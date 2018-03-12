#include <thread>
#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Network.hpp>

#include "../../inclusion/Session.h"

Session::Session() :
	communication(&Session::communiquerAuClient, this)
{
	this->deconnexion = false;
}

void Session::communiquerAuClient()
{
	while(!this->deconnexion)
	{
		printf("Dear Willi\n");
	}
}

void Session::deconnecterClient()
{
	this->deconnexion = true;
}

Session::~Session()
{
	this->deconnexion = true;
	this->communication.join();
}
