#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/vuePanneau.h"

VuePanneau::VuePanneau(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image) : sf::View(sf::FloatRect(0, 0, tailleCase, tailleCase)),
	longueur(longueurPanneau), hauteur(hauteurPanneau)
{
	texture.loadFromFile(image);
	sprite.setTexture(texture);
	this->setViewport(sf::FloatRect(0, 0.75f, 1, 0.25f)); 
}