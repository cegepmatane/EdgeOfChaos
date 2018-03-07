#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <SFML/Network.hpp>
#include "../../inclusion/Reseau.h"

Reseau::Reseau(std::string& adresseIpServeur, std::vector<std::string>* adressesIpClient)
{
	this->adresseIpServeur = adresseIpServeur;
	if (adressesIpClient != nullptr)
	{
		for(sf::IpAddress adresseIpClient : *adressesIpClient)
		{
			// Inclure regex pour vérifier la structure de la chaine de caractères.
			this->adressesIpClient.push_back(adresseIpClient);
		}
	}
}

std::vector<std::string> Reseau::getAdressesIpClient()
{
	std::vector<std::string> adressesIp;
	for (sf::IpAddress adresseIpClient : this->adressesIpClient)
	{
		adressesIp.push_back(adresseIpClient.toString());
	}
	return adressesIp;
}

void Reseau::setAdresseIpClient(std::string& adresseIpClient)
{
	this->adressesIpClient.push_back(adresseIpClient);
}

void Reseau::communiquerAuClient()
{
	std::cout << "J'aimes les licornes!" << std::endl;
}

void Reseau::communiquerAuServeur()
{	
	std::cout << "Et moi les pommes!" << std::endl;
}

void Reseau::demarrerReseau()
{
	std::thread client(&Reseau::communiquerAuClient, this);
	client.join();
	std::thread serveur(&Reseau::communiquerAuServeur, this);
	serveur.join();
}


