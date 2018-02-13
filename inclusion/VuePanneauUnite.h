#pragma once
#include <SFML/Graphics.hpp>
#include "vuePanneau.h"
#include "Unite.h"
#include <string>

class VuePanneauUnite : public VuePanneau
{
private:
	Unite* unite;
	sf::Text titreStats;
	sf::Text titrePoints;
	sf::Text titreAttaques;
	sf::Font fonte;

public:
	VuePanneauUnite(int longueurPanneau, int hauteurPanneau, int tailleCase, Unite* unite, std::string image);
	
	sf::Text getTitreStats() { return titreStats; }
	sf::Text getTitrePoints() { return titrePoints; }
	sf::Text getTitreAttaques() { return titreAttaques; }
	sf::Font getFonte() { return fonte; }

	void setTitreStats(std::string titre) { this->titreStats.setString(titre); }
	void setTitrePoints(std::string titre) { this->titrePoints.setString(titre); }
	void setTitreAttaques(std::string titre) { this->titreAttaques.setString(titre); }

	void initialiser();
	void dessiner(sf::RenderTarget &cible);
	void mettreAJourTexte();
};
