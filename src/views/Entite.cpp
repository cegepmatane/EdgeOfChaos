#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"

Entite::Entite(std::string nomEntite, int pointDeVieEntite, sf::Vector2u positionEntite) : 
	nom(nomEntite), pointDeVie(pointDeVieEntite), position(positionEntite)
{
	
}

void Entite::setTexture(std::string image, int numTexture)
{
	texture.loadFromFile(image, sf::IntRect(64*numTexture, 0, 64, 64));
}
