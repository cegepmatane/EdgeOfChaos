#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../inclusion/VuePanneauUnite.h"
# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN64) || (_WIN32)
# include "../../systemes/interfaceWindows.h"
# endif

VuePanneauUnite::VuePanneauUnite(int longueurPanneau, int hauteurPanneau, int tailleCase, Unite* unite, std::string image) :
	VuePanneau(longueurPanneau, hauteurPanneau, tailleCase, image), unite(unite)
{
	this->fonte.loadFromFile(Configuration::cheminPolices + "LinuxLibertine-Classique.ttf");
	initialiser();
}

void VuePanneauUnite::initialiser()
{
	std::string stats = "Statistiques :\nAttaque : " + std::to_string(this->unite->getAttaque())
		+ "\nDéfense : " + std::to_string(this->unite->getDefense());
	this->titreStats = sf::Text(stats, this->fonte, 60);
	initTexte(this->titreStats);
	this->titreStats.setPosition(64 / 2, 10);

	this->titrePoints = sf::Text("Points forts / faibles :\n", this->fonte, 60);
	initTexte(this->titrePoints);
	this->titrePoints.setPosition((64 * 16) / 2, 10);

	std::string texteAttaques = "Attaques spéciales :\n";
	for (std::string attaque : this->unite->getListeAttaques())
	{
		texteAttaques = texteAttaques + attaque + "\n";
	}
	this->titreAttaques = sf::Text(texteAttaques, this->fonte, 60);
	initTexte(this->titreAttaques);
	this->titreAttaques.setPosition((64 * 31) / 2, 10);
}

void VuePanneauUnite::dessiner(sf::RenderTarget& cible)
{
	this->initialiser();
	cible.draw(sprite);
	cible.draw(titreStats);
	cible.draw(titrePoints);
	cible.draw(titreAttaques);
}

void VuePanneauUnite::mettreAJourTexte()
{
	this->titreStats.setString("Statistiques :\nAttaque : " + std::to_string(this->unite->getAttaque())
		+ "\nDéfense : " + std::to_string(this->unite->getDefense()));
}
