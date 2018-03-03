#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

# if defined (linux)
# include "../../systemes/interfaceDebian.h"
# elif (_WIN32)||(_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif
#include "../../inclusion/Entite.h"

Entite::Entite(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur) :
	image(Configuration::cheminTextures + "textures64.png")
{
	this->pointsDeVie = pointsDeVie;
	this->pointsDefense = pointsDefense;
	this->position = std::vector<int>(positionLargeur, positionHauteur);
}
