#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class VueGrille : public sf::RenderWindow
{
private:
	int hauteur;
	int longueur;
	int tailleCase;
	TileMap carte;
	sf::View vueGrille;
	sf::View vueGénérale;
	int compteurHaut, compteurBas, compteurGauche, compteurDroite;
	sf::Sprite spritePanneau;

public:
	VueGrille(int hauteur, int longueur, int tailleCase);
	int getHauteur() { return hauteur; }
	int getLongueur() { return longueur; }
	void boucleOpen();
};
