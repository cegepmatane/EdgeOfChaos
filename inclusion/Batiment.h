#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Entite.h"

class Batiment: public Entite
{
private:
	std::string nom; // temporaire
	std::string description;
	std::vector<std::string> options;

public:
	std::string getNom() { return nom; }
	Batiment(int pointsDeVie, int positionLargeur, int positionHauteur, std::vector<std::string> optionsBatiment);

	std::string getDescription() { return description; }
	std::vector<std::string> getOptions() { return options; }
};
