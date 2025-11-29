#pragma once

#include "tools.h"
#include "editor.h"
#include "collisions.h"
#include "player.h"

//tileset des objets a animer
typedef struct Objects
{
	sfSprite* spObj;
	sfTexture* texObj;
	sfIntRect irectObj;
	sfVector2f posObj;
	sfVector2f animObj[mapSizeY][mapSizeX];
	sfVector2i buttonPos;
	int frameObjX;
	int frameObjY;

}Objects;
Objects obj;

//fonctions
void initAnims();
void updateAnims();
void displayAnims(sfRenderWindow* window);

void trap_anims(sfIntRect _irect);
void activated_trap();
void not_activated_trap();

extern int g_ActivateTrap;
extern int g_DesactivateTrap;