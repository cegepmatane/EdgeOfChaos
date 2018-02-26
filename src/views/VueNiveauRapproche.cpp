#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/VueNiveauRapproche.h"
#include "../../inclusion/TileMap.h"
# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

VueNiveauRapproche::VueNiveauRapproche(int longueurNiveau, int hauteurNiveau, int longueurGrille, int hauteurGrille, int tailleCase, int niveau[]) : sf::View(sf::FloatRect(0, 0, longueurGrille * tailleCase, hauteurGrille * tailleCase))
{
	compteurLongueur = 0;
	compteurHauteur = 0;
	
	// on crée la tilemap avec le niveau précédemment défini

	if (carte.load(Configuration::cheminTextures + "textures.png", sf::Vector2u(tailleCase, tailleCase), niveau, longueurNiveau, hauteurNiveau))
	{
		this->setViewport(sf::FloatRect(0, 0, 1, 0.75f));
	}
}

