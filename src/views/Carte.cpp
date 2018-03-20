/*
* Le code ci-apres a ete adapte de celui present sur le site suivant :
* https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array-fr.php
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/Carte.h"

Carte::Carte(const std::string& texture, sf::Vector2u tailleCase, Niveau niveau)
{
	charger(texture, tailleCase, niveau);
}


bool Carte::charger(const std::string& texture, sf::Vector2u tailleCase, Niveau niveau)
{
	int largeur = niveau.getLongueur();
	int hauteur = niveau.getHauteur();
	short int* cases = niveau.getCases();

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

void Carte::ajouterEntite(Entite* entite, int positionLongueur, int positionHauteur)
{
	sf::Sprite* entiteSprite = new sf::Sprite();
	sf::Texture* texture = new sf::Texture();

	int numTexture = entite->getNumTexture();
	std::string image = entite->getImage();

	if (!texture->loadFromFile(image, sf::IntRect(64 * numTexture, 0, 64, 64)))
		std::cerr << "Impossible de charger la texture de l'entite. \n ( " << image << " )" << std::endl;
	entiteSprite->setTexture(*texture);
	entiteSprite->setPosition(positionLongueur, positionHauteur);

	entites.push_back(entiteSprite);
}

void Carte::deplacerEntite(int anciennePositionLongueur, int anciennePositionHauteur, int nouvellePositionLongueur, int nouvellePositionHauteur)
{
	//parcourir entites pour trouver le bon Sprite en fonction de son ancienne position et changer sa position
	for (sf::Sprite* entiteSprite : entites)
	{
		if (entiteSprite->getPosition().x == anciennePositionLongueur && entiteSprite->getPosition().y == anciennePositionHauteur)
		{
			entiteSprite->setPosition(nouvellePositionLongueur, nouvellePositionHauteur);
		}
	}
}

void Carte::dessinerEntites(sf::RenderTarget& cible)
{
	for (sf::Sprite* entiteSprite : entites)
	{
		cible.draw(*entiteSprite);
	}
}

Carte::~Carte()
{
	for (sf::Sprite* entiteSprite : entites)
	{
		delete entiteSprite;
	}
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
 * 8 = curseur noir
 * 9 = caserne
 * 10 = barbare
 * 11 = barbare clair
 * 12 = barnare sombre
 */
