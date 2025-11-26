#pragma once

#include "tools.h"
#include "editor.h"

extern sfView* g_viewGame;

void initView();
void updateView(sfRenderWindow* _window);
void displayView(sfRenderWindow* _window);
void displaySkeletonView(sfRenderWindow* _window);
void displayBatView(sfRenderWindow* _window);


