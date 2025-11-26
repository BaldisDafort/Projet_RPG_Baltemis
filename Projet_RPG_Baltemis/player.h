#pragma once
#include "tools.h"

//directions
typedef enum BatDirection batDir;
enum Direction
{
	B_BAS = 0,
	B_HAUT,
	B_DROITE,
	B_GAUCHE
};
//skeleton
typedef enum SkeletonDirection skeletonDir;
enum SkeletonDirection
{
	SK_BAS = 0,
	SK_HAUT = 2,
	SK_DROITE = 4,
	SK_GAUCHE = 6
};

//structures des players
//bat
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

//skeleton
typedef struct SkeletonPlayer
{
	sfBool skeletonIsMoving;
	sfBool skeletonIsIdle;
	sfSprite* spSkeleton;
	sfTexture* texSkeleton;
	sfFloatRect playerRect;
	sfIntRect irectSkeleton;
	sfVector2f SpritePositionSkeleton;
	sfVector2f vitesse;
	float animSkeletonTime;
	float timerSkeleton;
	float animSkeletonSpeed;
	int frameSkeletonX;
	int frameSkeletonY;

}SkeletonPlayer;
SkeletonPlayer skeleton;

//etat des players
sfBool batIsMoving;
sfBool skeletonIsMoving;

//fonctions
void initPlayer();
void updatePlayer();
void displayPlayer(sfRenderWindow* window);

