#include <SFML/Graphics.hpp>
#include "../inclusion/menu.h"
#include "../inclusion/VueGrille.h"

int main()
{
	VueGrille vueGrille(20, 40, 64);
	vueGrille.boucleOpen();


	/*
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	sf::CircleShape shape(300.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(shape);
		window.display();
	}
	*/

	return 0;
}
