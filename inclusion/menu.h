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

		sf::Text titre;
		sf::Font policeTitre;

		void initFenetre();
		void initTitre(const std::string& chemin);
		void initBoutons(const std::string& chemin, const double proportion);
	public:
		Menu();
		void afficher();

		~Menu();
};
