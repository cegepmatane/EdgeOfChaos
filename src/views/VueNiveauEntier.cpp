#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/VueNiveauEntier.h"
#include "../../inclusion/Carte.h"
# if defined (__linux__)
# include "../../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

VueNiveauEntier::VueNiveauEntier(Niveau niveau, Carte* carte, int tailleCase) : sf::View(sf::FloatRect(0, 0, niveau.getLongueur() * tailleCase, niveau.getHauteur() * tailleCase))
{
	this->carte = carte;
}
