#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Network/Packet.hpp>

class Entite
{
private:
	
	int pointsDefense;
	std::vector<int> position;
	
	std::string image;
	int numTexture;

public:
	Entite(int pointsDeVie, int pointsDefense, int positionLargeur, int positionHauteur, int numTexture);

	int getVie() const { return pointsDeVie; }
	int getDefense() const { return pointsDefense; }
	std::vector<int> getPosition() const { return position; }
	std::string getImage() const { return image; }
	int getNumTexture() const { return numTexture; }

	void setVie(int pointsDeVie) { this->pointsDeVie = pointsDeVie; }
	void setDefense(int pointsDefense) { this->pointsDefense = pointsDefense; }
	void setPosition(int x, int y);
	int pointsDeVie;
};
sf::Packet& operator<<(sf::Packet& paquet, const Entite& e);
sf::Packet& operator>>(sf::Packet& paquet, const Entite& e);