#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Entite.h"

class Batiment: public Entite
{
private:
	std::string nom; // temporaire
	std::string description;
	std::vector<std::string> actions;

public:
	std::string getNom() { return nom; }
	Batiment(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur, std::vector<std::string> actionsBatiment);

	std::string getDescription() { return description; }
	std::vector<std::string> getActions() { return actions; }
};
