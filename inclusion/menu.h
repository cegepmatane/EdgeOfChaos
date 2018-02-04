#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "bouton.h"

class Menu : public sf::RenderWindow{
	private:
		Bouton * btnHeberger;
		Bouton * btnJoindre;
		Bouton * btnParametres;
		sf::Text titre;
	public:
		Menu();
		void afficher();

		~Menu();
};
