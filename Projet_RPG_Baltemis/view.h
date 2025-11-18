#pragma once

#include "tools.h"
#include "editor.h"

void initView();
void updateView(sfRenderWindow* _window);
void displayView(sfRenderWindow* _window);

sfView* view;
sfView* viewChoice;