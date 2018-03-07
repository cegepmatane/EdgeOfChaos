#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

# if defined (linux)
# include "../../systemes/interfaceDebian.h"
# elif (_WIN32)||(_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif
#include "../../inclusion/Entite.h"

Entite::Entite(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur, int numTexture) :
	image(Configuration::cheminTextures + "textures64.png")
{
	this->pointsDeVie = pointsDeVie;
	this->pointsDefense = pointsDefense;
	this->position = std::vector<int>(positionLargeur, positionHauteur);

	this->numTexture = numTexture;
}

void Entite::setPosition(int x, int y)
{
	std::vector<int> nouvellePosition;
	nouvellePosition.push_back(x);
	nouvellePosition.push_back(y);
	position = nouvellePosition;
}

sf::Packet& operator<<(sf::Packet& paquet, const Entite& e)
{
	return paquet << e.getVie() << e.getDefense() << e.getPosition().at(0) << e.getPosition().at(1) << e.getImage() << e.getNumTexture();
}

sf::Packet& operator>>(sf::Packet& paquet, Entite& e)
{
	int pointsDeVie, pointsDeDefense, x, y, numTexture;
	std::string image;
	paquet >> pointsDeVie >> pointsDeDefense >> x >> y >> image >> numTexture;
	e.setVie(pointsDeVie);
	e.setDefense(pointsDeDefense);
	e.setPosition(x, y);
	return paquet >> pointsDeVie >> pointsDeDefense >> x >> y >> image >> numTexture;
}
