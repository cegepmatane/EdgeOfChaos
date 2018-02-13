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
	initTexte(descriptionBatiment);
	descriptionBatiment.setPosition(64 / 2, 50);

	std::string texteOptions = "Options :\n";
	for (std::string option : this->batimentSprite->getOptions())
	{
		texteOptions = texteOptions + option + "\n";
	}
	optionsBatiment = sf::Text(texteOptions, fonte, 60);
	initTexte(optionsBatiment);
	optionsBatiment.setPosition(64 * 16 /2, 50);
}

void VuePanneauBatiment::draw(sf::RenderWindow &fenetre)
{
	fenetre.draw(sprite);
	fenetre.draw(descriptionBatiment);
	fenetre.draw(optionsBatiment);
}
