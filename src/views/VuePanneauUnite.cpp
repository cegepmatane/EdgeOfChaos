#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../inclusion/VuePanneauUnite.h"

VuePanneauUnite::VuePanneauUnite(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Unite unite) :
	VuePanneau(longueurPanneau, hauteurPanneau, tailleCase, image), uniteSprite(unite)
{
	this->fonte.loadFromFile("ressources/polices/LinuxLibertine-Classique.ttf");

	statTexte = sf::Text("Statistiques : ", fonte, 60);
	statTexte.setOutlineColor(sf::Color::Black);
	statTexte.setOutlineThickness(3.f);
	statTexte.setStyle(sf::Text::Bold);
	statTexte.setFillColor(sf::Color::White);
	statTexte.setScale(0.5f, 0.8f);
	statTexte.setPosition(64 / 2, 10);
}