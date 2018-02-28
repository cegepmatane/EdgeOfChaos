#pragma once
#include <SFML/Graphics.hpp>
#include "Unite.h"
#include "Batiment.h"
#include "VueNiveauRapproche.h"
#include "VueNiveauEntier.h"
#include "VuePanneauUnite.h"
#include "VuePanneauBatiment.h"
#include "Menu.h"

class Menu;

class FenetreJeu : public sf::RenderWindow
{
private:
	int longueurFenetre, hauteurFenetre, longueurGrille, hauteurGrille, tailleCase, hauteurPanneau;
	Niveau niveau;
	std::string nomFenetre, imagePanneau;
	std::vector<Unite*> unites;
	std::vector<Batiment*> batiments;
	bool estVueGrille;
	bool estUnite, estBatiment;
	Unite* uniteSelect;
	Batiment* batimentSelect;
	VueNiveauRapproche vueGrille;
	VueNiveauEntier vueGenerale;
	VuePanneauUnite panneauBoisUnite;
	VuePanneauBatiment panneauBoisBatiment;
	VuePanneau panneauBois;
	sf::Texture textureCurseur;
	sf::Sprite spriteCurseur;
	bool curseurPresent=false;

public:
	FenetreJeu(int longueurFenetre, int hauteurFenetre, std::string nomFenetre, Niveau niveau, int longueurGrille, int hauteurGrille, int tailleCase, int hauteurPanneau,
		std::string imagePanneau, std::vector<Unite*> &unites, std::vector<Batiment*> &batiments);

	void lancerBoucle(Menu* menu);
};
