#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../../inclusion/Entite.h"

class Unite : public Entite
{
public:
	Unite(std::string nom, int pdv, sf::Vector2u position);
};
