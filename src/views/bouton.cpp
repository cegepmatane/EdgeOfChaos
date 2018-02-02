#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "bouton.h"

Bouton::Bouton(int hauteur, int longueur, std::string texte, sf::Font police) : RectangleShape(sf::Vector2f(hauteur - sf::VideoMode::getDesktopMode().width / 213, longueur - sf::VideoMode::getDesktopMode().width / 213))
{
	this->setFillColor(sf::Color::White);
	this->bordure = sf::VideoMode::getDesktopMode().width / 213;
	this->contenu.setString(texte);
	this->contenu.setFont(police);
	this->contenu.setFillColor(sf::Color::Black);
	this->contenu.setCharacterSize(this->getSize().x - this->getSize().x / 4);
	this->contenu.setPosition(this->getPosition().x + this->getPosition().x / 4 / 2, this->getPosition().x + this->getPosition().x / 4 / 2);

}
