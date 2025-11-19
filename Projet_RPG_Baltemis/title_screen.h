#pragma once

#include "tools.h"

extern sfSprite* sTitleScreen;
extern sfRectangleShape* StartButton;
extern sfRectangleShape* EditorButton;
extern sfRectangleShape* OptionsButton;
extern sfRectangleShape* QuitButton;

void initTitleScreen();
void displayTitleScreen(sfRenderWindow* _window);