#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <fstream>
#include <SFML/Network.hpp>
#include "../../inclusion/Serveur.h"

Serveur::Serveur(std::string& adresseIpServeur)
{
	this->serveur = nullptr;
	this->adresseIpServeur = adresseIpServeur;
	this->avorteServeur = false;
}

/*Serveur::Serveur(std::string& adresseIpServeur, std::vector<std::string>& adressesIpClient)
{
	this->serveur = nullptr;
	this->adresseIpServeur = adresseIpServeur;
	this->avorteServeur = false;
	if (!adressesIpClient.empty())
	{
		for(sf::IpAddress adresseIpClient : adressesIpClient)
		{
			// Inclure regex pour vérifier la structure de la chaine de caractères.
			this->adressesIpClient.push_back(adresseIpClient);
		}
	}
}*/

std::vector<std::string> Serveur::getAdressesIpClient()
{
	std::vector<std::string> adressesIp;
	for (sf::IpAddress adresseIpClient : this->adressesIpClient)
	{
		adressesIp.push_back(adresseIpClient.toString());
	}
	return adressesIp;
}

void Serveur::executer()
{
	std::ofstream log("logServeur.txt", std::ios::out | std::ios::trunc);
	if(log)
	{
		log << this->avorteServeur << std::endl;
		while(!this->avorteServeur)
		{
			log << "Le serveur cherche des client potentiels... " << this << std::endl;
		}
		log << "Le serveur se ferme..." << std::endl;
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
	this->avorteServeur = true;
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
		this->attendreFermetureServeur();
		delete this->serveur;
		this->serveur = nullptr;
	}
}
