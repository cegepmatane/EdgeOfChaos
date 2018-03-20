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

// Preuve de concept de parsing avec pugiXML

/*#include "../lib/pugixml-1.8/src/pugixml.cpp"
#include <SFML/Network.hpp>
#include <string>
#include <sstream>
#include <iostream>

struct xml_string_writer : pugi::xml_writer
{
	std::string result;

	virtual void write(const void* data, size_t size)
	{
		result.append(static_cast<const char*>(data), size);
	}
};

int main(void)
{
	pugi::xml_document doc;
	pugi::xml_node ip = doc.append_child("test").append_child("reseau").append_child("adresse");;
	pugi::xml_node machine = doc.child("test").child("reseau").append_child("machine");
	machine.text().set("Debian");
	ip.append_attribute("ip").set_value("localhost");
	std::stringstream test;
	if (ip)
	{
		doc.print(test);
		std::cout << test.str() << std::endl;
	}
	std::string reseau = test.str();
	pugi::xml_document aze;
	pugi::xml_parse_result tst = aze.load_string(reseau.c_str());
	std::cout << aze.child("test").child("reseau").child("machine").child_value() << std::endl;
	std::cout << aze.child("test").child("reseau").child("adresse").attribute("ip").value() << std::endl;


	return 0;
}

// g++ -g main.cpp -o exec.exe -L/usr/include -lpugixml
*/

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
	Unite unite(100, 100, attaque, TAILLECASE * 1, TAILLECASE * 1, 11, listeAttaques);
	
	std::vector<std::string> listeAttaques2;
	listeAttaques2.push_back("Attaque eclair");
	listeAttaques2.push_back("Explosionnnnn!");
	Unite unite2(200, 20, 20, TAILLECASE * 3, TAILLECASE * 3, 12, listeAttaques2);

	std::vector<std::string> optionsBatiment;
	optionsBatiment.push_back("Creer un lancier");
	optionsBatiment.push_back("Creer un homme d'arme");
	Batiment batiment(100, 100, TAILLECASE * 2, TAILLECASE * 2, 9, optionsBatiment);

	/*std::vector<std::string> optionsBatiment2;
	optionsBatiment2.push_back("Soin");
	Batiment batiment2(100, 100, TAILLECASE * 0, TAILLECASE * 0, 13, optionsBatiment2);*/

	std::vector<Unite*>* unites = new std::vector<Unite*>;
	std::vector<Batiment*>* batiments = new std::vector<Batiment*>;

	unites->push_back(&unite);
	unites->push_back(&unite2);
	batiments->push_back(&batiment);
	//batiments->push_back(&batiment2);

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
