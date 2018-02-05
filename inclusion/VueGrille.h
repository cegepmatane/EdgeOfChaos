#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class VueGrille : public sf::RenderWindow
{
private:
	int hauteur;
	int longueur;
	int tailleCase;
public:
	VueGrille(int hauteur, int longueur, int tailleCase);
	int getHauteur() { return hauteur; }
	int getLongueur() { return longueur; }
};