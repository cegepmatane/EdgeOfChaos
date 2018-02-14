#include <iostream>
#include <string>

#include "../inclusion/menu.h"


int main(void)
{
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
				menu.initJeu();
				// // // // // // //
				menu.close();
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
