#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Batiment.h"

Batiment::Batiment(std::string nomEntite, int pointDeVieEntite, sf::Vector2u positionEntite, std::string descriptionBatiment, std::vector<std::string> optionsBatiment)
	: Entite(nomEntite, pointDeVieEntite, positionEntite), description(descriptionBatiment), options(optionsBatiment)
{
	
}

