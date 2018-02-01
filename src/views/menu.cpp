#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"

Menu::Menu() : RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2), "Edge of Chaos", sf::Style::Default)
{
	const int _OUTLINE = 2;
	const int _XPOSITION = this->getSize().x / 2 - this->getSize().x / 4;
	this->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2 - sf::VideoMode::getDesktopMode().height / 4));
	this->setVerticalSyncEnabled(true);

	this->btnHeberger.setSize(sf::Vector2f(this->getSize().x / 2 - _OUTLINE * 2, this->getSize().y / 2 - _OUTLINE * 2));
	this->btnHeberger.setOutlineThickness(_OUTLINE);
	this->btnHeberger.setOutlineColor(sf::Color::Black);
	this->btnHeberger.setPosition(_XPOSITION, 50);

	while(this->isOpen()){
		sf::Event event;

		while(this->pollEvent(event)){
			if(event.type == sf::Event::Closed){
				this->close();
			}
			this->clear(sf::Color::Yellow);
			this->draw(btnHeberger);
			this->display();
		}
	}

}

void Menu::afficher(){
}
