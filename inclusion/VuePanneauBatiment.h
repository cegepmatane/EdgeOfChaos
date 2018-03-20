#pragma once
#include <SFML/Graphics.hpp>
#include "VuePanneau.h"
#include "Batiment.h"

class VuePanneauBatiment : public VuePanneau
{
private:
	Batiment* batiment;
	sf::Font fonte;

	sf::Text descriptionBatiment;
	sf::Text optionsBatiment;	

public:
	VuePanneauBatiment(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Batiment* batiment);
	void initialiser();
	void dessiner(sf::RenderWindow &fenetre);

	void setBatiment(Batiment* batiment) { this->batiment = batiment; }

	sf::Text getDescriptionBatiment() { return descriptionBatiment; }
	sf::Text getOptionsBatiment() { return optionsBatiment; }
	void mettreAJourTexte(Batiment* batiment);
};
