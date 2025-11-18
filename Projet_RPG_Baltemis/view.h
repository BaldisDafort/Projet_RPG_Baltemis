#pragma once

#include "tools.h"
#include "editor.h"

void initView();
void updateView(sfRenderWindow* _window);
void displayView(sfRenderWindow* _window);
void displayEditorView(sfRenderWindow* _window);

sfView* viewEditor;
sfView* view;