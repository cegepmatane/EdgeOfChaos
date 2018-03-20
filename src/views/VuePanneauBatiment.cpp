#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../inclusion/VuePanneauBatiment.h"
# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

VuePanneauBatiment::VuePanneauBatiment(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Batiment* batiment) :
	VuePanneau(longueurPanneau, hauteurPanneau, tailleCase, image), batiment(batiment)
{
	if (!this->fonte.loadFromFile(Configuration::cheminPolices + "LinuxLibertine-Classique.ttf"))
		std::cerr << "Impossible de charger la police du panneau batiment. \n ( " << Configuration::cheminPolices + "LinuxLibertine-Classique.ttf" << " )" << std::endl;
	initialiser();
}

void VuePanneauBatiment::initialiser()
{
	descriptionBatiment = sf::Text(batiment->getNom() + "\nDescription :\n" + batiment->getDescription(), fonte, 60);
	initTexte(descriptionBatiment);
	descriptionBatiment.setPosition(64 / 2, 10);

	std::string texteOptions = "Options :\n";
	for (std::string option : this->batiment->getActions())
	{
		texteOptions = texteOptions + option + "\n";
	}
	optionsBatiment = sf::Text(texteOptions, fonte, 60);
	initTexte(optionsBatiment);
	optionsBatiment.setPosition((64 * 20) /2, 10);
}

void VuePanneauBatiment::dessiner(sf::RenderWindow &fenetre)
{
	fenetre.draw(sprite);
	fenetre.draw(descriptionBatiment);
	fenetre.draw(optionsBatiment);
}

void VuePanneauBatiment::mettreAJourTexte(Batiment* batiment)
{
	this->descriptionBatiment.setString(batiment->getNom() + "\nDescription :\n" + batiment->getDescription());
	std::string texteOptions = "Options :\n";
	for (std::string option : batiment->getActions())
	{
		texteOptions = texteOptions + option + "\n";
	}
	this->optionsBatiment.setString(texteOptions);
}
