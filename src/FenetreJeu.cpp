#include <SFML/Graphics.hpp>
#include "../inclusion/FenetreJeu.h"

FenetreJeu::FenetreJeu(int longueurFenetre, int hauteurFenetre, std::string nomFenetre, int longueurGenerale, int hauteurGenerale, int longueurGrille, int hauteurGrille,
	int tailleCase, int hauteurPanneau, int niveau[], std::string imagePanneau, std::vector<Unite> listeUnites, std::vector<Batiment> listeBatiment) :
	sf::RenderWindow(sf::VideoMode(longueurFenetre, hauteurFenetre), nomFenetre),
	longueurFenetre(longueurFenetre), hauteurFenetre(hauteurFenetre), nomFenetre(nomFenetre),
	longueurGenerale(longueurGenerale), hauteurGenerale(hauteurGenerale), longueurGrille(longueurGrille), hauteurGrille(hauteurGrille), tailleCase(tailleCase),
	hauteurPanneau(hauteurPanneau), niveau(niveau), imagePanneau(imagePanneau), listeUnites(listeUnites), listeBatiments(listeBatiment),
	vueGrille(longueurGenerale, hauteurGenerale, longueurGrille, hauteurGrille, tailleCase, niveau),
	vueGenerale(longueurGenerale, hauteurGenerale, tailleCase, niveau),
	panneauBoisUnite(longueurGrille, hauteurPanneau, tailleCase, &listeUnites.front(), imagePanneau),
	panneauBoisBatiment(longueurGrille, hauteurPanneau, tailleCase, imagePanneau, &listeBatiment.front())
{
	this->setView(vueGrille);
	estVueGrille = true;
}

void FenetreJeu::lancerBoucle()
{
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
					if (estVueGrille&&vueGrille.getCompteurLongueur() != (tailleCase*longueurGenerale) - (tailleCase * 20))
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

		this->clear(sf::Color::Black);

		//AFFICHER LA TILEMAP ET LE PANNEAU
		if (estVueGrille)
		{
			this->setView(vueGrille);
			this->draw(vueGrille.getCarte());
			
			for (Unite unite : listeUnites)
			{
				this->draw(unite);
			}
			for (Batiment batiment : listeBatiments)
			{
				this->draw(batiment);
			}

			//this->setView(panneauBoisUnite);
			//panneauBoisUnite.dessiner(*this);
			this->setView(panneauBoisBatiment);
			panneauBoisBatiment.dessiner(*this);
		}
		else
		{
			this->setView(vueGenerale);
			this->draw(vueGenerale.getCarte());
			for (Unite unite : listeUnites)
			{
				this->draw(unite);
			}
			for (Batiment batiment : listeBatiments)
			{
				this->draw(batiment);
			}
		}

		this->display();
	}
}



