#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "bouton.h"

class Menu : public sf::RenderWindow{
	private:
		Bouton * actionHeberger;
		Bouton * actionJoindre;
		Bouton * actionParametres;
		sf::Font policeBoutons;
		int positionXBoutons;
		int offsetYBoutons;
		int espacementBoutons;

		sf::Text titre;
		sf::Font policeTitre;

		void initFenetre();
		void initTitre(const std::string& cheminPolice);
		void initBoutons(const std::string& cheminPolice, const double proportion);
	public:
		Menu();
		Bouton getHeberger();
		Bouton getJoindre();
		Bouton getParametres();
		~Menu();
};
