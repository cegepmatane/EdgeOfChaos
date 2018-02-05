#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../inclusion/VueGrille.h"
#include "../../inclusion/TileMap.h"

VueGrille::VueGrille(int hauteur, int longueur, int tailleCase) : RenderWindow(sf::VideoMode::getDesktopMode(), "Fenêtre de jeu", sf::Style::None)
{
	this->hauteur = hauteur;
	this->longueur = longueur;
	this->tailleCase = tailleCase;

	//TILEMAP
	// on définit le niveau à l'aide de numéro de tuiles
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;

	if (map.load("ressources/textures/textures.png", sf::Vector2u(tailleCase, tailleCase), level, 16, 8))
	{

		sf::View vueGrille(sf::FloatRect(0, 0, 1280, 1280)); // haut à gauche, 5x5 textures de 256 px
		vueGrille.setViewport(sf::FloatRect(0, 0, 1, 0.7f));
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
							this->setView(this->getDefaultView());
							vueCarte = false;
						}
						else
						{
							this->setView(vueGrille);
							vueCarte = true;
						}
						break;
					case sf::Keyboard::D:
						if (vueCarte)
						{
							vueGrille.move(tailleCase, 0);
							this->setView(vueGrille);
						}
						break;
					case sf::Keyboard::Z:
						if (vueCarte)
						{
							vueGrille.move(0, -tailleCase);
							this->setView(vueGrille);
						}
						break;
					case sf::Keyboard::S:
						if (vueCarte)
						{
							vueGrille.move(0, tailleCase);
							this->setView(vueGrille);
						}
						break;
					case sf::Keyboard::Q:
						if (vueCarte)
						{
							vueGrille.move(-tailleCase, 0);
							this->setView(vueGrille);
						}
						break;
					}
				}

			}

			this->clear(sf::Color::White);

			//AFFICHER LA TILEMAP
			this->draw(map);

			this->display();
		}
	}
}
