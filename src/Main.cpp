#include <SFML/Graphics.hpp>
#include "../inclusion/menu.h"
#include "../inclusion/VueGrille.h"
#include "../inclusion/vueGenerale.h"
#include "../inclusion/Unite.h"
#include "../inclusion/VuePanneauUnite.h"
#include "../inclusion/VuePanneauBatiment.h" 

int main()
{
	int tailleCase = 64;

	int hauteurGenerale = 20;
	int hauteurGrille = 9;
	int hauteurPanneau = 3;

	int longueurGenerale = 40;
	int longueurGrille = 20;

	int niveau[] =
	{
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 4, 4, 4, 4, 4, 4, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 4, 4, 4, 2, 2, 4, 4, 4, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 2, 2, 4, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2, 2, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 2, 2, 2, 4, 4, 4, 2, 2, 1, 0, 0, 1, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0,
		2, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	std::string imagePanneau = "ressources/textures/bois2.jpg";

	int attaque = 10;
	std::vector<std::string> listeAttaques;
	listeAttaques.push_back("Charge");
	listeAttaques.push_back("Chun chun maru!");
	Unite unite("Test", 100, tailleCase*16, tailleCase*14, attaque, 10, listeAttaques);
	unite.setImage("ressources/textures/textures.png", 8);

	std::vector<std::string> optionsBatiment;
	optionsBatiment.push_back("Créer un lancier");
	optionsBatiment.push_back("Créer un homme d'arme");
	Batiment batiment("Caserne", 100, tailleCase * 26, tailleCase * 9, "Vous pouvez y former des unités", optionsBatiment);
	batiment.setImage("ressources/textures/textures.png", 9);

	sf::RenderWindow fenetre(sf::VideoMode(1280, 768), "Edge of Chaos");

	VueGrille vueGrille(longueurGenerale, hauteurGenerale, longueurGrille, hauteurGrille, tailleCase, niveau);
	VueGenerale vueGenerale(longueurGenerale, hauteurGenerale, tailleCase, niveau);
	VuePanneauUnite panneauBoisUnite(longueurGrille, hauteurPanneau, tailleCase, &unite, imagePanneau);
	VuePanneauBatiment panneauBoisBatiment(longueurGrille, hauteurPanneau, tailleCase, imagePanneau, &batiment);
	panneauBoisBatiment.init();

	fenetre.setView(vueGrille);
	bool estVueGrille = true;

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
						estVueGrille = false;
					}
					else
					{
						estVueGrille = true;
					}
					break;
				case sf::Keyboard::D: case sf::Keyboard::Right:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != (tailleCase*longueurGenerale)- (tailleCase * 20))
					{
						vueGrille.move(tailleCase, 0);
						vueGrille.setCompteurLongueur(vueGrille.getCompteurLongueur() + tailleCase);
					}
					break;
				case sf::Keyboard::Z: case sf::Keyboard::Up:
					if (estVueGrille&&vueGrille.getCompteurHauteur() != 0)
					{
						vueGrille.move(0, -tailleCase);
						vueGrille.setCompteurHauteur(vueGrille.getCompteurHauteur() - tailleCase);
					}
					break;
				case sf::Keyboard::I:
					unite.setAttaque(++attaque);
					panneauBoisUnite.mettreAJourTexte();
					break;
				case sf::Keyboard::O:
					unite.setAttaque(--attaque);
					panneauBoisUnite.mettreAJourTexte();
					break;
				case sf::Keyboard::S: case sf::Keyboard::Down:
					if (estVueGrille&&vueGrille.getCompteurHauteur() != (tailleCase*hauteurGenerale) - tailleCase*hauteurGrille)
					{
						vueGrille.move(0, tailleCase);
						vueGrille.setCompteurHauteur(vueGrille.getCompteurHauteur() + tailleCase);
					}
					break;
				case sf::Keyboard::Q: case sf::Keyboard::Left:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != 0)
					{
						vueGrille.move(-tailleCase, 0);
						vueGrille.setCompteurLongueur(vueGrille.getCompteurLongueur() - tailleCase);
					}
					break;
				}
			}

		}

		fenetre.clear(sf::Color::Black);

		//AFFICHER LA TILEMAP ET LE PANNEAU
		if (estVueGrille)
		{
			fenetre.setView(vueGrille);
			fenetre.draw(vueGrille.getCarte());
			fenetre.draw(unite);
			fenetre.draw(batiment);

			//fenetre.setView(panneauBoisUnite);
			//panneauBoisUnite.dessiner(fenetre);
			fenetre.setView(panneauBoisBatiment);
			panneauBoisBatiment.draw(fenetre);
		}
		else
		{
			fenetre.setView(vueGenerale);
			fenetre.draw(vueGenerale.getCarte());
			fenetre.draw(unite);
			fenetre.draw(batiment);
		}

		fenetre.display();
	}

	return 0;
}
