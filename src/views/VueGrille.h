#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class VueGrille : public sf::RenderWindow
{
private:
	int hauteur;
	int longueur;
public:
	VueGrille(int hauteur, int longueur);
	int getHauteur() { return hauteur; }
	int getLongueur() { return longueur; }
};