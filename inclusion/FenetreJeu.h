#pragma once
#include <SFML/Graphics.hpp>
#include "Unite.h"
#include "Batiment.h"
#include "VueGrille.h"
#include "vueGenerale.h"
#include "VuePanneauUnite.h"
#include "VuePanneauBatiment.h"

class FenetreJeu : public sf::RenderWindow
{
private:
	int longueurFenetre, hauteurFenetre, longueurGenerale, hauteurGenerale, longueurGrille, hauteurGrille, tailleCase, hauteurPanneau;
	int *niveau;
	std::string nomFenetre, imagePanneau;
	std::vector<Unite> listeUnites;
	std::vector<Batiment> listeBatiments;
	bool estVueGrille;
	VueGrille vueGrille;
	VueGenerale vueGenerale;
	VuePanneauUnite panneauBoisUnite;
	VuePanneauBatiment panneauBoisBatiment;

public:
	FenetreJeu(int longueurFenetre, int hauteurFenetre, std::string nomFenetre, int longueurGenerale, int hauteurGenerale, int longueurGrille, int hauteurGrille, int tailleCase, int hauteurPanneau,
		int niveau[], std::string imagePanneau, std::vector<Unite> listeUnites, std::vector<Batiment> listeBatiment);

	void lancerBoucle();
};
