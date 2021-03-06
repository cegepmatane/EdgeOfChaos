#pragma once

#include <thread>

#include <SFML/Graphics.hpp>

#include "Unite.h"
#include "Batiment.h"
#include "VueNiveauRapproche.h"
#include "VueNiveauEntier.h"
#include "VuePanneauUnite.h"
#include "VuePanneauBatiment.h"
#include "Menu.h"
#include "Serveur.h"
#include "ActionFenetreJeu.h"

class Menu;

class FenetreJeu : public sf::RenderWindow
{
private:
	int longueurFenetre, hauteurFenetre, longueurGrille, hauteurGrille, tailleCase, hauteurPanneau;
	Niveau niveau;
	Carte* carte;
	std::string nomFenetre, imagePanneau;
	std::vector<Unite*>* unites;
	std::vector<Batiment*>* batiments;
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
	
	Serveur* serveur;
	std::thread* client;
	bool jeuFerme;
	void communiquerAuServeur();
	void attendreFermeture();

public:
	FenetreJeu(Niveau niveau, std::vector<Unite*>* unites, std::vector<Batiment*>* batiments, Serveur* serveur=nullptr);

	void lancerBoucle(Menu* menu);
	void ajouterEntite(Entite* entite);
	void deplacerEntite(Entite* entite, int nouvellePositionX, int nouvellePositionY);
	bool positionsEgales(std::vector<int> positionSouris, std::vector<int> positionEntite);

	void setEstUnite(bool estUnite) { this->estUnite = estUnite; }
	void setEstBatiment(bool estBatiment) { this->estBatiment = estBatiment; }
	void setUniteSelect(Unite* unite) { uniteSelect = unite; }
	void setBatimentSelect(Batiment* batiment) { batimentSelect = batiment; }

	sf::Sprite* getSpriteCurseur() { return &spriteCurseur; }
	bool getEstUnite() { return estUnite; }
	std::vector<Unite*>* getUnites() { return unites; }
	std::vector<Batiment*>* getBatiments() { return batiments; }
	Unite* getUniteSelect() { return uniteSelect; }

	VuePanneauUnite* getPanneauBoisUnite() { return &panneauBoisUnite; }
	VuePanneauBatiment* getPanneauBoisBatiment() { return &panneauBoisBatiment; }

	Niveau* getNiveau() { return &niveau; }

	~FenetreJeu();

};
