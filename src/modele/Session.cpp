#include <thread>
#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Network.hpp>

#include "../../inclusion/Session.h"

Session::Session() :
	communication(&Session::communiquerAuClient, this)
{
	this->communication.join();
}

void Session::communiquerAuClient()
{
	printf("Dear Willi\n");
	// Pour Willi
}
