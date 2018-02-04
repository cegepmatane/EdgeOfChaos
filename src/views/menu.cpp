#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../inclusion/menu.h"
#include "../../inclusion/bouton.h"

Menu::Menu() : RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2), "Edge of Chaos", sf::Style::Default)
{
	const int _OUTLINE = 2;
	const int _XPOSITION = this->getSize().x / 4 + _OUTLINE;
	//std::cout << sf::VideoMode::getDesktopMode().width << " / " << sf::VideoMode::getDesktopMode().height << std::endl;

	this->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2 - sf::VideoMode::getDesktopMode().height / 4));
	this->setVerticalSyncEnabled(true);

	sf::Font policeTitre;
	if(!policeTitre.loadFromFile("../../ressources/polices/urw-chancery-l-medium-Menus.ttf")){
		std::cerr << "Impossible de charger la police du titre." << std::endl;
	}
	this->titre.setFont(policeTitre);
	this->titre.setString("Edge Of Chaos");
	this->titre.setCharacterSize(35);
	this->titre.setFillColor(sf::Color::Black);
	this->titre.setPosition(10, 10);


	this->btnHeberger = nullptr;
	this->btnJoindre = nullptr;
	this->btnParametres = nullptr;


	std::string test("azerty");

	this->btnHeberger = new Bouton(this->getSize().x / 2 - _OUTLINE * 2, this->getSize().y / 6 - _OUTLINE * 2, test, policeTitre);
	//this->btnHeberger->setPosition(_XPOSITION, 80);
	/*this->btnHeberger.setSize(sf::Vector2f(this->getSize().x / 2 - _OUTLINE * 2, this->getSize().y / 6 - _OUTLINE * 2));
	this->btnHeberger.setOutlineThickness(_OUTLINE);
	this->btnHeberger.setOutlineColor(sf::Color::Black);
	this->btnHeberger.setPosition(_XPOSITION, 80);*/

	while(this->isOpen()){
		sf::Event event;

		while(this->pollEvent(event)){
			if(event.type == sf::Event::Closed){
				this->close();
			}
			this->clear(sf::Color::Yellow);
			this->draw(this->titre);
			this->draw(*(this->btnHeberger));
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
