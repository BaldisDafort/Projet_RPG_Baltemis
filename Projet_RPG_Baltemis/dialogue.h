#pragma once

#include "tools.h"
#include "collisions.h"

//bat
typedef struct Dialogue
{
	sfSprite* spPnjPortrait;
	sfTexture* texPnjPortrait;
	sfSprite* spSkeletonPortrait;
	sfTexture* texSkeletonPortrait;
	sfVector2f portraitPos;
	sfSprite* spDial;
	sfTexture* texDial;
	sfVector2f dialoguePos;
	sfVector2f dialSize;
	sfFloatRect portraitRect;
	sfFloatRect dialRect;
	int isTalking;
	int chest;
	float talkingTimer;

}Dialogue;
Dialogue dial;

void initDialogue();
void updateDialogue();
void displayDialogue(sfRenderWindow* _window);
