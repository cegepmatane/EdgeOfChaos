#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/vuePanneau.h"

VuePanneau::VuePanneau(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image) : sf::View(sf::FloatRect(0, 0, tailleCase*20, tailleCase*20)),
	longueur(longueurPanneau), hauteur(hauteurPanneau)
{
	texture.loadFromFile(image);
	sprite.setTexture(texture);
	this->setViewport(sf::FloatRect(0, 0.75f, 1, 1));
}

void VuePanneau::initTexte(sf::Text &texte)
{
	texte.setOutlineColor(sf::Color::Black);
	texte.setOutlineThickness(3.f);
	texte.setStyle(sf::Text::Bold);
	texte.setFillColor(sf::Color::White);
	texte.setScale(0.5f, 0.8f);
}
