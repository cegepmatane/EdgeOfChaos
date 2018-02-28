#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Bouton.h"
#include "FenetreJeu.h"
#include "Niveau.h"

class FenetreJeu;

class Menu : public sf::RenderWindow{
	private:
		sf::RectangleShape cadreErreur;
		sf::Text erreur;
		sf::Font policeErreur;

		Bouton * actionHeberger;
		Bouton * actionJoindre;
		Bouton * actionParametres;
		int positionXBoutons;
		int offsetYBoutons;
		int espacementBoutons;

		sf::Text titre;
		sf::Font policeTitre;

		FenetreJeu * jeu;

		void initFenetre();
		void initTitre(const std::string& police);
		void initBoutons(const std::string& police, const double proportion);
		void initErreur(const std::string& police);
	public:
		Menu();
		void initJeu(Niveau niveau, std::vector<Unite*>& unites, std::vector<Batiment*>& batiments);
		void afficher();
		void lancerErreur( std::string& messageErreur );
		Bouton getHeberger();
		Bouton getJoindre();
		Bouton getParametres();
		~Menu();
};
