#pragma once
#include <SFML/Graphics.hpp>

class Panneau : public sf::Sprite
{
private:
	int longueur;
	int hauteur;
	sf::Texture texture;

public:
	Panneau(int longueurPanneau, int hauteurPanneau, sf::Texture texturePanneau);
	int getLongueurPanneau() { return longueur; }
	int getHauteurPanneau() { return hauteur; }
	sf::Texture getTexturePanneau() { return texture; }

	void setLongueurPanneau(int longueurPanneau) { longueur = longueurPanneau; }
	void setHauteurPanneau(int hauteurPanneau) { hauteur = hauteurPanneau; }
	void setTexturePanneau(sf::Texture texturePanneau) { texture = texturePanneau; }
};