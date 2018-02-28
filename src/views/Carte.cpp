/*
* Le code ci-apres a ete adapte de celui present sur le site suivant :
* https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array-fr.php
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/Carte.h"

bool Carte::charger(const std::string& texture, sf::Vector2u tailleCase, const int* cases, unsigned largeur, unsigned hauteur)
{
	// on charge la texture du tileset
	if (!textureCases.loadFromFile(texture))
		return false;

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	tableauCases.setPrimitiveType(sf::Quads);
	tableauCases.resize(largeur * hauteur * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int compteurLargeur = 0; compteurLargeur < largeur; ++compteurLargeur)
		for (unsigned int compteurHauteur = 0; compteurHauteur < hauteur; ++compteurHauteur)
		{
			// on récupère le numéro de tuile courant
			int numeroCase = cases[compteurLargeur + compteurHauteur * largeur];

			// on en déduit sa position dans la texture du tileset
			int tu = numeroCase % (textureCases.getSize().x / tailleCase.x);
			int tv = numeroCase / (textureCases.getSize().x / tailleCase.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* caseUnique = &tableauCases[(compteurLargeur + compteurHauteur * largeur) * 4];

			// on définit ses quatre coins
			caseUnique[0].position = sf::Vector2f(compteurLargeur * tailleCase.x, compteurHauteur * tailleCase.y);
			caseUnique[1].position = sf::Vector2f((compteurLargeur + 1) * tailleCase.x, compteurHauteur * tailleCase.y);
			caseUnique[2].position = sf::Vector2f((compteurLargeur + 1) * tailleCase.x, (compteurHauteur + 1) * tailleCase.y);
			caseUnique[3].position = sf::Vector2f(compteurLargeur * tailleCase.x, (compteurHauteur + 1) * tailleCase.y);

			// on définit ses quatre coordonnées de texture
			caseUnique[0].texCoords = sf::Vector2f(tu * tailleCase.x, tv * tailleCase.y);
			caseUnique[1].texCoords = sf::Vector2f((tu + 1) * tailleCase.x, tv * tailleCase.y);
			caseUnique[2].texCoords = sf::Vector2f((tu + 1) * tailleCase.x, (tv + 1) * tailleCase.y);
			caseUnique[3].texCoords = sf::Vector2f(tu * tailleCase.x, (tv + 1) * tailleCase.y);
		}

	return true;
}

/* Correspondance numéros et textures :
 * 0 = desert
 * 1 = eau
 * 2 = pierre
 * 3 = plaine
 * 4 = plaine2
 * 5 = route
 * 6 = route2
 * 7 = bois
 * 8 = maison
 * 9 = taverne
 * 10 = eglise
 * 11 = moulin
 * 12 = cavalier
 * 13 = curseur noir
 */
