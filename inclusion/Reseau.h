#pragma once
#include <string>
#include <vector>
#include <SFML/Network.hpp>

class Reseau
{
private:
	sf::IpAddress adresseIpServeur;
	std::vector<sf::IpAddress> adressesIpClient;

	void communiquerAuServeur();

public:
	Reseau(std::string& adresseIpServeur, std::vector<std::string>* adressesIpClient = nullptr);

	std::string getAdresseIpServeur() { return this->adresseIpServeur.toString(); }
	std::vector<std::string> getAdressesIpClient();

	//void setAdresseIpServeur(std::string& adresseIpServeur) { this->adresseIpServeur = adresseIpServeur; }
	void setAdresseIpClient(std::string& adresseIpClient);

	void demarrerReseau();
};
