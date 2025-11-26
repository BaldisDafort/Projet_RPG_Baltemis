#pragma once

#include "tools.h"
#include "view.h"

extern sfSprite* sTitleScreen;
extern sfRectangleShape* StartButton;
extern sfRectangleShape* EditorButton;
extern sfRectangleShape* OptionsButton;
extern sfRectangleShape* QuitButton;

void initTitleScreen();
void updateTitleScreen(sfRenderWindow* _window);
void displayTitleScreen(sfRenderWindow* _window);