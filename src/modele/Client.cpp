#include <thread>
#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Network.hpp>

#include "../../inclusion/Client.h"


Client::Client() :
	communication(&Client::communiquerAuClient, this)
{
	this->communication.join();
}

void Client::communiquerAuClient()
{
	printf("Dear Willi\n");
	// Pour Willi
}
