#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "bouton.h"

class Menu : public sf::RenderWindow{
	private:
		Bouton * btnHeberger;
		Bouton * btnJoindre;
		Bouton * btnParametres;
		sf::Font policeBoutons;

		sf::Text titre;
		sf::Font policeTitre;

		void initFenetre();
		void initTitre(const std::string& chemin);
		void initBoutons(const std::string& chemin);
	public:
		Menu();
		void afficher();

		~Menu();
};
