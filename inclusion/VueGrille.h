#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueGrille : public sf::View
{
private:
	TileMap carte;
	int compteurHauteur, compteurLongueur;

public:
	VueGrille(int longueur, int hauteur, int tailleCase, int niveau[]);

	int getCompteurHauteur() { return compteurHauteur; }
	int getCompteurLongueur() { return compteurLongueur; }

	void setCompteurHauteur(int hauteur) { compteurHauteur = hauteur; }
	void setCompteurLongueur(int longueur) { compteurLongueur = longueur; }

	TileMap getCarte() { return carte; }
};
