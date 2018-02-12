#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Entite.h"

class Unite : public Entite
{
private:
	int attaque;
	int defense;
	std::vector<std::string> listeAttaques;

public:
	Unite(std::string nomEntite, int pointDeVieEntite, int positionLargeur, int positionHauteur, int attaqueUnite, int defenseUnite, std::vector<std::string> attaques);
	int getAttaque() { return attaque; }
	int getDefense() { return defense; }
	std::vector<std::string> getListeAttaques() { return listeAttaques; }

	void setAttaque(int attaqueUnite) { attaque = attaqueUnite; }
	void setDefense(int defenseUnite) { defense = defenseUnite; }
	void setListeAttaques(std::vector<std::string> attaques) { listeAttaques = attaques; }
};
