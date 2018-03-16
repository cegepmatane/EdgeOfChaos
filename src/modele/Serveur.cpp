#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <fstream>
#include <SFML/Network.hpp>
#include "../../inclusion/Serveur.h"

Serveur::Serveur()
{
	this->serveur = nullptr;
	this->avorteFil = false;
}

void Serveur::executer()
{
	std::ofstream log("logServeur.txt", std::ios::out | std::ios::trunc);
	if(log)
	{
		sf::TcpListener ecouteur;
		initialiserEcouteur(ecouteur, log);
		while(!this->avorteFil)
		{
			sf::TcpSocket* connexion = new sf::TcpSocket();
			if(ecouteur.accept(*connexion) != sf::Socket::Done)
			{
				log << "Problème lors de la connexion au client." << std::endl;
			}
			Session* client = new Session(connexion);
			this->clients.push_back(client);

			log << "Le serveur cherche des client potentiels... " << this << std::endl;
		}
		log << "Le serveur clôt la tâche..." << std::endl;
		log.close();
		// dockClient.disconnect(); // Déconnexion du client au serveur
	}
}

inline void Serveur::initialiserEcouteur(sf::TcpListener& ecouteur, std::ofstream& log)
{
	while(ecouteur.listen(5001) != sf::Socket::Done)
	{
		log << "Problème lors de la mise à l'écoute du port." << std::endl;
	}
}

void Serveur::demarrer()
{
	if(this->serveur == nullptr)
	{
		this->serveur = new std::thread(&Serveur::executer, this);
	}
}

void Serveur::arreter()
{
	this->avorteFil = true;
}

void Serveur::attendreFermetureServeur()
{
	if(this->serveur->joinable())
	{
		this->serveur->join();
	}
}

Serveur::~Serveur()
{
	if(this->serveur != nullptr)
	{
		this->arreter();
		this->attendreFermetureServeur();
		delete this->serveur;
		this->serveur = nullptr;

		for(int i = 0; i < this->clients.size(); ++i)
		{
			delete this->clients.at(i);
			this->clients.at(i) = nullptr;
		}
	}
}
