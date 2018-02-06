#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Bouton : public sf::RectangleShape{
	private:
		int bordure;
		sf::Text contenu;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		Bouton(int hauteur, int longueur, std::string texte, sf::Font& police);
		void setBtnPosition(float x, float y);
		const sf::Vector2f getPosition();
};
