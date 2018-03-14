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
		while(!this->avorteFil)
		{
			log << "Le serveur cherche des client potentiels... " << this << std::endl;
		}
		log << "Le serveur clôt la tâche..." << std::endl;
		log.close();
		// dockClient.disconnect(); // Déconnexion du client au serveur
	}
}

void Serveur::demarrerServeur()
{
	if(this->serveur == nullptr)
	{
		this->serveur = new std::thread(&Serveur::executer, this);
	}
}

void Serveur::arreterServeur()
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
		this->arreterServeur();
		this->attendreFermetureServeur();
		delete this->serveur;
		this->serveur = nullptr;
	}
}
