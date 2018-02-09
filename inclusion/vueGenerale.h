#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueGenerale : public sf::View
{
private:
	TileMap carte;

public:
	VueGenerale(int longueur, int hauteur, int tailleCase, int niveau[]);
};
