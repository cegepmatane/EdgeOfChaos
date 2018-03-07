#include "SFML/Network.hpp"
#include "../../inclusion/PaquetEntite.h"

sf::Packet& PaquetEntite::operator<<(Entite entite)
{
	int pointsDeVie = entite.getVie();
	int pointsDefense = entite.getDefense();
	int x = entite.getPosition().at(0);
	int y = entite.getPosition().at(1);
	int numTexture = entite.getNumTexture();
	std::string image = entite.getImage();
	Packet paquet = static_cast<Packet>(*this);
	return paquet << pointsDeVie << pointsDefense << x << y << image << numTexture;
}

sf::Packet& PaquetEntite::operator>>(Entite entite)
{
	int pointsDeVie = entite.getVie();
	int pointsDefense = entite.getDefense();
	int x = entite.getPosition().at(0);
	int y = entite.getPosition().at(1);
	int numTexture = entite.getNumTexture();
	std::string image = entite.getImage();
	Packet paquet = static_cast<Packet>(*this);
	return paquet >> pointsDeVie >> pointsDefense >> x >> y >> image >> numTexture;
}
