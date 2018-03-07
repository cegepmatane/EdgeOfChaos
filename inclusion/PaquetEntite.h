#pragma once
#include "SFML/Network.hpp"
#include "Entite.h"


class PaquetEntite : public sf::Packet
{
public:
	Packet& operator<<(Entite entite);
	Packet& operator>>(Entite entite);
};