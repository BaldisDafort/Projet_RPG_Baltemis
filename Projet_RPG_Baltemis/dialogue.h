#pragma once

#include "tools.h"
#include "collisions.h"

//bat
typedef struct Dialogue
{
	sfSprite* spPnjPortrait;
	sfTexture* texPnjPortrait;
	sfSprite* spSkeletonPortrait;
	sfTexture* texSkeletonPortait;
	sfSprite* spDial;
	sfTexture* texDial;
	sfFloatRect portraitRect;
	sfFloatRect dialRect;

}Dialogue;
Dialogue dial;

void initDialogue();
void displayDialogue(sfRenderWindow* _window);
