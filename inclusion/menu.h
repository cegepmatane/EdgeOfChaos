#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "bouton.h"

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

		void initFenetre();
		void initTitre(const std::string& police);
		void initBoutons(const std::string& police, const double proportion);
		void initErreur(const std::string& police);
	public:
		Menu();
		void afficher();
		void lancerErreur( std::string& messageErreur );
		Bouton getHeberger();
		Bouton getJoindre();
		Bouton getParametres();
		~Menu();
};
