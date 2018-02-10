#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../inclusion/VuePanneauUnite.h"

VuePanneauUnite::VuePanneauUnite(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Unite unite) :
	VuePanneau(longueurPanneau, hauteurPanneau, tailleCase, image), uniteSprite(unite)
{

}