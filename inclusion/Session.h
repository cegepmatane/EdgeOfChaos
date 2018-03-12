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
		bool deconnexion;

	public:
		Session();
		void communiquerAuClient();
		void deconnecterClient();
		~Session();
};

#endif
