#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../../inclusion/Entite.h"
#include "../../inclusion/Unite.h"

Unite::Unite(int pointsDeVie, int pointsDefense, int pointsAttaque, int positionLargeur, int positionHauteur, int numTexture, std::vector<std::string> attaques) :
	Entite(pointsDeVie, pointsDefense, positionLargeur, positionHauteur, numTexture),
	attaque(pointsAttaque),
	listeAttaques(attaques),
	nom("Unite")
{
	
}
