#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "../../inclusion/bouton.h"

Bouton::Bouton(int hauteur, int longueur, std::string& texte, sf::Font& police) : RectangleShape(sf::Vector2f(hauteur - sf::VideoMode::getDesktopMode().width / 426 * 2, longueur - sf::VideoMode::getDesktopMode().width / 426 * 2))
{
	this->bordure = sf::VideoMode::getDesktopMode().width / 426;
	
	this->setFillColor(sf::Color::White);
	this->setOutlineThickness(this->bordure);
	this->setOutlineColor(sf::Color::Black);
	this->setPosition(this->bordure, this->bordure);
	
	this->contenu.setFont(police);
	this->contenu.setString(texte);

	this->contenu.setCharacterSize(this->getSize().y - this->getSize().y / 6);
	this->contenu.setFillColor(sf::Color::Black);
	this->contenu.setPosition(this->bordure, 0);
}

void Bouton::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw((RectangleShape)(*this));	// Caster, sinon, affichage récursif de tous les composant de l'instance de la classe.
	target.draw(this->contenu);
}

void Bouton::setBtnPosition(float x, float y)
{
	x += this->bordure;
	y += this->bordure;
	this->setPosition(x, y);
	this->contenu.setPosition(x, y);
}
