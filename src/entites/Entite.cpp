#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"

Entite::Entite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur) : sf::Sprite(),
	nom(nomEntite), pointDeVie(pointDeVieEntite)
{
	this->vraiePosition = sf::Vector2f(positionLargeur, positionHauteur);
	this->setPosition(sf::Vector2f(positionLargeur, positionHauteur));
}

void Entite::setImage(std::string image, int numTexture)
{
	this->numTexture = numTexture;
	texture.loadFromFile(image, sf::IntRect(64*numTexture, 0, 64, 64));
	this->setTexture(texture);
}
