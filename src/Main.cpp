#include <SFML/Graphics.hpp>
#include "../inclusion/menu.h"
#include "../inclusion/VueGrille.h"
#include "../inclusion/vueGenerale.h"
#include "../inclusion/Unite.h"
#include "../inclusion/VuePanneauUnite.h"
#include "../inclusion/VuePanneauBatiment.h" 
#include "../inclusion/FenetreJeu.h"

int main()
{
	int longueurFenetre = 1280;
	int hauteurFenetre = 768;
	std::string nomFenetre = "Edge of Chaos";

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

	std::vector<Unite> listeUnites;
	std::vector<Batiment> listeBatiments;

	listeUnites.push_back(unite);
	listeBatiments.push_back(batiment);

	FenetreJeu fenetre(longueurFenetre, hauteurFenetre, nomFenetre, longueurGenerale, hauteurGenerale, longueurGrille, hauteurGrille,
		tailleCase, hauteurPanneau, niveau, imagePanneau, listeUnites, listeBatiments);
	
	fenetre.lancerBoucle();

	return 0;
}
