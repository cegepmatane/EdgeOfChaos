#include <SFML/Graphics.hpp>
#include <iostream>
#include "VueGrille.h"

VueGrille::VueGrille(int hauteur, int longueur) : RenderWindow(sf::VideoMode::getDesktopMode(), "Fenêtre de jeu", sf::Style::None)
{
	this->hauteur = hauteur;
	this->longueur = longueur;

	//TILEMAP


	sf::View vueGrille (sf::FloatRect(200, 200, 200, 200)); // COORD A CHANGER
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
						vueGrille.move(50, 0);
						this->setView(vueGrille);
					}
					break;
				case sf::Keyboard::Z:
					if (vueCarte)
					{
						vueGrille.move(0, -50);
						this->setView(vueGrille);
					}
					break;
				case sf::Keyboard::S:
					if (vueCarte)
					{
						vueGrille.move(0, 50);
						this->setView(vueGrille);
					}
					break;
				case sf::Keyboard::Q:
					if (vueCarte)
					{
						vueGrille.move(-50, 0);
						this->setView(vueGrille);
					}
					break;
				}
			}

		}

		this->clear(sf::Color::White);

		//AFFICHER LA TILEMAP

		this->display();
	}
}
