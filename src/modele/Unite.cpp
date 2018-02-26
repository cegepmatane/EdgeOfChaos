#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "../../inclusion/Unite.h"

Unite::Unite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, int attaqueUnite, int defenseUnite, std::vector<std::string> attaques) :
Entite(nomEntite, pointDeVieEntite, positionLargeur, positionHauteur), attaque(attaqueUnite), defense(defenseUnite), listeAttaques(attaques)
{
	
}