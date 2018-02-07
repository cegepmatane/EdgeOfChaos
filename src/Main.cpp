#include <SFML/Graphics.hpp>
#include "../inclusion/menu.h"
#include "../inclusion/VueGrille.h"
#include "../inclusion/vueGénérale.h"

int main()
{
	int tailleCase = 64;

	int hauteurGénérale = 20;
	int hauteurGrille = 9;
	int hauteurPanneau = 3;

	int longueurGénérale = 40;
	int longueurGrille = 20;

	int niveau[] =
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

	sf::Texture texturePanneau;
	texturePanneau.loadFromFile("image.png");

	sf::RenderWindow fenetre(sf::VideoMode(1280, 768), "Edge of Chaos");

	VueGrille vueGrille(longueurGénérale, hauteurGénérale, tailleCase, niveau);
	VueGénérale vueGénérale(longueurGénérale, hauteurGénérale, tailleCase, niveau);

	fenetre.setView(vueGrille);
	bool estVueGrille = true;
	
	//Panneau panneauBois(longueurGrille, hauteurPanneau, texturePanneau);

	/*
	sf::Texture textureBois;
	textureBois.loadFromFile("ressources/textures/bois.jpg");
	spritePanneau.setTexture(textureBois);
	spritePanneau.setPosition(sf::Vector2f(0, tailleCase * 9));

	TODO réussir à afficher le panneau
	*/

	while (fenetre.isOpen())
	{
		sf::Event event;
		while (fenetre.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				fenetre.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::R:
					if (estVueGrille)
					{
						fenetre.setView(vueGénérale);
						estVueGrille = false;
					}
					else
					{
						fenetre.setView(vueGrille);
						estVueGrille = true;
					}
					break;
				case sf::Keyboard::D:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != (tailleCase*longueurGénérale)- (tailleCase * 20))
					{
						vueGrille.move(tailleCase, 0);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurLongueur(vueGrille.getCompteurLongueur() + tailleCase);
					}
					break;
				case sf::Keyboard::Right:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != (tailleCase*longueurGénérale) - (tailleCase * longueurGrille))
					{
						vueGrille.move(tailleCase, 0);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurLongueur(vueGrille.getCompteurLongueur() + tailleCase);
					}
					break;
				case sf::Keyboard::Z:
					if (estVueGrille&&vueGrille.getCompteurHauteur() != 0)
					{
						vueGrille.move(0, -tailleCase);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurHauteur(vueGrille.getCompteurHauteur() - tailleCase);
					}
					break;
				case sf::Keyboard::Up:
					if (estVueGrille&&vueGrille.getCompteurHauteur() != 0)
					{
						vueGrille.move(0, -tailleCase);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurHauteur(vueGrille.getCompteurHauteur() - tailleCase);
					}
					break;
				case sf::Keyboard::S:
					if (estVueGrille&&vueGrille.getCompteurHauteur() != (tailleCase*hauteurGénérale) - tailleCase*hauteurGrille)
					{
						vueGrille.move(0, tailleCase);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurHauteur(vueGrille.getCompteurHauteur() + tailleCase);
					}
					break;
				case sf::Keyboard::Down:
					if (estVueGrille&&vueGrille.getCompteurHauteur() != (tailleCase*hauteurGénérale) - tailleCase*hauteurGrille)
					{
						vueGrille.move(0, tailleCase);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurHauteur(vueGrille.getCompteurHauteur() + tailleCase);
					}
					break;
				case sf::Keyboard::Q:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != 0)
					{
						vueGrille.move(-tailleCase, 0);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurLongueur(vueGrille.getCompteurLongueur() - tailleCase);
					}
					break;
				case sf::Keyboard::Left:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != 0)
					{
						vueGrille.move(-tailleCase, 0);
						fenetre.setView(vueGrille);
						vueGrille.setCompteurLongueur(vueGrille.getCompteurLongueur() - tailleCase);
					}
					break;
				}
			}

		}

		fenetre.clear(sf::Color::White);

		//AFFICHER LA TILEMAP

		fenetre.draw(vueGrille.getCarte());
		//fenetre.draw(spritePanneau);

		fenetre.display();
	}

	return 0;
}
