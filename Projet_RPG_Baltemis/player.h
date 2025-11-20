#pragma once
#include "tools.h"

typedef enum Direction Direction;
enum Direction
{
	BAS = 0,
	DROITE,
	GAUCHE,
	HAUT
};
int frameY;
sfVector2f vitesse;
sfBool isMoving;

void initPlayer();
void updatePlayer();
void displayPlayer(sfRenderWindow* window);

