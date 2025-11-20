#pragma once

#include "tools.h"
#include "editor.h"

extern sfView* g_viewGame;

void initView();
void updateView(sfRenderWindow* _window);
void displayView(sfRenderWindow* _window);
void displayEditorView(sfRenderWindow* _window);

