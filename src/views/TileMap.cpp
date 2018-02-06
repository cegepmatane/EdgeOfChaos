#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/TileMap.h"

bool TileMap::load(const std::string& texture, sf::Vector2u tailleCase, const int* cases, unsigned largeur, unsigned hauteur)
{
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(texture))
		return false;

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(largeur * hauteur * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < largeur; ++i)
		for (unsigned int j = 0; j < hauteur; ++j)
		{
			// on récupère le numéro de tuile courant
			int numeroCase = cases[i + j * largeur];

			// on en déduit sa position dans la texture du tileset
			int tu = numeroCase % (m_tileset.getSize().x / tailleCase.x);
			int tv = numeroCase / (m_tileset.getSize().x / tailleCase.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * largeur) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tailleCase.x, j * tailleCase.y);
			quad[1].position = sf::Vector2f((i + 1) * tailleCase.x, j * tailleCase.y);
			quad[2].position = sf::Vector2f((i + 1) * tailleCase.x, (j + 1) * tailleCase.y);
			quad[3].position = sf::Vector2f(i * tailleCase.x, (j + 1) * tailleCase.y);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * tailleCase.x, tv * tailleCase.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tailleCase.x, tv * tailleCase.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tailleCase.x, (tv + 1) * tailleCase.y);
			quad[3].texCoords = sf::Vector2f(tu * tailleCase.x, (tv + 1) * tailleCase.y);
		}

	return true;
}

/* Correspondance numéros et textures :
 * 0 = désert
 * 1 = eau
 * 2 = pierre
 * 3 = plaine
 * 4 = plaine2
 * 5 = route
 * 6 = route2
 */