#include "player.h"

State state = GAME;
sfSprite* spBat;
sfTexture* texBat;
sfFloatRect playerRect;
sfIntRect irectBat = { 0, 0, 16, 16 };
sfVector2f SpritePositionBat = {0.0f, 0.0f};
sfVector2f vitesse = { 100.0f, 100.0f };
float animtime = 0.0f;
float timer = 0.0f;
int frameX = 0;
int frameY = 0;

sfBool isMoving = sfFalse;

void initPlayer()
{
	spBat = sfSprite_create();
	texBat = sfTexture_createFromFile("..\\Resources\\Textures\\player.png", NULL);
	sfSprite_setTexture(spBat, texBat, sfTrue);
	sfSprite_setTextureRect(spBat, irectBat);
	sfSprite_setPosition(spBat, SpritePositionBat);
}

void updatePlayer()
{
	timer += GetDeltaTime();
	if (state == GAME)
	{

		//player Bat
		playerRect = sfSprite_getGlobalBounds(spBat);
		isMoving = sfFalse;
		if (sfKeyboard_isScancodePressed(sfScanW))
		{
			isMoving = sfTrue;
			frameY = HAUT;
			SpritePositionBat.y -= vitesse.y * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanS))
		{
			isMoving = sfTrue;
			frameY = BAS;
			SpritePositionBat.y += vitesse.y * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanA))
		{
			isMoving = sfTrue;
			frameY = GAUCHE;
			SpritePositionBat.x -= vitesse.x * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanD))
		{
			isMoving = sfTrue;
			frameY = DROITE;
			SpritePositionBat.x += vitesse.x * GetDeltaTime();
		}
		else   
		{
			isMoving = sfFalse;
		}

		animtime += GetDeltaTime();
		if (animtime > 0.06f)
		{

			if (isMoving) frameX++;
			else frameX = 0;
			if (frameX > 4) frameX = 0;
			irectBat.left = frameX * irectBat.width;
			irectBat.top = frameY * irectBat.height;
			sfSprite_setTextureRect(spBat, irectBat);
			animtime = 0.0f;
		}

		sfSprite_setPosition(spBat, SpritePositionBat);
	}
}

void displayPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, spBat, NULL);
}
