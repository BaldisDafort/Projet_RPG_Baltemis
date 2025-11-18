#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include <time.h>
#include "title_screen.h"

typedef enum { MENU, GAME, EDITOR }State;
State state;

void initTools();
void restartClock();
float GetDeltaTime();

