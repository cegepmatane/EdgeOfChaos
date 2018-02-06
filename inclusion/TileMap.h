#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(const std::string& texture, sf::Vector2u tailleCase, const int* cases, unsigned largeur, unsigned hauteur);

private:

	virtual void draw(sf::RenderTarget& cible, sf::RenderStates etat) const
	{
		// on applique la transformation
		etat.transform *= getTransform();

		// on applique la texture du tileset
		etat.texture = &m_tileset;

		// et on dessine enfin le tableau de vertex
		cible.draw(m_vertices, etat);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};