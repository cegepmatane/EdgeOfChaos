#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <SFML/Network.hpp>
#include "../../inclusion/Serveur.h"

Serveur::Serveur(std::string& adresseIpServeur, std::vector<std::string>* adressesIpClient)
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

std::vector<std::string> Serveur::getAdressesIpClient()
{
	std::vector<std::string> adressesIp;
	for (sf::IpAddress adresseIpClient : this->adressesIpClient)
	{
		adressesIp.push_back(adresseIpClient.toString());
	}
	return adressesIp;
}

void Serveur::setAdresseIpClient(std::string& adresseIpClient)
{
	this->adressesIpClient.push_back(adresseIpClient);
}

void Serveur::executer()
{	
	/*std::cout << "Client" << std::endl;

	sf::TcpSocket dockClient;
	int portServeur = 50000;
	sf::Socket::Status statut = dockClient.connect(this->adresseIpServeur, portServeur); // adresse et port auquel se connecte le client.

	if (statut != sf::Socket::Done)	// Si la connexion n'est pas établie
	{
		std::cerr << "Connexion au serveur impossible" << std::endl;
	}

	char donneeRecue; // Caractère reçu
	std::size_t tailleRecue; // Taille en octet du message reçu.
	if (dockClient.receive(&donneeRecue, 1, tailleRecue) != sf::Socket::Done) // Si le message n'est pas reçu
	{
		std::cerr << "Réception impossible" << std::endl;
	}
	std::cout << "L'objet reçu est d'une taille de " << tailleRecue << " octet(s), il s'agit de " << donneeRecue << "." << std::endl;
	dockClient.disconnect(); // Déconnexion du client au serveur*/
}

void Serveur::demarrerServeur()
{
	std::thread serveur(&Serveur::executer, this);
	client.join();
}


