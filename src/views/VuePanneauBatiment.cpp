#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../inclusion/VuePanneauBatiment.h"

VuePanneauBatiment::VuePanneauBatiment(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Batiment* batiment) :
	VuePanneau(longueurPanneau, hauteurPanneau, tailleCase, image), batimentSprite(batiment)
{
	this->fonte.loadFromFile("ressources/polices/LinuxLibertine-Classique.ttf");
}

void VuePanneauBatiment::init()
{
	descriptionBatiment = sf::Text(batimentSprite->getNom() + "\nDescription :\n" + batimentSprite->getDescription(), fonte, 60);
	descriptionBatiment.setOutlineColor(sf::Color::Black);
	descriptionBatiment.setOutlineThickness(3.f);
	descriptionBatiment.setStyle(sf::Text::Bold);
	descriptionBatiment.setFillColor(sf::Color::White);
	descriptionBatiment.setScale(0.5f, 0.8f);
	descriptionBatiment.setPosition(64 / 2, 50);

	optionsBatiment = sf::Text("Options :\n" + batimentSprite->getOptions(), fonte, 60);
	optionsBatiment.setOutlineColor(sf::Color::Black);
	optionsBatiment.setOutlineThickness(3.f);
	optionsBatiment.setStyle(sf::Text::Bold);
	optionsBatiment.setFillColor(sf::Color::White);
	optionsBatiment.setScale(0.5f, 0.8f);
	optionsBatiment.setPosition(64 * 16 /2, 50);
}

void VuePanneauBatiment::draw(sf::RenderWindow &fenetre)
{
	fenetre.draw(sprite);
	fenetre.draw(descriptionBatiment);
	fenetre.draw(optionsBatiment);
}
