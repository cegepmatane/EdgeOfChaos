#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"

class Batiment: public Entite
{
private:
	std::string description;
	std::vector<std::string> options;

public:
	Batiment(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, std::string descriptionBatiment, std::vector<std::string> optionsBatiment);

	std::string getDescription() { return description; }
	std::vector<std::string> getOptions() { return options; }
};