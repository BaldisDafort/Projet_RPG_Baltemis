#pragma once
#include "tools.h"

typedef enum Direction Direction;
enum Direction
{
	BAS = 0,
	HAUT,
	DROITE,
	GAUCHE
};

typedef struct BatPlayer
{
	sfBool batIsMoving;
	sfSprite* spBat;
	sfTexture* texBat;
	sfFloatRect playerRect;
	sfIntRect irectBat;
	sfVector2f SpritePositionBat;
	sfVector2f vitesse;
	float animBatTime;
	float timerBat;
	float animBatSpeed;
	int frameBatX;
	int frameBatY;

}BatPlayer;
BatPlayer bat;

sfBool batIsMoving;

void initPlayer();
void updatePlayer();
void displayPlayer(sfRenderWindow* window);

