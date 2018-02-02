#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public sf::RenderWindow{
	private:
		sf::RectangleShape btnHeberger;
		sf::RectangleShape btnJoindre;
		sf::RectangleShape btnParametres;
		sf::Text titre;
	public:
		Menu();
		void afficher();
};
