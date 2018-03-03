#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Entite
{
private:
	int pointsDeVie;
	int pointsDefense;
	sf::Vector2f position;
	
	std::string image;
	int numTexture;

public:
	Entite(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur);

	int getPointsDeVie() { return pointsDeVie; }
	int getPointsDefense() { return pointsDefense; }
	sf::Vector2f getPosition() { return position; }
	std::string getImage() { return image; }
	int getNumTexture() { return numTexture; }

	void setPointsDeVie(int pointsDeVie) { this->pointsDeVie = pointsDeVie; }
	void setPointsDefense(int pointsDefense) { this->pointsDefense = pointsDefense; }
	void setNumTexture(int numTexture) { this->numTexture = numTexture; }
	void setPosition(int x, int y) { position = sf::Vector2f(x, y); }
};
