#pragma once

#include "tools.h"

sfSprite* sTitleScreen;
sfRectangleShape* StartButton;
sfRectangleShape* EditorButton;
sfRectangleShape* QuitButton;

void initTitleScreen();
void displayTitleScreen(sfRenderWindow* _window);