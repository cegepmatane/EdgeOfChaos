#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class Entite
{
private:
	int pointsDeVie;
	int pointsDefense;
	std::vector<int> position;
	
	std::string image;
	int numTexture;

public:
	Entite(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur);

	int getVie() { return pointsDeVie; }
	int getDefense() { return pointsDefense; }
	std::vector<int> getPosition() { return position; }
	std::string getImage() { return image; }
	int getNumTexture() { return numTexture; }

	void setVie(int pointsDeVie) { this->pointsDeVie = pointsDeVie; }
	void setDefense(int pointsDefense) { this->pointsDefense = pointsDefense; }
	void setNumTexture(int numTexture) { this->numTexture = numTexture; }
	void setPosition(int x, int y);
};
