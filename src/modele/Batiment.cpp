#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Batiment.h"

Batiment::Batiment(int pointsDeVie, int positionLargeur, int positionHauteur, std::vector<std::string> optionsBatiment):
	Entite(pointsDeVie, positionLargeur, positionHauteur),
	options(optionsBatiment),
	nom("Batiment"),
	description("Vous pouvez y former des unités à pied.")
{
	
}
