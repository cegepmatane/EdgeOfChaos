/*
 * Le code ci-apres a ete adapte de celui present sur le site suivant :
 * https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array-fr.php
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool charger(const std::string& texture, sf::Vector2u tailleCase, const int* cases, unsigned largeur, unsigned hauteur);

private:

	virtual void draw(sf::RenderTarget& cible, sf::RenderStates etat) const
	{
		// on applique la transformation
		etat.transform *= getTransform();

		// on applique la texture du tileset
		etat.texture = &textureCases;

		// et on dessine enfin le tableau de vertex
		cible.draw(tableauCases, etat);
	}

	sf::VertexArray tableauCases;
	sf::Texture textureCases;
};