#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Entite.h"

class Unite : public Entite
{
private:
	int attaque;
	int defense;

public:
	Unite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, int attaqueUnite, int defenseUnite);
	int getAttaque() { return attaque; }
	int getDefense() { return defense; }

	void setAttaque(int attaqueUnite) { attaque = attaqueUnite; }
	void setDefense(int defenseUnite) { defense = defenseUnite; }
};
