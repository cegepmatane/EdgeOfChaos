#include <string>
#include <vector>
#include <thread>
#include <SFML/Network.hpp>
#include "../../inclusion/Reseau.h"

Reseau::Reseau(std::string& adresseIpServeur, std::string adresseIpClient)
{
	this->adresseIpServeur = adresseIpServeur;
}

Reseau::Reseau(std::string& adresseIpServeur, std::vector<std::string>* adressesIpClient)
{
	this->adresseIpServeur = adresseIpServeur;
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
	std::thread client(this->communiquerAuClient);
	std::thread serveur(this->communiquerAuServeur);
}


