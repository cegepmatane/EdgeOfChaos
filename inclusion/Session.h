#ifndef CLIENT_H
#define CLIENT_H

#include <thread>
#include <string>

#include <SFML/Network.hpp>

class Session
{
	private:
		sf::TcpSocket socket;
		std::thread communication;

	public:
		void communiquerAuClient();
		Client();
};

#endif
