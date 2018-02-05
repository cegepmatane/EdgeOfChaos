#include <SFML/Graphics.hpp>
#include "../inclusion/menu.h"
#include "../inclusion/VueGrille.h"

int main()
{
	VueGrille vueGrille(600, 600, 256);

	/*sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	sf::CircleShape shape(300.f);
	shape.setFillColor(sf::Color::Green);

	sf::View view(sf::FloatRect(200, 200, 200, 200));
	bool isView = false;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type ==sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::R:
					if (isView)
					{
						window.setView(window.getDefaultView());
						isView = false;
					} else
					{
						window.setView(view);
						isView = true;
					}
					break;
				case sf::Keyboard::D:
					if (isView)
					{
						view.move(50, 0);
						window.setView(view);
					}
					break;
				case sf::Keyboard::Z:
					if (isView)
					{
						view.move(0, -50);
						window.setView(view);
					}
					break;
				case sf::Keyboard::S:
					if (isView)
					{
						view.move(0, 50);
						window.setView(view);
					}
					break;
				case sf::Keyboard::Q:
					if (isView)
					{
						view.move(-50, 0);
						window.setView(view);
					}
					break;
				}
			}

		}

		window.clear(sf::Color::White);
		window.draw(shape);
		window.display();
	}*/

	return 0;
}
