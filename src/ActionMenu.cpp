#include "../inclusion/ActionMenu.h"
#include <vector>

ActionMenu::ActionMenu()
{
}

void ActionMenu::cliquer(Menu* menu, int x, int y)
{
	int hauteurHeberger = menu->getHeberger().getDimensions().at(0);
	int longueurHeberger = menu->getHeberger().getDimensions().at(1);
	int hauteurJoindre = menu->getJoindre().getDimensions().at(0);
	int longueurJoindre = menu->getJoindre().getDimensions().at(1);

	if (x < menu->getHebergerPosition().at(0)+hauteurHeberger && x > menu->getHebergerPosition().at(0)
		&& y < menu->getHebergerPosition().at(1)+longueurHeberger && y > menu->getHebergerPosition().at(1))
	{
		std::cout << "Heberger" << std::endl;
		// action.heberger(this, positionSouris);
	}

	if (x < menu->getJoindrePosition().at(0)+hauteurJoindre && x > menu->getJoindrePosition().at(0)
		&& y < menu->getJoindrePosition().at(0)+longueurJoindre && y > menu->getJoindrePosition().at(0))
	{
		std::cout << "Joindre" << std::endl;
		// action.joindre(this, positionSouris);
	}
}
