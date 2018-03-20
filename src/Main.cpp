#include <iostream>
#include <string>
#include <thread>
#include "../inclusion/Menu.h"
#include "../inclusion/Unite.h"
#include "../inclusion/Batiment.h"
#include "../inclusion/Niveau.h"
#include "../inclusion/ActionMenu.h"
# if defined (__linux__)
# include "../systemes/interfaceDebian.h"
# elif defined (_WIN32) || (_WIN64)
# include "../../systemes/interfaceWindows.h"
# endif

int main(void)
{
#define TAILLECASE 64

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
	Unite unite(100, 100, attaque, TAILLECASE * 1, TAILLECASE * 1, 10, listeAttaques);
	//Unite* unitePtr = &unite;
	
	/*Unite unite2(200, 20, 20, TAILLECASE * 3, TAILLECASE * 3, 10, listeAttaques);
	Unite* unite2Ptr = &unite2;*/

	std::vector<std::string> optionsBatiment;
	optionsBatiment.push_back("Creer un lancier");
	optionsBatiment.push_back("Creer un homme d'arme");
	Batiment batiment(100, 100, TAILLECASE * 2, TAILLECASE * 2, 9, optionsBatiment);
	//Batiment* batimentPtr = &batiment;

	std::vector<Unite*>* unites = new std::vector<Unite*>;
	std::vector<Batiment*>* batiments = new std::vector<Batiment*>;

	unites->push_back(&unite);
	//unites.push_back(unite2Ptr);
	batiments->push_back(&batiment);

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
				menu.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				int clicX = sf::Mouse::getPosition(menu).x;
				int clicY = sf::Mouse::getPosition(menu).y;
				ActionMenu action = ActionMenu();
				switch (action.cliquer(&menu, clicX, clicY))
				{
				case 1: menu.initJeu(niveau, unites, batiments, true);
					break;
				case 2: menu.initJeu(niveau, unites, batiments);
					break;
				}
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
