#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Unite.h"

Unite::Unite(std::string nomEntite, int pointDeVieEntite, sf::Vector2u positionEntite, int attaqueUnite, int defenseUnite) : 
Entite(nomEntite, pointDeVieEntite, positionEntite), attaque(attaqueUnite), defense(defenseUnite)
{
	
}