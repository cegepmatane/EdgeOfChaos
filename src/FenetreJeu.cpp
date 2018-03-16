#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../inclusion/FenetreJeu.h"
#include "../inclusion/ActionFenetreJeu.h"
#include <thread>
# if defined (__linux__)
# include "../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

FenetreJeu::FenetreJeu(Niveau niveau, std::vector<Unite*>* unites, std::vector<Batiment*>* batiments, Serveur* serveur) :
	longueurFenetre(1280), hauteurFenetre(768), nomFenetre("Edge Of Chaos"),
	sf::RenderWindow(sf::VideoMode(1280, 768), "Edge Of Chaos", sf::Style::Close),
	longueurGrille(20), hauteurGrille(9), tailleCase(64),
	hauteurPanneau(3), imagePanneau(Configuration::cheminTextures + "bois2.jpg"), niveau(niveau), carte(new Carte(Configuration::cheminTextures + "textures64.png", sf::Vector2u(tailleCase, tailleCase), niveau)),
	unites(unites), batiments(batiments),
	vueGrille(niveau, carte, longueurGrille, hauteurGrille, tailleCase), vueGenerale(niveau, carte, tailleCase),
	panneauBoisUnite(longueurGrille, hauteurPanneau, tailleCase, unites->front(), imagePanneau),
	panneauBoisBatiment(longueurGrille, hauteurPanneau, tailleCase, imagePanneau, batiments->front()),
	panneauBois(longueurGrille, hauteurPanneau, tailleCase, imagePanneau),
	serveur(serveur)
{
	this->jeuFerme = false;
	this->client = new std::thread(&FenetreJeu::communiquerAuServeur, this);
	this->uniteSelect = nullptr;
	this->batimentSelect = nullptr;
	this->estUnite = false;
	this->estBatiment= false;
	this->setView(vueGrille);
	estVueGrille = true;

	if (!textureCurseur.loadFromFile(Configuration::cheminTextures + "textures64.png", sf::IntRect(64*13, 0, 64, 64)))
		std::cerr << "Impossible de charger la texture du curseur. \n ( " << Configuration::cheminTextures + "textures64.png" << " )" << std::endl;
	spriteCurseur = sf::Sprite(textureCurseur);
	spriteCurseur.setPosition(0, 0);

	for (Unite* unite : *unites)
	{
		ajouterEntite(unite);
	}
	for (Batiment* batiment : *batiments)
	{
		ajouterEntite(batiment);
	}
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
			{
				if (serveur!=nullptr)
				{
					serveur->arreter();
				}
				this->close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::R)
				{
					if (estVueGrille)
					{
						estVueGrille = false;	// nom pas super super clair...
					}
					else
					{
						estVueGrille = true;
					}
					break;
				}
			}

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::D: case sf::Keyboard::Right:
					if (estVueGrille&&vueGrille.getCompteurLongueur() != (tailleCase*niveau.getLongueur()) - (tailleCase * 20))
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
					if (estVueGrille&&vueGrille.getCompteurHauteur() != (tailleCase*niveau.getHauteur()) - tailleCase*hauteurGrille)
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

				if (clicX < longueurFenetre && clicX > 0 && clicY < tailleCase*hauteurGrille && clicY > 0 && estVueGrille)
				{
					//Pour avoir les coordonnees du coin haut-gauche
					clicX = clicX - clicX % tailleCase;
					clicY = clicY - clicY % tailleCase;

					// Pour avoir les coordonnees absolues
					clicX += vueGrille.getCompteurLongueur();
					clicY += vueGrille.getCompteurHauteur();

					std::vector<int> positionSouris;
					positionSouris.push_back(clicX);
					positionSouris.push_back(clicY);

					if (event.mouseButton.button == sf::Mouse::Left)
					{
						ActionFenetreJeu action = ActionFenetreJeu();
						action.clicGauche(this, positionSouris);
					} else if (event.mouseButton.button == sf::Mouse::Right && uniteSelect != nullptr)
					{
						ActionFenetreJeu action = ActionFenetreJeu();
						action.clicDroit(this, positionSouris);
					}
				}
			}
		}

		this->clear(sf::Color::Black);

		//AFFICHER LA TILEMAP ET LE PANNEAU
		if (estVueGrille)
		{
			//Affichage de la carte, des entites et du curseur
			this->setView(vueGrille);
			this->draw(*carte);
			carte->dessinerEntites(*this);

			this->draw(spriteCurseur);

			//Affichage du panneauBois
			if (estUnite)
			{
				panneauBoisUnite.setUnite(uniteSelect); // !!!!! "uniteSelect" est à nullptr les 3/4 du temps!
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
			this->draw(*carte);
			carte->dessinerEntites(*this);

			this->draw(spriteCurseur);
		}
		this->display();
	}
}

void FenetreJeu::ajouterEntite(Entite* entite)
{
	carte->ajouterEntite(entite, entite->getPosition().at(0), entite->getPosition().at(1));
}

void FenetreJeu::deplacerEntite(Entite* entite, int nouvellePositionX, int nouvellePositionY)
{
	carte->deplacerEntite(entite->getPosition().at(0), entite->getPosition().at(1), nouvellePositionX, nouvellePositionY);

}

bool FenetreJeu::positionsEgales(std::vector<int> positionSouris, std::vector<int> positionEntite)
{
	if (positionSouris.at(0)==positionEntite.at(0)&&positionSouris.at(1)==positionEntite.at(1))
	{
		return true;
	}
	return false;
}

void FenetreJeu::communiquerAuServeur()
{
	while(!this->jeuFerme)
	{
		std::cout << "Code de communication au serveur. (dans FenetreJeu.cpp)..." << std::endl;
	}
}

void FenetreJeu::attendreFermeture()
{
	if(this->client->joinable())
	{
		this->client->join();
	}
}

FenetreJeu::~FenetreJeu()
{
	if(this->client != nullptr)
	{
		this->jeuFerme = true;
		this->attendreFermeture();
		delete this->client;
		this->client = nullptr;
	}
}
