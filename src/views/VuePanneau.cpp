#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/VuePanneau.h"
#include <iostream>

# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

VuePanneau::VuePanneau(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image) : sf::View(sf::FloatRect(0, 0, tailleCase*20, tailleCase*20)),
	longueur(longueurPanneau), hauteur(hauteurPanneau)
{
	if (!texture.loadFromFile(image))
		std::cerr << "Impossible de charger la texture du panneau. \n ( " << Configuration::cheminTextures + image << " )" << std::endl;
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
