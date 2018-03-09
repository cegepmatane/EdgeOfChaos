#ifndef CLIENT_H
#define CLIENT_H

#include <thread>
#include <string>

#include <SFML/Network.hpp>

class Client
{
	private:
		sf::TcpSocket socket;
		std::thread communication;
		std::string exemple;

	public:
		void communiquerAuClient();
		Client();
};

#endif
