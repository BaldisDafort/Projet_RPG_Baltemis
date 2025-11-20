#include "player.h"

State state = GAME;

void initPlayer()
{
	//init bat player
	bat.batIsMoving = sfFalse;
	bat.irectBat = (sfIntRect){ 0, 0, 16, 16 };
	bat.SpritePositionBat = (sfVector2f){ 0.0f, 0.0f };
	bat.vitesse = (sfVector2f){ 100.0f, 100.0f };
	bat.animBatTime = 0.0f;
	bat.timerBat = 0.0f;
	bat.animBatSpeed = 0.13f;
	bat.frameBatX = 0;
	bat.frameBatY = 0;


	//create bat player sprite
	bat.spBat = sfSprite_create();
	bat.texBat = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetbat.png", NULL);
	sfSprite_setTexture(bat.spBat, bat.texBat, sfTrue);
	sfSprite_setTextureRect(bat.spBat, bat.irectBat);
	sfSprite_setPosition(bat.spBat, bat.SpritePositionBat);
}

void updatePlayer()
{
	bat.timerBat += GetDeltaTime();
	if (state == GAME)
	{

		//player Bat
		bat.playerRect = sfSprite_getGlobalBounds(bat.spBat);
		batIsMoving = sfFalse;
		if (sfKeyboard_isScancodePressed(sfScanW))
		{
			batIsMoving = sfTrue;
			bat.frameBatY = HAUT;
			bat.SpritePositionBat.y -= bat.vitesse.y * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanS))
		{
			batIsMoving = sfTrue;
			bat.frameBatY = BAS;
			bat.SpritePositionBat.y += bat.vitesse.y * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanA))
		{
			batIsMoving = sfTrue;
			bat.frameBatY = GAUCHE;
			bat.SpritePositionBat.x -= bat.vitesse.x * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanD))
		{
			batIsMoving = sfTrue;
			bat.frameBatY = DROITE;
			bat.SpritePositionBat.x += bat.vitesse.x * GetDeltaTime();
		}
		else   
		{
			batIsMoving = sfFalse;
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
	}
}

void displayPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, bat.spBat, NULL);
}
