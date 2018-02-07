#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueGénérale : public sf::View
{
private:
	TileMap carte;

public:
	VueGénérale(int longueur, int hauteur, int tailleCase, int niveau[]);
};
