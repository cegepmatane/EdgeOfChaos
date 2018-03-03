#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Batiment.h"

Batiment::Batiment(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur, std::vector<std::string> actionsBatiment):
	Entite(pointsDeVie, pointsDefense, positionLargeur, positionHauteur),
	actions(actionsBatiment),
	nom("Batiment"),
	description("Vous pouvez y former des unités à pied.")
{
	
}
