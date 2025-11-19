#pragma once

#include "tools.h"

extern sfRectangleShape* g_DisplayOptions;
extern sfRectangleShape* g_GeneralSoundButton_IsMuted;
extern sfRectangleShape* g_SFXSoundButton_IsMuted;

void initOptions();
void displayOptions(sfRenderWindow* _window);