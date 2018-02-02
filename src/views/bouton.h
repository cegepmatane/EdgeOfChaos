#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "bouton.h"

class Bouton : public sf::RectangleShape{
	private:
		int bordure;
		sf::Text contenu;
	public:
		Bouton(int hauteur, int longueur, std::string texte, sf::Font police);
		sf::Vector2f getPosition();
		void setPosition(float x, float y);
};
