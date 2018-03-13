#ifndef CLIENT_H
#define CLIENT_H

#include <thread>
#include <string>

#include <SFML/Network.hpp>

class Session
{
	private:
		sf::TcpSocket* socket;
		std::thread* communication;
		bool deconnexion;

		void executerSession();
		void attendreFermetureSession();

	public:
		Session(sf::TcpSocket* socket)throw(std::string&);
		void connecterClient();
		void deconnecterClient();
		~Session();
};

#endif
