#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Entite.h"

class Batiment: public Entite
{
private:
	std::string description;
	std::string options;

public:
	Batiment(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, std::string descriptionBatiment, std::string optionsBatiment);

	std::string getDescription() { return description; }
	std::string getOptions() { return options; }
};