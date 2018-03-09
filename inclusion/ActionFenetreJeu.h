#pragma once
#include "FenetreJeu.h"
#include "Unite.h"
#include "Batiment.h"

class FenetreJeu;

class ActionFenetreJeu
{
public:
	ActionFenetreJeu();
	void clicGauche(FenetreJeu* fenetre, std::vector<int> positionSouris);
	void clicDroit(FenetreJeu* fenetre, std::vector<int> positionSouris);
};