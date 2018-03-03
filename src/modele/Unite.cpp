#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../../inclusion/Entite.h"
#include "../../inclusion/Unite.h"

Unite::Unite(int pointsDeVie, int positionLargeur, int positionHauteur, int attaque, int defense, std::vector<std::string> attaques) :
	Entite(pointsDeVie, defense, positionLargeur, positionHauteur), attaque(attaque),
	listeAttaques(attaques),
	nom("Unité")
{
	
}
