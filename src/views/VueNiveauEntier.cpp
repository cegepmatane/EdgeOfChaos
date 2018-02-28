#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/VueNiveauEntier.h"
#include "../../inclusion/TileMap.h"
# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

VueNiveauEntier::VueNiveauEntier(int longueurNiveau, int hauteurNiveau, int tailleCase, int niveau[]) : sf::View(sf::FloatRect(0, 0, longueurNiveau * tailleCase, hauteurNiveau * tailleCase))
{
	// on crée la tilemap avec le niveau précédemment défini

	carte.load(Configuration::cheminTextures + "textures64.png", sf::Vector2u(tailleCase, tailleCase), niveau, longueurNiveau, hauteurNiveau);
}
