#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/vueNiveauEntier.h"
#include "../../inclusion/TileMap.h"

#include "../../systemes/interfaceWindows.h"

VueNiveauEntier::VueNiveauEntier(int longueurNiveau, int hauteurNiveau, int tailleCase, int niveau[]) : sf::View(sf::FloatRect(0, 0, longueurNiveau * tailleCase, hauteurNiveau * tailleCase))
{
	// on crée la tilemap avec le niveau précédemment défini

	carte.load(Configuration::cheminTextures + "textures.png", sf::Vector2u(tailleCase, tailleCase), niveau, longueurNiveau, hauteurNiveau);
}
