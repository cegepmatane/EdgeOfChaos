#pragma once
#include "Menu.h"

class Menu;

class ActionMenu
{
public:
	ActionMenu();
	int cliquer(Menu* menu, int x, int y);
};