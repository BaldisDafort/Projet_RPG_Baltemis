#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include <time.h>
#include "title_screen.h"
#include "sound.h"

extern sfVector2i g_mousePixelPos;
extern sfVector2f g_mouseWorldPos;

typedef enum { MENU, GAME, EDITOR, OPTION, QUIT }State;
State state;

void initTools();
void restartClock();
float GetDeltaTime();

