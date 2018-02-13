#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Batiment.h"

Batiment::Batiment(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, std::string descriptionBatiment, std::vector<std::string> optionsBatiment)
	: Entite(nomEntite, pointDeVieEntite, positionLargeur, positionHauteur), description(descriptionBatiment), options(optionsBatiment)
{
	
}

