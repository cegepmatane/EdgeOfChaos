#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/VueGrille.h"
#include "../../inclusion/TileMap.h"

VueGrille::VueGrille(int hauteur, int longueur, int tailleCase) : RenderWindow(sf::VideoMode(1280, 768), "Edge of Chaos")
{
	this->hauteur = hauteur;
	this->longueur = longueur;
	this->tailleCase = tailleCase;

	compteurGauche = 0;
	compteurHaut = 0;
	compteurDroite = tailleCase * 20;
	compteurBas = tailleCase * 9;

	//TILEMAP
	// on définit le niveau à l'aide de numéro de case
	const int niveau[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 5, 0, 1, 1,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 0, 0, 5, 0, 0, 0, 1, 1,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 5, 0, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 4, 0, 0, 0, 1, 1, 1, 1, 3, 1, 1, 5, 1, 1, 0, 0, 0, 0, 0, 2, 1, 1,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 3, 0, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 0, 3, 0, 0, 0, 0, 1, 1,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 5, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 5, 1, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 5, 0, 1, 1,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 5, 0, 3, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 1, 2,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 0, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 0, 3, 1, 1,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 5, 1, 0, 0, 0, 0, 0, 0, 1, 1, 5, 1, 1, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 1, 5, 1, 3, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
	};

	// on crée la tilemap avec le niveau précédemment défini

	if (carte.load("ressources/textures/textures.png", sf::Vector2u(tailleCase, tailleCase), niveau, longueur, hauteur))
	{

		vueGrille = sf::View(sf::FloatRect(0, 0, 20*tailleCase, 9*tailleCase));
		vueGrille.setViewport(sf::FloatRect(0, 0, 1, 0.75f));
		this->setView(vueGrille);
		vueGénérale = sf::View(sf::FloatRect(0, 0, longueur * tailleCase, hauteur * tailleCase));
		
	}

	sf::Texture textureBois;
	textureBois.loadFromFile("ressources/textures/bois.jpg");
	spritePanneau.setTexture(textureBois);
	//spritePanneau.setPosition(sf::Vector2f(0, tailleCase*9));

	//TODO réussir à afficher le panneau
}

void VueGrille::boucleOpen()
{
	bool vueCarte = true;
	while (this->isOpen())
	{
		sf::Event event;
		while (this->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::R:
					if (vueCarte)
					{
						this->setView(vueGénérale);
						vueCarte = false;
					}
					else
					{
						this->setView(vueGrille);
						vueCarte = true;
					}
					break;
				case sf::Keyboard::D:
					if (vueCarte&&compteurDroite!=tailleCase*longueur)
					{
						vueGrille.move(tailleCase, 0);
						this->setView(vueGrille);
						compteurDroite += tailleCase;
						compteurGauche += tailleCase;
					}
					break;
				case sf::Keyboard::Z:
					if (vueCarte&&compteurHaut!=0)
					{
						vueGrille.move(0, -tailleCase);
						this->setView(vueGrille);
						compteurBas -= tailleCase;
						compteurHaut -= tailleCase;
					}
					break;
				case sf::Keyboard::S:
					if (vueCarte&&compteurBas!=tailleCase*hauteur)
					{
						vueGrille.move(0, tailleCase);
						this->setView(vueGrille);
						compteurBas += tailleCase;
						compteurHaut += tailleCase;
					}
					break;
				case sf::Keyboard::Q:
					if (vueCarte&&compteurGauche!=0)
					{
						vueGrille.move(-tailleCase, 0);
						this->setView(vueGrille);
						compteurDroite -= tailleCase;
						compteurGauche -= tailleCase;
					}
					break;
				}
			}

		}

		this->clear(sf::Color::White);

		//AFFICHER LA TILEMAP
		//this->draw(carte);
		this->draw(spritePanneau);

		this->display();
	}
}

