#include "../inclusion/ActionFenetreJeu.h"

ActionFenetreJeu::ActionFenetreJeu()
{
}

void ActionFenetreJeu::clicGauche(FenetreJeu* fenetre, std::vector<int> positionSouris)
{
	fenetre->setEstUnite(false);
	fenetre->setEstBatiment(false);
	fenetre->setUniteSelect (nullptr);
	fenetre->setBatimentSelect (nullptr);

	fenetre->getSpriteCurseur()->setPosition(positionSouris.at(0), positionSouris.at(1));

	for (Unite* unite : *fenetre->getUnites())
	{
		if (fenetre->positionsEgales(positionSouris, unite->getPosition()))
		{
			fenetre->setEstUnite(true);
			fenetre->setUniteSelect(unite);	// après le for, "unite" est désalloué,
											// donc "uniteSelect" pointe dans le vide.
			fenetre->getPanneauBoisUnite()->mettreAJourTexte(unite);
		}
	}
	if (!fenetre->getEstUnite())
	{
		for (Batiment* batiment : *fenetre->getBatiments())
		{
			if (fenetre->positionsEgales(positionSouris, batiment->getPosition()))
			{
				fenetre->setEstBatiment(true);
				fenetre->setBatimentSelect(batiment);	// idem
				fenetre->getPanneauBoisBatiment()->mettreAJourTexte(batiment);
			}
		}
	}
}

void ActionFenetreJeu::clicDroit(FenetreJeu* fenetre, std::vector<int> positionSouris)
{
	// Verification du contenu de la case cliquee
	bool caseOccupee = false;
	for (Unite* unite : *fenetre->getUnites())
	{
		if (fenetre->positionsEgales(positionSouris, unite->getPosition()))
		{
			caseOccupee = true;
		}
	}
	if (!caseOccupee) {
		for (Batiment* batiment : *fenetre->getBatiments())
		{
			if (fenetre->positionsEgales(positionSouris, batiment->getPosition()))
			{
				caseOccupee = true;
			}
		}
	}

	// Vérifier que non montagne (2) et non eau (1)
	if (!caseOccupee)
	{
		int x = positionSouris.at(0);
		int y = positionSouris.at(1);
		if (positionSouris.at(0)!=0)
		{
			x = positionSouris.at(0) / 64;
		}
		if (positionSouris.at(1) != 0)
		{
			y = positionSouris.at(1) / 64;
		}
		int numeroCase = fenetre->getNiveau()->getValeurCase(x, y);
		if (numeroCase==2 || numeroCase==1)
		{
			caseOccupee = true;
		}
	}


	// Mettre l'unite sur la case cliquee
	if (!caseOccupee)
	{
		fenetre->deplacerEntite(fenetre->getUniteSelect(), positionSouris.at(0), positionSouris.at(1));

		fenetre->getUniteSelect()->setPosition(positionSouris.at(0), positionSouris.at(1));

		fenetre->getSpriteCurseur()->setPosition(positionSouris.at(0), positionSouris.at(1));



		/* Envoyer infos au reseau :
		 * *(fenetre->getUniteSelect())
		 * positionSouris.at(0)
		 * positionSouris.at(1)
		 * Le reseau se chargera de faire les paquets et de les envoyer
		 */
	}
}
