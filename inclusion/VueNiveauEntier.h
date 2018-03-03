#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carte.h"
#include "Niveau.h"

class VueNiveauEntier : public sf::View
{
private:
	Carte* carte;

public:
	VueNiveauEntier(Niveau niveau, Carte* carte, int tailleCase);
	Carte* getCarte() { return carte; }
};
