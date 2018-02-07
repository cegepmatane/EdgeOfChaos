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
	const int _XPOSITION = this->getSize().x / 4;
	const int _HAUTEUR_BTN = this->getSize().y / 6;
	const int _LONGUEUR_BTN = this->getSize().x / 2;
	
	if(!(this->policeBoutons.loadFromFile(chemin))){
		std::cerr << "Impossible de charger la police des boutons." << std::endl;
	}
	this->btnHeberger = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Heberger", this->policeBoutons);
	this->btnHeberger->setBtnPosition(_XPOSITION, 80);
	this->btnJoindre = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Joindre", this->policeBoutons);
	this->btnJoindre->setBtnPosition(_XPOSITION, 160);
	this->btnParametres = new Bouton(_LONGUEUR_BTN, _HAUTEUR_BTN, "Parametres", this->policeBoutons);
	this->btnParametres->setBtnPosition(_XPOSITION, 240);
}

Menu::Menu() : RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2), "Edge of Chaos", sf::Style::Default)
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
			this->draw(*(this->btnHeberger));
			this->draw(*(this->btnJoindre));
			this->draw(*(this->btnParametres));
			this->display();
		}
	}

}

void Menu::afficher(){
}

Menu::~Menu(){
	if(this->btnHeberger != nullptr){
		delete this->btnHeberger;
		this->btnHeberger = nullptr;
	}
	if(this->btnJoindre != nullptr){
		delete this->btnJoindre;
		this->btnJoindre = nullptr;
	}
	if(this->btnParametres != nullptr){
		delete this->btnParametres;
		this->btnParametres = nullptr;
	}
}
