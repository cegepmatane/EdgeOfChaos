#pragma once

class Niveau
{
private:
	int hauteur;
	int longueur;
	short int* cases;
public:
	Niveau(int hauteur, int longueur, short int* cases);
	int getHauteur() { return this->hauteur; }
	int getLongueur() { return this->longueur; }
	short int* getCases() { return this->cases; }
	short int getValeurCase(int x, int y);
};