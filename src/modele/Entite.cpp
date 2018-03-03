#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"
#include <iostream>

# if defined (linux)
# include "../../systemes/interfaceDebian.h"
# elif (_WIN32)||(_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

Entite::Entite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur) :	nom(nomEntite), pointDeVie(pointDeVieEntite)
{
	this->position = sf::Vector2f(positionLargeur, positionHauteur);
}
