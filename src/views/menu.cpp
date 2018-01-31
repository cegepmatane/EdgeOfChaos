#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"

Menu::Menu() : RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 3, sf::VideoMode::getDesktopMode().height / 2), "Edge of Chaos", sf::Style::Default)
{
	this->setVerticalSyncEnabled(true);
	while(this->isOpen()){
		sf::Event event;

		while(this->pollEvent(event)){
			if(event.type == sf::Event::Closed){
				this->close();
			}
			this->clear(sf::Color::Yellow);
			this->display();
		}
	}

}

void Menu::afficher(){
}
