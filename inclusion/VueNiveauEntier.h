#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carte.h"

class VueNiveauEntier : public sf::View
{
private:
	Carte carte;

public:
	VueNiveauEntier(int longueurNiveau, int hauteurNiveau, int tailleCase, int niveau[]);
	Carte getCarte() { return carte; }
};
