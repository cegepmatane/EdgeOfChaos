#pragma once
#include <SFML/Graphics.hpp>
#include "Unite.h"
#include "Batiment.h"
#include "VueNiveauRapproche.h"
#include "vueNiveauEntier.h"
#include "VuePanneauUnite.h"
#include "VuePanneauBatiment.h"
#include "menu.h"

class Menu;

class FenetreJeu : public sf::RenderWindow
{
private:
	int longueurFenetre, hauteurFenetre, longueurNiveau, hauteurNiveau, longueurGrille, hauteurGrille, tailleCase, hauteurPanneau;
	int *niveau;
	std::string nomFenetre, imagePanneau;
	std::vector<Unite> unites;
	std::vector<Batiment> batiments;
	bool estVueGrille;
	VueNiveauRapproche vueGrille;
	VueNiveauEntier vueGenerale;
	VuePanneauUnite panneauBoisUnite;
	VuePanneauBatiment panneauBoisBatiment;

public:
	FenetreJeu(int longueurFenetre, int hauteurFenetre, std::string nomFenetre, int longueurNiveau, int hauteurNiveau, int longueurGrille, int hauteurGrille, int tailleCase, int hauteurPanneau,
		int niveau[], std::string imagePanneau, std::vector<Unite> &unites, std::vector<Batiment> &batiments);

	void lancerBoucle(Menu* menu);
};
