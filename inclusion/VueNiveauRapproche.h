#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carte.h"
#include "Niveau.h"

class VueNiveauRapproche : public sf::View
{
private:
	Carte* carte;
	int compteurHauteur, compteurLongueur;

public:
	VueNiveauRapproche(Niveau niveau, Carte* carte, int longueurGrille, int hauteurGrille, int tailleCase);

	int getCompteurHauteur() { return compteurHauteur; }
	int getCompteurLongueur() { return compteurLongueur; }

	void setCompteurHauteur(int hauteur) { compteurHauteur = hauteur; }
	void setCompteurLongueur(int longueur) { compteurLongueur = longueur; }

	Carte* getCarte() { return carte; }
};
