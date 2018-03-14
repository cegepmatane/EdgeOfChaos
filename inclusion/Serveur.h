#ifndef SERVEUR_H
#define SERVEUR_H

#include <string>
#include <vector>

#include <SFML/Network.hpp>

#include "Session.h"

class Serveur
{
private:
	std::vector<Session> clients;
	std::thread* serveur;
	bool avorteFil;

	void executer();
	void attendreFermetureServeur();

public:
	Serveur();

	void demarrerServeur();
	void arreterServeur();

	~Serveur();
};

#endif
