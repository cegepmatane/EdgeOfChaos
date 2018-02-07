#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/vueG�n�rale.h"
#include "../../inclusion/TileMap.h"

VueG�n�rale::VueG�n�rale(int longueur, int hauteur, int tailleCase, int niveau[]) : sf::View(sf::FloatRect(0, 0, longueur * tailleCase, hauteur * tailleCase))
{
	// on cr�e la tilemap avec le niveau pr�c�demment d�fini

	carte.load("ressources/textures/textures.png", sf::Vector2u(tailleCase, tailleCase), niveau, longueur, hauteur);
}
