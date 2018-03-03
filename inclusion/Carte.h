/*
 * Le code ci-apres a ete adapte de celui present sur le site suivant :
 * https://www.sfml-dev.org/tutorials/2.4/graphics-vertex-array-fr.php
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Niveau.h"
#include "Entite.h"

class Carte : public sf::Drawable, public sf::Transformable
{
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
	std::vector<sf::Sprite*> entites;

public:
	Carte(const std::string& texture, sf::Vector2u tailleCase, Niveau niveau);
	bool charger(const std::string& texture, sf::Vector2u tailleCase, Niveau niveau);
	void ajouterEntite(Entite* entite, int positionLongueur, int positionHauteur);
	void deplacerEntite(int anciennePositionLongueur, int anciennePositionHauteur, int nouvellePositionLongueur, int nouvellePositionHauteur);
	void dessinerEntites(sf::RenderTarget& cible);
	std::vector<sf::Sprite*> getEntites() { return entites; }
	~Carte();
};
