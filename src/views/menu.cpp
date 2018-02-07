#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "../../inclusion/menu.h"
#include "../../inclusion/bouton.h"


Menu::Menu() : RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2), "Edge of Chaos", sf::Style::Close)
{
	const std::string cheminPoliceTitre("../../ressources/polices/fraktur-bt.ttf");
	const std::string cheminPoliceBoutons("../../ressources/polices/urw-chancery-l-medium-Menus.ttf");
	const double dimensionBoutons = 5 / 9.0;

	initFenetre();
	initTitre(cheminPoliceTitre);
	initBoutons(cheminPoliceBoutons, dimensionBoutons);

	while(this->isOpen()){
		sf::Event event;
		//sf::Event ;

		while(this->pollEvent(event)){
			if(event.type == sf::Event::Closed)
			{
				this->close();
			}
			/*if(sf::Mouse::getposition(*this).x > )
			{
			}*/
			this->clear(sf::Color::Yellow);
			this->draw(this->titre);
			this->draw(*(this->actionHeberger));
			this->draw(*(this->actionJoindre));
			this->draw(*(this->actionParametres));
			this->display();
		}
	}
}

Bouton Menu::getHeberger(){
	return *(this->actionHeberger);
}

Bouton Menu::getJoindre(){
	return *(this->actionJoindre);
}

Bouton Menu::getParametres(){
	return *(this->actionParametres);
}

Menu::~Menu(){
	if(this->actionHeberger != nullptr){
		delete this->actionHeberger;
		this->actionHeberger = nullptr;
	}
	if(this->actionJoindre != nullptr){
		delete this->actionJoindre;
		this->actionJoindre = nullptr;
	}
	if(this->actionParametres != nullptr){
		delete this->actionParametres;
		this->actionParametres = nullptr;
	}
}

void Menu::initFenetre(){
	this->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2 - sf::VideoMode::getDesktopMode().height / 4));
	this->setVerticalSyncEnabled(true);
}

void Menu::initTitre(const std::string& cheminPolice){
	if(!(this->policeTitre.loadFromFile(cheminPolice))){
		std::cerr << "Impossible de charger la police du titre." << std::endl;
	}
	this->titre.setFont(this->policeTitre);
	this->titre.setString("Edge Of Chaos");
	this->titre.setCharacterSize(35);
	this->titre.setFillColor(sf::Color::Black);
	this->titre.setPosition(this->getSize().x / 2 - this->getSize().x / 4, 10);
}

void Menu::initBoutons(const std::string& cheminPolice, const double proportion){
	this->positionXBoutons = this->getSize().x * (1 - proportion) / 2 ;	// Somme des des fractions doit être égale à 1.
	this->offsetYBoutons = this->titre.getCharacterSize() + this->titre.getPosition().y;
	this->espacementBoutons = 20;
	
	const int _HAUTEUR = this->getSize().y / 6;	
	const int _LONGUEUR = this->getSize().x * proportion;
	
	this->actionHeberger = new Bouton(_LONGUEUR, _HAUTEUR, "Heberger", cheminPolice);
	this->actionHeberger->setBtnPosition(this->positionXBoutons, this->offsetYBoutons + 50 + (_HAUTEUR + this->espacementBoutons) * 0);
	this->actionJoindre = new Bouton(_LONGUEUR, _HAUTEUR, "Joindre", cheminPolice);
	this->actionJoindre->setBtnPosition(this->positionXBoutons, this->offsetYBoutons + 50 + (_HAUTEUR + this->espacementBoutons) * 1);
	this->actionParametres = new Bouton(_LONGUEUR, _HAUTEUR, "Parametres", cheminPolice);
	this->actionParametres->setBtnPosition(this->positionXBoutons, this->offsetYBoutons + 50 + (_HAUTEUR + this->espacementBoutons) * 2);
}
