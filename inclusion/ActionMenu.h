#pragma once
#include "Menu.h"

class Menu;

class ActionMenu
{
public:
	ActionMenu();
	bool cliquer(Menu* menu, int x, int y);
};