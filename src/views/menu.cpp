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

		while(this->pollEvent(event)){
			if(event.type == sf::Event::Closed){
				this->close();
			}
			this->clear(sf::Color::Yellow);
			this->draw(this->titre);
			this->draw(*(this->actionHeberger));
			this->draw(*(this->actionJoindre));
			this->draw(*(this->actionParametres));
			this->display();
		}
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
	const int _XPOSITION = this->getSize().x * (1 - proportion) / 2 ;	// Somme des des fractions doit être égale à 1.
	const int _YOFFSET_POSITION = this->titre.getCharacterSize() + this->titre.getPosition().y;
	const int _ESPACEMENT = 20;
	
	const int _HAUTEUR_BTN = this->getSize().y / 6;	
	const int _LONGUEUR_BTN = this->getSize().x * proportion;
	
	//if(!(this->policeBoutons.loadFromFile(cheminPolice))){
	//	std::cerr << "Impossible de charger la police des boutons." << std::endl;
	//}
	this->actionHeberger = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Heberger", cheminPolice);
	this->actionHeberger->setBtnPosition(_XPOSITION, _YOFFSET_POSITION + 50 + (_HAUTEUR_BTN + _ESPACEMENT) * 0);
	this->actionJoindre = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Joindre", cheminPolice);
	this->actionJoindre->setBtnPosition(_XPOSITION, _YOFFSET_POSITION + 50 + (_HAUTEUR_BTN + _ESPACEMENT) * 1);
	this->actionParametres = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Parametres", cheminPolice);
	this->actionParametres->setBtnPosition(_XPOSITION, _YOFFSET_POSITION + 50 + (_HAUTEUR_BTN + _ESPACEMENT) * 2);
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
