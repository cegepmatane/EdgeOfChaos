#include <thread>
#include <iostream>
#include <string>
#include <fstream>

#include <SFML/Network.hpp>

#include "../../inclusion/Session.h"

Session::Session(sf::TcpSocket* socket) throw(std::string&)
try
{
	this->communication  = nullptr;
	this->deconnexion = false;
	if(socket != nullptr)
	{
		this->socket = socket;
	}
	else
	{
		throw std::string ("The socket parameter must be initialized");
	}
}
catch(const std::string& err)
{
	//std::cerr << "ERROR :\t\"" << err << "\" in a \"Session\" constructor." << std::endl;
}

void Session::connecterClient()
{
	if(this->communication == nullptr)
	{
		this->communication = new std::thread(&Session::executerSession, this);
	}
}

void Session::executerSession()
{
	while(!this->deconnexion)
	{
		std::cout << "Dear William\nI can't give a fuck in your section.\nSO WORK!" << std::endl;
	}
}

void Session::deconnecterClient()
{
	this->deconnexion = true;
}

void Session::attendreFermetureSession()
{
	if(this->communication->joinable())
	{
		this->communication->join();
	}
}

Session::~Session()
{
	this->deconnexion = true;
	if(this->communication != nullptr)
	{
		this->attendreFermetureSession();
		delete this->communication;
		this->communication = nullptr;
	}
	this->socket = nullptr;
}
