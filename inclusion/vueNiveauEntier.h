#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueNiveauEntier : public sf::View
{
private:
	TileMap carte;

public:
	VueNiveauEntier(int longueurNiveau, int hauteurNiveau, int tailleCase, int niveau[]);
	TileMap getCarte() { return carte; }
};
