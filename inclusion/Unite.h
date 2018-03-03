#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Entite.h"

class Unite : public Entite
{
private:
	std::string nom; // temporaire
	int attaque;
	std::vector<std::string> listeAttaques;

public:
	std::string getNom() { return nom; }
	Unite(int pointsDeVie, int positionLargeur, int positionHauteur, int numTexture, int attaque, int defense, std::vector<std::string> attaques);
	int getAttaque() { return attaque; }
	std::vector<std::string> getListeAttaques() { return listeAttaques; }

	void setAttaque(int attaqueUnite) { attaque = attaqueUnite; }
	void setListeAttaques(std::vector<std::string> attaques) { listeAttaques = attaques; }
};
