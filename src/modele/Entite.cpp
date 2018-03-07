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

sf::Packet& Entite::operator<<(sf::Packet& paquet)
{
	return paquet << this->pointsDeVie << this->pointsDefense << this->position.at(0) << this->position.at(1) << this->image << this->numTexture;
}

sf::Packet& Entite::operator>>(sf::Packet& paquet)
{
	return paquet >> this->pointsDeVie >> this->pointsDefense >> this->position.at(0) >> this->position.at(1) >> this->image >> this->numTexture;
}
