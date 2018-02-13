#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../inclusion/VuePanneauUnite.h"

VuePanneauUnite::VuePanneauUnite(int longueurPanneau, int hauteurPanneau, int tailleCase, Unite* unite, std::string image) :
	VuePanneau(longueurPanneau, hauteurPanneau, tailleCase, image), unite(unite)
{
	this->fonte.loadFromFile("ressources/polices/LinuxLibertine-Classique.ttf");

	std::string stats = "Statistiques :\nAttaque : " + std::to_string(this->unite->getAttaque())
	+ "\nD�fense : " + std::to_string(this->unite->getDefense());
	this->titreStats = sf::Text(stats, this->fonte, 60);
	this->titreStats.setOutlineColor(sf::Color::Black);
	this->titreStats.setOutlineThickness(3.f);
	this->titreStats.setStyle(sf::Text::Bold);
	this->titreStats.setFillColor(sf::Color::White);
	this->titreStats.setScale(0.5f, 0.8f);
	this->titreStats.setPosition(tailleCase / 2, 10);

	this->titrePoints = sf::Text("Points forts / faibles :\n", this->fonte, 60);
	this->titrePoints.setOutlineColor(sf::Color::Black);
	this->titrePoints.setOutlineThickness(3.f);
	this->titrePoints.setStyle(sf::Text::Bold);
	this->titrePoints.setFillColor(sf::Color::White);
	this->titrePoints.setScale(0.5f, 0.8f);
	this->titrePoints.setPosition((tailleCase * 16) / 2, 10);

	std::string texteAttaques = "Attaques sp�ciales :\n";
	for(std::string attaque : this->unite->getListeAttaques())
	{
		texteAttaques = texteAttaques + attaque + "\n";
	}
	this->titreAttaques = sf::Text(texteAttaques, this->fonte, 60);
	this->titreAttaques.setOutlineColor(sf::Color::Black);
	this->titreAttaques.setOutlineThickness(3.f);
	this->titreAttaques.setStyle(sf::Text::Bold);
	this->titreAttaques.setFillColor(sf::Color::White);
	this->titreAttaques.setScale(0.5f, 0.8f);
	this->titreAttaques.setPosition((tailleCase * 31) / 2, 10);
}

void VuePanneauUnite::dessiner(sf::RenderTarget& cible)
{
	cible.draw(sprite);
	cible.draw(titreStats);
	cible.draw(titrePoints);
	cible.draw(titreAttaques);
}

void VuePanneauUnite::mettreAJourTexte()
{
	this->titreStats.setString("Statistiques :\nAttaque : " + std::to_string(this->unite->getAttaque())
		+ "\nD�fense : " + std::to_string(this->unite->getDefense()));
}