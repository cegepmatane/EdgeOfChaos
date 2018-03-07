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
		for(int i = 0; i < this->adressesIpClient.size(); ++i)
		{
			std::cout << this->adressesIpClient.at(i) << std::endl;
		}
	}
}

std::vector<std::string> Reseau::getAdressesIpClient()
{
	std::vector<std::string> adressesIpClient;
	for (sf::IpAddress adresseIpClient : this->adressesIpClient)
	{
		adressesIpClient.push_back(adresseIpClient.toString());
	}
	return adressesIpClient;
}

void Reseau::setAdresseIpClient(std::string& adresseIpClient)
{
	this->adressesIpClient.push_back(adresseIpClient);
}

void Reseau::communiquerAuClient()
{
	
}

void Reseau::communiquerAuServeur()
{
	
}

void Reseau::demarrerReseau()
{
	//std::thread client(&Reseau::communiquerAuClient);
	//std::thread serveur(&Reseau::communiquerAuServeur);
}


