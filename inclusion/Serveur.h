#ifndef SERVEUR_H
#define SERVEUR_H

#include <string>
#include <vector>
#include <SFML/Network.hpp>

class Serveur
{
private:
	sf::IpAddress adresseIpServeur;
	std::vector<sf::IpAddress> adressesIpClient;
	std::thread* serveur;
	bool avorteServeur;

	void executer();

public:
	Serveur(std::string& adresseIpServeur);
	//Serveur(std::string& adresseIpServeur, std::vector<std::string>& adressesIpClient);

	std::string getAdresseIpServeur() { return this->adresseIpServeur.toString(); }
	std::vector<std::string> getAdressesIpClient();

	//void setAdresseIpServeur(std::string& adresseIpServeur) { this->adresseIpServeur = adresseIpServeur; }
	//void setAdresseIpClient(std::string& adresseIpClient);

	void demarrerServeur();
	void arreterServeur();
	void attendreFermetureServeur();

	~Serveur();
};

#endif
