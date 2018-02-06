#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"

Entite::Entite(std::string nom, int pdv, sf::Vector2u position) : nom(nom), pointDeVie(pdv), position(position)
{
	
}