#include <iostream>
#include <string>
#include <thread>
#include "../inclusion/Menu.h"
#include "../inclusion/Unite.h"
#include "../inclusion/Batiment.h"
#include "../inclusion/Niveau.h"
# if defined (__linux__)
# include "../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

int main(void)
{
#define tailleCase 64

	// Definitions des mesures

	int hauteurNiveau = 20;
	int longueurNiveau = 40;

	short int casesNiveau[] =
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

	Niveau niveau(hauteurNiveau, longueurNiveau, casesNiveau);

	// Declaration des unites et batiments

	int attaque = 10;
	std::vector<std::string> listeAttaques;
	listeAttaques.push_back("Charge");
	listeAttaques.push_back("Chun chun maru!");
	Unite unite(100, 100, attaque, tailleCase * 1, tailleCase * 1, 12, listeAttaques);
	Unite* unitePtr = &unite;
	
	/*Unite unite2("Test2", 100, tailleCase * 3, tailleCase * 3, 200, 50, listeAttaques);
	unite2.setImage(Configuration::cheminTextures + "textures64.png");
	unite2.setNumTexture(12);
	Unite* unite2Ptr = &unite2;*/

	std::vector<std::string> optionsBatiment;
	optionsBatiment.push_back("Créer un lancier");
	optionsBatiment.push_back("Créer un homme d'arme");
	Batiment batiment(100, 100, tailleCase * 2, tailleCase * 2, 10, optionsBatiment);
	Batiment* batimentPtr = &batiment;

	std::vector<Unite*> unites;
	std::vector<Batiment*> batiments;

	unites.push_back(unitePtr);
	//unites.push_back(unite2Ptr);
	batiments.push_back(batimentPtr);

	Menu menu;
	bool estConnecte = true;
	std::string tst = "Pas de connexion reseau.";

	while(menu.isOpen())
	{
		sf::Event event;
		while(menu.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				// Inclusion de l'initialisation du jeu ici
				menu.initJeu(niveau, unites, batiments);
			}

			menu.clear(sf::Color::Yellow);
			menu.afficher();
			if(!estConnecte){
				menu.lancerErreur(tst);
			}
			menu.display();
		}
	}

	return 0;
}
