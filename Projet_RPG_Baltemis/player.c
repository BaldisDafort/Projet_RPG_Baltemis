#include "player.h"

State state = GAME;
//init bat player
sfSprite* spBat;
sfTexture* texBat;
sfFloatRect playerRect;
sfIntRect irectBat = { 0, 0, 16, 16 };
sfVector2f SpritePositionBat = { 0.0f, 0.0f };
sfVector2f vitesse = { 100.0f, 100.0f };
float animBatTime = 0.0f;
float timerBat = 0.0f;
float animBatSpeed = 0.13f;
int frameBatX = 0;
int frameBatY = 0;

sfBool batIsMoving = sfFalse;

void initPlayer()
{

	//create bat player sprite
	spBat = sfSprite_create();
	texBat = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetbat.png", NULL);
	sfSprite_setTexture(spBat, texBat, sfTrue);
	sfSprite_setTextureRect(spBat, irectBat);
	sfSprite_setPosition(spBat, SpritePositionBat);
}

void updatePlayer()
{
	timerBat += GetDeltaTime();
	if (state == GAME)
	{

		//player Bat
		playerRect = sfSprite_getGlobalBounds(spBat);
		batIsMoving = sfFalse;
		if (sfKeyboard_isScancodePressed(sfScanW))
		{
			batIsMoving = sfTrue;
			frameBatY = HAUT;
			SpritePositionBat.y -= vitesse.y * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanS))
		{
			batIsMoving = sfTrue;
			frameBatY = BAS;
			SpritePositionBat.y += vitesse.y * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanA))
		{
			batIsMoving = sfTrue;
			frameBatY = GAUCHE;
			SpritePositionBat.x -= vitesse.x * GetDeltaTime();
		}
		if (sfKeyboard_isScancodePressed(sfScanD))
		{
			batIsMoving = sfTrue;
			frameBatY = DROITE;
			SpritePositionBat.x += vitesse.x * GetDeltaTime();
		}
		else   
		{
			batIsMoving = sfFalse;
		}

		animBatTime += GetDeltaTime();
		if (animBatTime > animBatSpeed)
		{

			frameBatX++;
			if (frameBatX >= 4) frameBatX = 0;
				irectBat.left = frameBatX * irectBat.width;
				irectBat.top = frameBatY * irectBat.height;
				sfSprite_setTextureRect(spBat, irectBat);
				animBatTime = 0.0f;
		}

		sfSprite_setPosition(spBat, SpritePositionBat);
	}
}

void displayPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, spBat, NULL);
}
