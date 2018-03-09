#pragma once
#include "Menu.h"

class Menu;

class ActionMenu
{
public:
	ActionMenu();
	void cliquer(Menu* menu, int x, int y);
};