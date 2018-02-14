#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueNiveauRapproche : public sf::View
{
private:
	TileMap carte;
	int compteurHauteur, compteurLongueur;

public:
	VueNiveauRapproche(int longueurNiveau, int hauteurNiveau, int longueurGrille, int hauteurGrille, int tailleCase, int niveau[]);

	int getCompteurHauteur() { return compteurHauteur; }
	int getCompteurLongueur() { return compteurLongueur; }

	void setCompteurHauteur(int hauteur) { compteurHauteur = hauteur; }
	void setCompteurLongueur(int longueur) { compteurLongueur = longueur; }

	TileMap getCarte() { return carte; }
};
