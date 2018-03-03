#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

# if defined (linux)
# include "../../systemes/interfaceDebian.h"
# elif (_WIN32)||(_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif
#include "../../inclusion/Entite.h"

Entite::Entite(std::string& nom, int pointsDeVie, int positionLargeur, int positionHauteur) :	nom(nom)
{
	this->image = Configuration::cheminTextures + "textures64.png";
	this->pointsDeVie = pointsDeVie;
	this->position = sf::Vector2f(positionLargeur, positionHauteur);
}
