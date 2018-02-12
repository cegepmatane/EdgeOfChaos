#pragma once
#include <SFML/Graphics.hpp>
#include "vuePanneau.h"
#include "Batiment.h"

class VuePanneauBatiment : public VuePanneau
{
private:
	Batiment* batimentSprite;
	sf::Font fonte;

	sf::Text descriptionBatiment;
	sf::Text optionsBatiment;	

public:
	VuePanneauBatiment(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Batiment* batiment);
	void init();
	void draw(sf::RenderWindow &fenetre);

	sf::Text getDescriptionBatiment() { return descriptionBatiment; }
	sf::Text getOptionsBatiment() { return optionsBatiment; }
};