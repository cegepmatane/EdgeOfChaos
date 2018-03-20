#include "../../inclusion/Niveau.h"

Niveau::Niveau(int hauteur, int longueur, short int* cases) :
hauteur(hauteur), longueur(longueur), cases(cases)
{
}

short Niveau::getValeurCase(int x, int y)
{
	return cases[longueur*y + x];
}
