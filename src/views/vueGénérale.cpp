#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/vueGénérale.h"
#include "../../inclusion/TileMap.h"

VueGénérale::VueGénérale(int longueur, int hauteur, int tailleCase, int niveau[]) : sf::View(sf::FloatRect(0, 0, longueur * tailleCase, hauteur * tailleCase))
{
	// on crée la tilemap avec le niveau précédemment défini

	carte.load("ressources/textures/textures.png", sf::Vector2u(tailleCase, tailleCase), niveau, longueur, hauteur);
}
