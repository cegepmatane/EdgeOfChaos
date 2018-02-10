#pragma once
#include <SFML/Graphics.hpp>
#include "vuePanneau.h"
#include "Unite.h"

class VuePanneauUnite : public VuePanneau
{
private:
	Unite uniteSprite;

public:
	VuePanneauUnite(int longueurPanneau, int hauteurPanneau, int tailleCase, std::string image, Unite unite);
	Unite getUniteSprite() { return uniteSprite; }

	void setUniteSprite(Unite unite) { uniteSprite = unite; }
};
