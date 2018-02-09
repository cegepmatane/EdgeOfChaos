#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Unite.h"

Unite::Unite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, int attaqueUnite, int defenseUnite) :
Entite(nomEntite, pointDeVieEntite, positionLargeur, positionHauteur), attaque(attaqueUnite), defense(defenseUnite)
{
	
}