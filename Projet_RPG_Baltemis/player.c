#include "player.h"

State state = GAME;
void setPlayerPositions()
{
	bat.SpritePositionBat = (sfVector2f){ posBaseBat.x * tileSize, posBaseBat.y * tileSize };
	skeleton.SpritePositionSkeleton = (sfVector2f){ posBaseSkeleton.x * tileSize, posBaseSkeleton.y * tileSize };
}


void initPlayer()
{
	//init bat player
	bat.batIsMoving = sfFalse;
	bat.irectBat = (sfIntRect){ 0, 0, 16, 16 };
	bat.vitesse = (sfVector2f){ 100.0f, 100.0f };
	bat.animBatTime = 0.0f;
	bat.timerBat = 0.0f;
	bat.animBatSpeed = 0.13f;
	bat.frameBatX = 0;
	bat.frameBatY = 0;

	//init skeleton player
	skeleton.skeletonIsMoving = sfFalse;
	skeleton.skeletonIsIdle = sfFalse;
	skeleton.irectSkeleton = (sfIntRect){ 0, 0, 16, 16 };
	skeleton.vitesse = (sfVector2f){ 80.0f, 80.0f };
	skeleton.animSkeletonTime = 0.0f;
	skeleton.timerSkeleton = 0.0f;
	skeleton.animSkeletonSpeed = 0.20f;
	skeleton.frameSkeletonX = 0;
	skeleton.frameSkeletonY = 0;


	//create bat player sprite
	bat.spBat = sfSprite_create();
	bat.texBat = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetbat.png", NULL);
	sfSprite_setTexture(bat.spBat, bat.texBat, sfTrue);
	sfSprite_setTextureRect(bat.spBat, bat.irectBat);
	sfSprite_setPosition(bat.spBat, bat.SpritePositionBat);

	//create skeleton player sprite
	skeleton.spSkeleton = sfSprite_create();
	skeleton.texSkeleton = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetskeleton.png", NULL);
	sfSprite_setTexture(skeleton.spSkeleton, skeleton.texSkeleton, sfTrue);
	sfSprite_setTextureRect(skeleton.spSkeleton, skeleton.irectSkeleton);
	sfSprite_setPosition(skeleton.spSkeleton, skeleton.SpritePositionSkeleton);

	//create shadow sprite
	//skeleton
	skeleton.spShadow = sfSprite_create();
	skeleton.texShadow = sfTexture_createFromFile("..\\Resources\\Textures\\shadow.png", NULL);
	sfSprite_setTexture(skeleton.spShadow, skeleton.texShadow, sfTrue);
	sfSprite_setPosition(skeleton.spShadow, skeleton.SpritePositionSkeleton);
	//bat
	bat.spShadow = sfSprite_create();
	bat.texShadow = sfTexture_createFromFile("..\\Resources\\Textures\\shadow.png", NULL);
	sfSprite_setTexture(bat.spShadow, bat.texShadow, sfTrue);
	sfSprite_setPosition(bat.spShadow, bat.SpritePositionBat);
}

