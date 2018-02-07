#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "../../inclusion/menu.h"
#include "../../inclusion/bouton.h"


void Menu::initFenetre(){
	this->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2 - sf::VideoMode::getDesktopMode().height / 4));
	this->setVerticalSyncEnabled(true);
}

void Menu::initTitre(const std::string& chemin){
	if(!(this->policeTitre.loadFromFile(chemin))){
		std::cerr << "Impossible de charger la police du titre." << std::endl;
	}
	this->titre.setFont(this->policeTitre);
	this->titre.setString("Edge Of Chaos");
	this->titre.setCharacterSize(35);
	this->titre.setFillColor(sf::Color::Black);
	this->titre.setPosition(10, 10);
}

void Menu::initBoutons(const std::string& chemin){
	const int _XPOSITION = this->getSize().x * (4 / 9.0) / 2 ;	// Somme des des fractions doit être égale
	const int _HAUTEUR_BTN = this->getSize().y / 6;			// à 1.
	const int _LONGUEUR_BTN = this->getSize().x * (5 / 9.0);
	
	if(!(this->policeBoutons.loadFromFile(chemin))){
		std::cerr << "Impossible de charger la police des boutons." << std::endl;
	}
	this->actionHeberger = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Heberger", this->policeBoutons);
	this->actionHeberger->setBtnPosition(_XPOSITION, 80);
	this->actionJoindre = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Joindre", this->policeBoutons);
	this->actionJoindre->setBtnPosition(_XPOSITION, 160);
	this->actionParametres = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Parametres", this->policeBoutons);
	this->actionParametres->setBtnPosition(_XPOSITION, 240);
}

Menu::Menu() : RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2), "Edge of Chaos", sf::Style::Close)
{
	const std::string cheminPoliceTitre("../../ressources/polices/fraktur-bt.ttf");
	const std::string cheminPoliceBoutons("../../ressources/polices/urw-chancery-l-medium-Menus.ttf");

	initFenetre();
	initTitre(cheminPoliceTitre);
	initBoutons(cheminPoliceBoutons);

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

void Menu::afficher(){
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
