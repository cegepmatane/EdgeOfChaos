#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/TileMap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned width, unsigned height)
{
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// on r�cup�re le num�ro de tuile courant
			int tileNumber = tiles[i + j * width];

			// on en d�duit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// on r�cup�re un pointeur vers le quad � d�finir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on d�finit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on d�finit ses quatre coordonn�es de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

/* Correspondance num�ros et textures :
 * 0 = d�sert
 * 1 = eau
 * 2 = pierre
 * 3 = plaine
 * 4 = plaine2
 * 5 = route
 * 6 = route2
 */