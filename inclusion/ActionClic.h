#pragma once
#include "FenetreJeu.h"
#include "Unite.h"
#include "Batiment.h"

class FenetreJeu;

class ActionClic
{
public:
	ActionClic();
	void clicGauche(FenetreJeu* fenetre, std::vector<int> positionSouris);
	void clicDroit(FenetreJeu* fenetre, std::vector<int> positionSouris);
};