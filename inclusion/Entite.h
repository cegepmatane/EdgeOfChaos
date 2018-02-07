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
	Entite(std::string nomEntite, int pointDeVieEntite, sf::Vector2u positionEntite);
	std::string getNom() { return nom; }
	int getPointDeVie() { return pointDeVie; }
	sf::Vector2u getPosition() { return position; }

	void setNom(std::string nomEntite) { nom = nomEntite; }
	void setPointDeVie(int pointDeVieEntite) { pointDeVie = pointDeVieEntite; }
	void setPosition(sf::Vector2u positionEntite) { position = positionEntite; }
};