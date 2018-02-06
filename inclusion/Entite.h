#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entite
{
protected:
	std::string nom;
	int pointDeVie;
	sf::Vector2u position;

public:
	Entite(std::string nom, int pdv, sf::Vector2u position);
	std::string getNom() { return nom; }
	int getPointDeVie() { return pointDeVie; }
	sf::Vector2u getPosition() { return position; }
};