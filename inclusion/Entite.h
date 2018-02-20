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

public:
	Entite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur);

	std::string getNom() { return nom; }
	int getPointDeVie() { return pointDeVie; }
	sf::Vector2f getVraiePosition() { return vraiePosition; }
	sf::Texture getTexture() { return texture; }
	
	void setNom(std::string nomEntite) { nom = nomEntite; }
	void setPointDeVie(int pointDeVieEntite) { pointDeVie = pointDeVieEntite; }
	void setImage(std::string image, int numTexture);
};