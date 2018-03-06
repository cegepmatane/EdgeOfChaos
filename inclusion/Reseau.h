#pragma once
#include <string>
#include <SFML/Network.hpp>

class Reseau
{
private:
	sf::IpAddress adresseIpServeur;
	sf::IpAddress adresseIpClient;

public:
	Reseau(std::string adresseIpServeur, std::string adresseIpClient);
	~Reseau();

	sf::IpAddress getAdresseIpServeur() { return this->adresseIpServeur; }
	sf::IpAddress getAdresseIpClient() { return this->adresseIpClient; }

	void setAdresseIpServeur(sf::IpAddress adresseIpServeur) { this->adresseIpClient = adresseIpServeur; }
	void setAdresseIpClient(sf::IpAddress adresseIpClient) { this->adresseIpClient = adresseIpClient; }
};