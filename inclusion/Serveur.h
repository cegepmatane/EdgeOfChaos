#ifndef SERVEUR_H
#define SERVEUR_H

#include <string>
#include <vector>

#include <SFML/Network.hpp>

#include "Session.h"

class Serveur
{
private:
	std::vector<Session*> clients;
	sf::TcpListener* ecouteur;
	std::thread* serveur;
	bool avorteFil;

	void executer();
	inline void initialiserEcouteur(std::ofstream& log);
	void attendreFermetureServeur();

public:
	Serveur();

	void demarrer();
	void arreterConnexions();
	void arreter();

	~Serveur();
};

#endif
