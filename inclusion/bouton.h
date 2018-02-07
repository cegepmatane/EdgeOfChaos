#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Bouton : public sf::RectangleShape{
	private:
		int bordure;
		sf::Text contenu;
		sf::Font police;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void initBordure(const sf::Color& couleur);
		void initContenu(std::string& texte, const std::string& cheminPolice);
	public:
		Bouton(int hauteur, int longueur, std::string texte, const std::string& cheminPolice);
		void setBtnPosition(float x, float y);
		const sf::Vector2f getPosition() override;
		const sf::Vector2f getSize() override;
		
};
