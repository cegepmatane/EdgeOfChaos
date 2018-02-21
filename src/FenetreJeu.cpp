#include <SFML/Graphics.hpp>
#include "../inclusion/FenetreJeu.h"
#include "../systemes/interfaceWindows.h"
# if defined (__linux__)
# include "../systemes/interfaceDebian.h"
# elif defined (_WIN64) || (_WIN32)
# include "../../systemes/interfaceWindows.h"
# endif

FenetreJeu::FenetreJeu(int longueurFenetre, int hauteurFenetre, std::string nomFenetre, int longueurNiveau, int hauteurNiveau, int longueurGrille, int hauteurGrille,
	int tailleCase, int hauteurPanneau, int niveau[], std::string imagePanneau, std::vector<Unite> &unites, std::vector<Batiment> &batiments) :
	sf::RenderWindow(sf::VideoMode(longueurFenetre, hauteurFenetre), nomFenetre, sf::Style::Close),
	longueurFenetre(longueurFenetre), hauteurFenetre(hauteurFenetre), nomFenetre(nomFenetre),
	longueurNiveau(longueurNiveau), hauteurNiveau(hauteurNiveau), longueurGrille(longueurGrille), hauteurGrille(hauteurGrille), tailleCase(tailleCase),
	hauteurPanneau(hauteurPanneau), niveau(niveau), imagePanneau(imagePanneau), unites(unites), batiments(batiments),
	vueGrille(longueurNiveau, hauteurNiveau, longueurGrille, hauteurGrille, tailleCase, niveau),
	vueGenerale(longueurNiveau, hauteurNiveau, tailleCase, niveau),
	panneauBoisUnite(longueurGrille, hauteurPanneau, tailleCase, &unites.front(), imagePanneau),
	panneauBoisBatiment(longueurGrille, hauteurPanneau, tailleCase, imagePanneau, &batiments.front()),
	panneauBois(longueurGrille, hauteurPanneau, tailleCase, imagePanneau)
{
	this->setView(vueGrille);
	estVueGrille = true;
}

void FenetreJeu::lancerBoucle(Menu* menu)
{
	menu->close();
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
					if (estVueGrille&&vueGrille.getCompteurLongueur() != (tailleCase*longueurNiveau) - (tailleCase * 20))
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
					if (estVueGrille&&vueGrille.getCompteurHauteur() != (tailleCase*hauteurNiveau) - tailleCase*hauteurGrille)
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

			if (event.type == sf::Event::MouseButtonPressed)
			{
				int clicX = sf::Mouse::getPosition(*this).x;
				int clicY = sf::Mouse::getPosition(*this).y;

				if (clicX<longueurFenetre && clicX>0 && clicY<tailleCase*hauteurGrille && clicY>0 && estVueGrille)
				{
					//Pour avoir les coordonnees du coin haut-gauche
					clicX = clicX - clicX%tailleCase;
					clicY = clicY - clicY%tailleCase;

					// Pour avoir les coordonnees absolues
					clicX += vueGrille.getCompteurLongueur();
					clicY += vueGrille.getCompteurHauteur();

					sf::Vector2f positionSouris(clicX, clicY);

					if (event.mouseButton.button == sf::Mouse::Left)
					{
						estUnite = false;
						estBatiment = false;
						uniteSelect = nullptr;
						batimentSelect = nullptr;

						for (Unite unite : unites)
						{
							if (positionSouris == unite.getVraiePosition())
							{
								estUnite = true;
								uniteSelect = &unite;
							}
						}
						for (Batiment batiment : batiments)
						{
							if (positionSouris == batiment.getVraiePosition())
							{
								estBatiment = true;
								batimentSelect = &batiment;
							}
						}
					} else if (event.mouseButton.button == sf::Mouse::Right && uniteSelect!=nullptr)
					{
						// Verification du contenu de la case cliquee
						bool caseOccupee = false;
						for (Unite unite : unites)
						{
							if (positionSouris == unite.getVraiePosition())
							{
								caseOccupee = true;
								
							}
						}
						for (Batiment batiment : batiments)
						{
							if (positionSouris == batiment.getVraiePosition())
							{
								caseOccupee = true;
							}
						}

						// Mettre l'unite sur la case cliquee
						if (!caseOccupee)
						{
							Unite uniteDeplacee = Unite(uniteSelect->getNom(), uniteSelect->getPointDeVie(), positionSouris.x,
								positionSouris.y, uniteSelect->getAttaque(), uniteSelect->getDefense(), uniteSelect->getListeAttaques()); 

							uniteDeplacee.setImage(Configuration::cheminTextures+"textures.png", uniteSelect->getNumTexture());
							
							int compteurUnite = 0;
							for (Unite unite : unites)
							{
								if(unite.getVraiePosition()==uniteSelect->getVraiePosition())
								{
									unites.erase(unites.begin() + compteurUnite);
								}
								compteurUnite++;
							}
							unites.push_back(uniteDeplacee);

							uniteSelect = nullptr;

						}

					}
				}
			}
		}

		this->clear(sf::Color::Black);

		//AFFICHER LA TILEMAP ET LE PANNEAU
		if (estVueGrille)
		{
			//Affichage de la carte et des entites
			this->setView(vueGrille);
			this->draw(vueGrille.getCarte());
			
			for (Unite unite : unites)
			{
				this->draw(unite);
			}
			for (Batiment batiment : batiments)
			{
				this->draw(batiment);
			}

			//Affichage du panneauBois
			if (estUnite)
			{
				panneauBoisUnite.setUnite(uniteSelect);
				/*uniteSelect->setAttaque(200);
				panneauBoisUnite.mettreAJourTexte();*/
				this->setView(panneauBoisUnite);
				panneauBoisUnite.dessiner(*this);
			}
			else if (estBatiment)
			{
				panneauBoisBatiment.setBatiment(batimentSelect);
				this->setView(panneauBoisBatiment);
				panneauBoisBatiment.dessiner(*this);
			}
			else
			{
				this->setView(panneauBois);
				this->draw(panneauBois.getSprite());
			}
		}
		else
		{
			this->setView(vueGenerale);
			this->draw(vueGenerale.getCarte());
			for (Unite unite : unites)
			{
				this->draw(unite);
			}
			for (Batiment batiment : batiments)
			{
				this->draw(batiment);
			}
		}

		this->display();
	}
}
