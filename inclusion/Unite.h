#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"

class Unite : public Entite
{
private:
	int attaque;
	int defense;

public:
	Unite(std::string nomEntite, int pointDeVieEntite, sf::Vector2u positionEntite, int attaqueUnite, int defenseUnite);
	int getAttaque() { return attaque; }
	int getDefense() { return defense; }

	void setAttaque(int attaqueUnite) { attaque = attaqueUnite; }
	void setDefense(int defenseUnite) { defense = defenseUnite; }
};
