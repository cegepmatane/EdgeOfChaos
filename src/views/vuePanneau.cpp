#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/vuePanneau.h"

VuePanneau::VuePanneau(int longueurPanneau, int hauteurPanneau, int tailleCase, sf::Texture texturePanneau) : sf::View(sf::FloatRect(0, 0, tailleCase, tailleCase)),
	longueur(longueurPanneau), hauteur(hauteurPanneau), texture(texturePanneau)
{
	//texture.setRepeated(true);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, tailleCase * 9));
	
	this->setViewport(sf::FloatRect(0, 0.75f, 1, 0.25f));
}