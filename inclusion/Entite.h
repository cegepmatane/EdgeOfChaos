#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Entite
{
protected:
	std::string nom;
	int pointsDeVie;
	sf::Vector2f position;
	std::string image;
	int numTexture;

public:
	Entite(std::string& nom, int pointsDeVie, int positionLargeur, int positionHauteur);

	std::string getNom() { return nom; }
	int getPointsDeVie() { return pointsDeVie; }
	sf::Vector2f getPosition() { return position; }
	std::string getImage() { return image; }
	int getNumTexture() { return numTexture; }

	void setNom(std::string& nom) { this->nom = nom; }
	void setPointsDeVie(int pointsDeVie) { this->pointsDeVie = pointsDeVie; }
	//void setImage(std::string& image) { this->image = image; }
	void setNumTexture(int numTexture) { this->numTexture = numTexture; }
	void setPosition(int x, int y) { position = sf::Vector2f(x, y); }
};
