#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entite : public sf::Sprite
{
protected:
	std::string nom;
	int pointDeVie;
	sf::Vector2f vraiePosition;
	sf::Texture texture;
	int numTexture;

public:
	Entite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur);

	std::string getNom() { return nom; }
	int getPointDeVie() { return pointDeVie; }
	sf::Vector2f getVraiePosition() { return vraiePosition; }
	sf::Texture getTexture() { return texture; }
	int getNumTexture() { return numTexture; }
	
	void setNom(std::string nomEntite) { nom = nomEntite; }
	void setPointDeVie(int pointDeVieEntite) { pointDeVie = pointDeVieEntite; }
	void setImage(std::string image, int numTexture);
	void setVraiePosition(int x, int y) { vraiePosition = sf::Vector2f(x, y); }
};