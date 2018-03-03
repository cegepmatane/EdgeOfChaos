#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entite
{
protected:
	std::string nom;
	int pointDeVie;
	sf::Vector2f position;
	std::string image;
	int numTexture;

public:
	Entite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur);

	std::string getNom() { return nom; }
	int getPointDeVie() { return pointDeVie; }
	sf::Vector2f getPosition() { return position; }
	std::string getImage() { return image; }
	int getNumTexture() { return numTexture; }
	
	void setNom(std::string nomEntite) { nom = nomEntite; }
	void setPointDeVie(int pointDeVieEntite) { pointDeVie = pointDeVieEntite; }
	void setImage(std::string image) { this->image = image; }
	void setNumTexture(int numTexture) { this->numTexture = numTexture; }
	void setPosition(int x, int y) { position = sf::Vector2f(x, y); }
};