void updatePlayer()
{
	bat.timerBat += GetDeltaTime();
	skeleton.animSkeletonTime += GetDeltaTime();

	if (state == GAME)
	{
		//player Bat
		bat.playerRect = sfSprite_getGlobalBounds(bat.spBat);
		batIsMoving = sfFalse;
		if (sfKeyboard_isScancodePressed(sfScanUp))
		{
			bat.batIsMoving = sfTrue;
			bat.frameBatY = B_HAUT;
			if (!batCollisions(bat.playerRect, bat.frameBatY, &bat.vitesse, &bat.animBatTime))
			{
				bat.SpritePositionBat.y -= bat.vitesse.y * GetDeltaTime();
			}
		}
		if (sfKeyboard_isScancodePressed(sfScanDown))
		{
			bat.batIsMoving = sfTrue;
			bat.frameBatY = B_BAS;
			if (!batCollisions(bat.playerRect, bat.frameBatY, &bat.vitesse, &bat.animBatTime))
			{
				bat.SpritePositionBat.y += bat.vitesse.y * GetDeltaTime();
			}
		}
		if (sfKeyboard_isScancodePressed(sfScanLeft))
		{
			bat.batIsMoving = sfTrue;
			bat.frameBatY = B_GAUCHE;
			if (!batCollisions(bat.playerRect, bat.frameBatY, &bat.vitesse, &bat.animBatTime))
			{
				bat.SpritePositionBat.x -= bat.vitesse.x * GetDeltaTime();
			}
		}
		if (sfKeyboard_isScancodePressed(sfScanRight))
		{
			bat.batIsMoving = sfTrue;
			bat.frameBatY = B_DROITE;
			if (!batCollisions(bat.playerRect, bat.frameBatY, &bat.vitesse, &bat.animBatTime))
			{
				bat.SpritePositionBat.x += bat.vitesse.x * GetDeltaTime();
			}
		}
		//nomalisation des mouvements diagonaux
		if ((sfKeyboard_isScancodePressed(sfScanRight) || sfKeyboard_isScancodePressed(sfScanDown) || sfKeyboard_isScancodePressed(sfScanLeft) || sfKeyboard_isScancodePressed(sfScanUp)) && (sfKeyboard_isScancodePressed(sfScanRight) || sfKeyboard_isScancodePressed(sfScanDown) || sfKeyboard_isScancodePressed(sfScanLeft) || sfKeyboard_isScancodePressed(sfScanUp)))
		{
			bat.vitesse.x* GetDeltaTime() / 2;
		}

		bat.animBatTime += GetDeltaTime();
		if (bat.animBatTime > bat.animBatSpeed)
		{

			bat.frameBatX++;
			if (bat.frameBatX >= 4) bat.frameBatX = 0;
			bat.irectBat.left = bat.frameBatX * bat.irectBat.width;
			bat.irectBat.top = bat.frameBatY * bat.irectBat.height;
			sfSprite_setTextureRect(bat.spBat, bat.irectBat);
			bat.animBatTime = 0.0f;
		}

		sfSprite_setPosition(bat.spBat, bat.SpritePositionBat);
		//ajout de l ombre sous la bat
		sfSprite_setPosition(bat.spShadow, bat.SpritePositionBat);



		//player Skeleton
		skeleton.playerRect = sfSprite_getGlobalBounds(skeleton.spSkeleton);
		skeleton.skeletonIsMoving = sfFalse;
		if (sfKeyboard_isScancodePressed(sfScanW))
		{
			skeleton.skeletonIsMoving = sfTrue;
			skeleton.skeletonIsIdle = sfFalse;
			skeleton.frameSkeletonY = SK_HAUT;
			if (!skeletonCollisions(skeleton.playerRect, skeleton.frameSkeletonY, &skeleton.vitesse, &skeleton.animSkeletonTime))
			{
				skeleton.SpritePositionSkeleton.y -= skeleton.vitesse.y * GetDeltaTime();
			}
		}
		else if (sfKeyboard_isScancodePressed(sfScanS))
		{
			skeleton.skeletonIsMoving = sfTrue;
			skeleton.skeletonIsIdle = sfFalse;
			skeleton.frameSkeletonY = SK_BAS;
			if (!skeletonCollisions(skeleton.playerRect, skeleton.frameSkeletonY, &skeleton.vitesse, &skeleton.animSkeletonTime))
			{
				skeleton.SpritePositionSkeleton.y += skeleton.vitesse.y * GetDeltaTime();
			}
		}
		else if (sfKeyboard_isScancodePressed(sfScanA))
		{
			skeleton.skeletonIsMoving = sfTrue;
			skeleton.skeletonIsIdle = sfFalse;
			skeleton.frameSkeletonY = SK_GAUCHE;
			if (!skeletonCollisions(skeleton.playerRect, skeleton.frameSkeletonY, &skeleton.vitesse, &skeleton.animSkeletonTime))
			{
				skeleton.SpritePositionSkeleton.x -= skeleton.vitesse.x * GetDeltaTime();
			}
		}
		else if (sfKeyboard_isScancodePressed(sfScanD))
		{
			skeleton.skeletonIsMoving = sfTrue;
			skeleton.skeletonIsIdle = sfFalse;
			skeleton.frameSkeletonY = SK_DROITE;
			if (!skeletonCollisions(skeleton.playerRect, skeleton.frameSkeletonY, &skeleton.vitesse, &skeleton.animSkeletonTime))
			{
				skeleton.SpritePositionSkeleton.x += skeleton.vitesse.x * GetDeltaTime();
			}
		}

		if (skeleton.skeletonIsIdle == sfFalse && skeleton.skeletonIsMoving == sfFalse)
		{
			skeleton.skeletonIsIdle = sfTrue;
			skeleton.frameSkeletonY++;
		}

		skeleton.animSkeletonTime += GetDeltaTime();
		if (skeleton.animSkeletonTime > skeleton.animSkeletonSpeed)
		{

			skeleton.frameSkeletonX++;
			if (skeleton.frameSkeletonY == 1 || skeleton.frameSkeletonY == 3 || skeleton.frameSkeletonY == 5 || skeleton.frameSkeletonY == 7)
			{
				if (skeleton.frameSkeletonX >= 8) skeleton.frameSkeletonX = 0;
			}
			else
			{
				if (skeleton.frameSkeletonX >= 4) skeleton.frameSkeletonX = 0;
			}
			skeleton.irectSkeleton.left = skeleton.frameSkeletonX * skeleton.irectSkeleton.width;
			skeleton.irectSkeleton.top = skeleton.frameSkeletonY * skeleton.irectSkeleton.height;
			sfSprite_setTextureRect(skeleton.spSkeleton, skeleton.irectSkeleton);
			skeleton.animSkeletonTime = 0.0f;
		}

		sfSprite_setPosition(skeleton.spSkeleton, skeleton.SpritePositionSkeleton);
		//ajout de lombre sous le skeleton
		sfSprite_setPosition(skeleton.spShadow, skeleton.SpritePositionSkeleton);
	}

}

void displayPlayer(sfRenderWindow* _window)
{
	//le skeleton doit etre dessiner avant le bat pour etre en dessous (et la shadow avant le skeleton)
	sfRenderWindow_drawSprite(_window, skeleton.spShadow, NULL);
	sfRenderWindow_drawSprite(_window, bat.spShadow, NULL);
	sfRenderWindow_drawSprite(_window, skeleton.spSkeleton, NULL);
	sfRenderWindow_drawSprite(_window, bat.spBat, NULL);
}
