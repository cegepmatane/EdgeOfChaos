#include <SFML/Graphics.hpp>
#include "../inclusion/menu.h"
#include "../inclusion/VueGrille.h"
#include "../inclusion/vueGenerale.h"
//#include "../inclusion/vuePanneau.h"
#include "../inclusion/Unite.h"
#include "../inclusion/VuePanneauUnite.h"

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
	std::string imagePanneau = "ressources/textures/bois2.jpg";

	Unite unite("Test", 100, tailleCase*21, tailleCase*10, 10, 10);
	unite.setImage("ressources/textures/textures.png", 8);

	sf::RenderWindow fenetre(sf::VideoMode(1280, 768), "Edge of Chaos");

	VueGrille vueGrille(longueurGenerale, hauteurGenerale, tailleCase, niveau);
	VueGenerale vueGenerale(longueurGenerale, hauteurGenerale, tailleCase, niveau);
	//VuePanneau panneauBois(longueurGrille, hauteurPanneau, tailleCase, imagePanneau);

	VuePanneauUnite panneauBoisUnite(longueurGrille, hauteurPanneau, tailleCase, imagePanneau, unite);
	sf::Sprite spriteBois = panneauBoisUnite.getSprite();

	sf::Font fonte;
	fonte.loadFromFile("ressources/polices/LinuxLibertine-Classique.ttf");
	
	sf::Text statistiquesTexte("Statistiques : ", fonte, 60);
	statistiquesTexte.setOutlineColor(sf::Color::Black);
	statistiquesTexte.setOutlineThickness(3.f);
	statistiquesTexte.setStyle(sf::Text::Bold);
	statistiquesTexte.setFillColor(sf::Color::White);
	statistiquesTexte.setScale(0.5f, 0.8f);
	statistiquesTexte.setPosition(tailleCase/2, 10);

	sf::Text pointsTexte("Points forts / faibles :", fonte, 60);
	pointsTexte.setOutlineColor(sf::Color::Black);
	pointsTexte.setOutlineThickness(3.f);
	pointsTexte.setStyle(sf::Text::Bold);
	pointsTexte.setFillColor(sf::Color::White);
	pointsTexte.setScale(0.5f, 0.8f);
	pointsTexte.setPosition((tailleCase*16)/2, 10);

	sf::Text attaquesTexte("Attaques spéciales :", fonte, 60);
	attaquesTexte.setOutlineColor(sf::Color::Black);
	attaquesTexte.setOutlineThickness(3.f);
	attaquesTexte.setStyle(sf::Text::Bold);
	attaquesTexte.setFillColor(sf::Color::White);
	attaquesTexte.setScale(0.5f, 0.8f);
	attaquesTexte.setPosition((tailleCase*31)/2, 10);

	/*sf::Text attaqueTexte("Attaque", fonte, 70);
	attaqueTexte.setFillColor(sf::Color::Black);
	attaqueTexte.setScale(0.5f, 0.8f);
	attaqueTexte.setPosition(tailleCase, tailleCase);*/


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
			fenetre.setView(panneauBoisUnite);
			fenetre.draw(spriteBois);
			fenetre.draw(statistiquesTexte);
			fenetre.draw(pointsTexte);
			fenetre.draw(attaquesTexte);
			//fenetre.draw(attaqueTexte);
		}
		else
		{
			fenetre.setView(vueGenerale);
			fenetre.draw(vueGenerale.getCarte());
			fenetre.draw(unite);
		}
		

		fenetre.display();
	}

	return 0;
}
