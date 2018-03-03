#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/VueNiveauRapproche.h"
#include "../../inclusion/Carte.h"
# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

VueNiveauRapproche::VueNiveauRapproche(Niveau niveau, Carte* carte, int longueurGrille, int hauteurGrille, int tailleCase) : sf::View(sf::FloatRect(0, 0, longueurGrille * tailleCase, hauteurGrille * tailleCase))
{
	compteurLongueur = 0;
	compteurHauteur = 0;

	this->carte = carte;
	this->setViewport(sf::FloatRect(0, 0, 1, 0.75f));
}

