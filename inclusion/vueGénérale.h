#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueG�n�rale : public sf::View
{
private:
	TileMap carte;

public:
	VueG�n�rale(int longueur, int hauteur, int tailleCase, int niveau[]);
};
