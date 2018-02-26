#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"
#include <iostream>

# if defined (linux)
# include "../../systemes/interfaceDebian.h"
# elif (_WIN32)||(_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

Entite::Entite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur) : sf::Sprite(),
	nom(nomEntite), pointDeVie(pointDeVieEntite)
{
	this->vraiePosition = sf::Vector2f(positionLargeur, positionHauteur);
	this->setPosition(sf::Vector2f(positionLargeur, positionHauteur));
}

void Entite::setImage(std::string image, int numTexture)
{
	this->numTexture = numTexture;
	if (!texture.loadFromFile(image, sf::IntRect(64*numTexture, 0, 64, 64)))
		std::cerr << "Impossible de charger la texture de l'entite. \n ( " << image << " )" << std::endl;
	this->setTexture(texture);
}
