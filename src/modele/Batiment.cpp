#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Batiment.h"

Batiment::Batiment(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur, int numTexture, std::vector<std::string> actionsBatiment):
	Entite(pointsDeVie, pointsDefense, positionLargeur, positionHauteur, numTexture),
	actions(actionsBatiment),
	nom("Batiment"),
	description("Vous pouvez y former des unites terrestres.")
{
	
}
