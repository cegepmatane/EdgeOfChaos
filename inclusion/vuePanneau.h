#pragma once
#include <SFML/Graphics.hpp>

class VuePanneau : public sf::View
{
protected:
	int longueur;
	int hauteur;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	VuePanneau(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image);
	int getLongueurPanneau() { return longueur; }
	int getHauteurPanneau() { return hauteur; }
	sf::Texture getTexturePanneau() { return texture; }

	void setLongueurPanneau(int longueurPanneau) { longueur = longueurPanneau; }
	void setHauteurPanneau(int hauteurPanneau) { hauteur = hauteurPanneau; }
	void setTexturePanneau(sf::Texture texturePanneau) { texture = texturePanneau; }
	
	sf::Sprite getSprite() { return sprite; }
};