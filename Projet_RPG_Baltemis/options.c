#include "options.h"
#include "SFML/Graphics.h"

sfRectangleShape* g_DisplayOptions;

sfSprite* g_SpriteGeneralSound;
sfIntRect g_GeneralSoundRect = { 0, 0, 575,50 };

sfSprite* g_SpriteGeneralTurnUpVolume;
sfIntRect g_GeneralTurnUpVolumeRect = { 0,0,75,50 };

sfSprite* g_SpriteMusicSound;
sfIntRect g_MusicSoundRect = { 0, 0, 575,50 };

sfSprite* g_SpriteMusicTurnUpVolume;
sfIntRect g_MusicTurnUpVolumeRect = { 0,0,75,50 };

sfSprite* g_SpriteSFXSound;
sfIntRect g_SFXSoundRect = { 0, 0, 575,50 };

sfSprite* g_SpriteSFXTurnUpVolume;
sfIntRect g_SFXTurnUpVolumeRect = { 0,0,75,50 };

sfSprite* g_SpriteTurnDownVolume;
sfIntRect g_TurnDownVolumeRect = { 0,0,75,50 };

sfSprite* g_SpriteGeneralTurnDownVolume;
sfIntRect g_GeneralTurnDownVolumeRect = { 0,0,75,50 };

sfSprite* g_SpriteMusicTurnDownVolume;
sfIntRect g_MusicTurnDownVolumeRect = { 0,0,75,50 };

sfSprite* g_SpriteSFXTurnDownVolume;
sfIntRect g_SFXTurnDownVolumeRect = { 0,0,75,50 };

// Les boutons pour le son en general
sfRectangleShape* g_GeneralSoundButton_IsMuted;
sfRectangleShape* g_GeneralSoundButtonVolumePlus;
sfRectangleShape* g_GeneralSoundButtonVolumeMinus;

// Les boutons pour les musiques
sfRectangleShape* g_MusicSoundButton_IsMuted;
sfRectangleShape* g_MusicSoundButtonVolumePlus;
sfRectangleShape* g_MusicSoundButtonVolumeMinus;

// Les boutons pour les sons
sfRectangleShape* g_SFXSoundButton_IsMuted;
sfRectangleShape* g_SFXSoundButtonVolumePlus;
sfRectangleShape* g_SFXSoundButtonVolumeMinus;



void initOptions()
{
	g_DisplayOptions = sfRectangleShape_create();
	sfVector2f sizeDisplayOptions = { 640.f, 480.f };
	sfVector2f positionDisplayOptions = { 80.f, 60.f };
	sfColor displayOptionsColor = sfColor_fromRGBA(34, 66, 124, 100);
	sfRectangleShape_setSize(g_DisplayOptions, sizeDisplayOptions);
	sfRectangleShape_setFillColor(g_DisplayOptions, displayOptionsColor);
	sfRectangleShape_setPosition(g_DisplayOptions, positionDisplayOptions);
	sfRectangleShape_setOutlineThickness(g_DisplayOptions, 5.f);
	sfRectangleShape_setOutlineColor(g_DisplayOptions, sfBlack);

	// GENERAL
	g_GeneralSoundButton_IsMuted = sfRectangleShape_create();
	sfVector2f sizeGeneralSound = { 575.f, 50.f };
	sfVector2f positionGeneralSound = { 110.f, 90.f };
	sfColor generalSoundButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_GeneralSoundButton_IsMuted, generalSoundButtonColor);
	sfRectangleShape_setSize(g_GeneralSoundButton_IsMuted, sizeGeneralSound);
	sfRectangleShape_setPosition(g_GeneralSoundButton_IsMuted, positionGeneralSound);

	g_GeneralSoundButtonVolumeMinus = sfRectangleShape_create();
	sfVector2f sizeGeneralVolumeMinus = { 75.f, 50.f };
	sfVector2f positionGeneralVolumeMinus = { 515.f, 160.f };
	sfColor generalVolumeDownButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_GeneralSoundButtonVolumeMinus, generalVolumeDownButtonColor);
	sfRectangleShape_setSize(g_GeneralSoundButtonVolumeMinus, sizeGeneralVolumeMinus);
	sfRectangleShape_setPosition(g_GeneralSoundButtonVolumeMinus, positionGeneralVolumeMinus);

	g_GeneralSoundButtonVolumePlus = sfRectangleShape_create();
	sfVector2f sizeGeneralVolumePlus = { 75.f, 50.f };
	sfVector2f positionGeneralVolumePlus = { 610.f, 160.f };
	sfColor generalVolumePlusButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_GeneralSoundButtonVolumePlus, generalVolumePlusButtonColor);
	sfRectangleShape_setSize(g_GeneralSoundButtonVolumePlus, sizeGeneralVolumePlus);
	sfRectangleShape_setPosition(g_GeneralSoundButtonVolumePlus, positionGeneralVolumePlus);

	
	// MUSIC
	g_MusicSoundButton_IsMuted = sfRectangleShape_create();
	sfVector2f sizeMusicSound = { 575.f, 50.f };
	sfVector2f positionMusicSound = { 110.f, 240.f };
	sfColor musicSoundButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_MusicSoundButton_IsMuted, musicSoundButtonColor);
	sfRectangleShape_setSize(g_MusicSoundButton_IsMuted, sizeMusicSound);
	sfRectangleShape_setPosition(g_MusicSoundButton_IsMuted, positionMusicSound);

	g_MusicSoundButtonVolumeMinus = sfRectangleShape_create();
	sfVector2f sizeMusicVolumeMinus = { 75.f, 50.f };
	sfVector2f positionMusicVolumeMinus = { 515.f, 310.f };
	sfColor musicVolumeDownButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_MusicSoundButtonVolumeMinus, musicVolumeDownButtonColor);
	sfRectangleShape_setSize(g_MusicSoundButtonVolumeMinus, sizeMusicVolumeMinus);
	sfRectangleShape_setPosition(g_MusicSoundButtonVolumeMinus, positionMusicVolumeMinus);

	g_MusicSoundButtonVolumePlus = sfRectangleShape_create();
	sfVector2f sizeMusicVolumePlus = { 75.f, 50.f };
	sfVector2f positionMusicVolumePlus = { 610.f, 310.f };
	sfColor musicVolumePlusButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_MusicSoundButtonVolumePlus, musicVolumePlusButtonColor);
	sfRectangleShape_setSize(g_MusicSoundButtonVolumePlus, sizeMusicVolumePlus);
	sfRectangleShape_setPosition(g_MusicSoundButtonVolumePlus, positionMusicVolumePlus);


	// SOUND
	g_SFXSoundButton_IsMuted = sfRectangleShape_create();
	sfVector2f sizeSFXSound = { 575.f, 50.f };
	sfVector2f positionSFXSound = { 110.f, 390.f };
	sfColor sfxSoundButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_SFXSoundButton_IsMuted, sfxSoundButtonColor);
	sfRectangleShape_setSize(g_SFXSoundButton_IsMuted, sizeSFXSound);
	sfRectangleShape_setPosition(g_SFXSoundButton_IsMuted, positionSFXSound);

	g_SFXSoundButtonVolumeMinus = sfRectangleShape_create();
	sfVector2f sizeSFXVolumeMinus = { 75.f, 50.f };
	sfVector2f positionSFXVolumeMinus = { 515.f, 460.f };
	sfColor sfxVolumeDownButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_SFXSoundButtonVolumeMinus, sfxVolumeDownButtonColor);
	sfRectangleShape_setSize(g_SFXSoundButtonVolumeMinus, sizeSFXVolumeMinus);
	sfRectangleShape_setPosition(g_SFXSoundButtonVolumeMinus, positionSFXVolumeMinus);

	g_SFXSoundButtonVolumePlus = sfRectangleShape_create();
	sfVector2f sizeSFXVolumePlus = { 75.f, 50.f };
	sfVector2f positionSFXVolumePlus = { 610.f, 460.f };
	sfColor sfxVolumePlusButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(g_SFXSoundButtonVolumePlus, sfxVolumePlusButtonColor);
	sfRectangleShape_setSize(g_SFXSoundButtonVolumePlus, sizeSFXVolumePlus);
	sfRectangleShape_setPosition(g_SFXSoundButtonVolumePlus, positionSFXVolumePlus);

	g_SpriteGeneralSound = sfSprite_create();
	sfTexture* tGeneralSound = sfTexture_createFromFile("..\\Resources\\Textures\\general-sound-button.png", NULL);
	sfSprite_setTexture(g_SpriteGeneralSound, tGeneralSound, sfTrue);
	sfSprite_setTextureRect(g_SpriteGeneralSound, g_GeneralSoundRect);
	sfSprite_setPosition(g_SpriteGeneralSound, positionGeneralSound);

	g_SpriteMusicSound = sfSprite_create();
	sfTexture* tMusicSound = sfTexture_createFromFile("..\\Resources\\Textures\\music-sound-button.png", NULL);
	sfSprite_setTexture(g_SpriteMusicSound, tMusicSound, sfTrue);
	sfSprite_setTextureRect(g_SpriteMusicSound, g_MusicSoundRect);
	sfSprite_setPosition(g_SpriteMusicSound, positionMusicSound);

	g_SpriteSFXSound = sfSprite_create();
	sfTexture* tSFXSound = sfTexture_createFromFile("..\\Resources\\Textures\\sfx-sound-button.png", NULL);
	sfSprite_setTexture(g_SpriteSFXSound, tSFXSound, sfTrue);
	sfSprite_setTextureRect(g_SpriteSFXSound, g_SFXSoundRect);
	sfSprite_setPosition(g_SpriteSFXSound, positionSFXSound);

	g_SpriteGeneralTurnUpVolume = sfSprite_create();
	sfTexture* tTurnUpVolume = sfTexture_createFromFile("..\\Resources\\Textures\\volumeUp.png", NULL);
	sfSprite_setTexture(g_SpriteGeneralTurnUpVolume, tTurnUpVolume, sfTrue);
	sfSprite_setTextureRect(g_SpriteGeneralTurnUpVolume, g_GeneralTurnUpVolumeRect);
	sfSprite_setPosition(g_SpriteGeneralTurnUpVolume, positionGeneralVolumePlus);

	g_SpriteMusicTurnUpVolume = sfSprite_create();
	sfTexture* tMusicTurnUpVolume = sfTexture_createFromFile("..\\Resources\\Textures\\volumeUp.png", NULL);
	sfSprite_setTexture(g_SpriteMusicTurnUpVolume, tMusicTurnUpVolume, sfTrue);
	sfSprite_setTextureRect(g_SpriteMusicTurnUpVolume, g_MusicTurnUpVolumeRect);
	sfSprite_setPosition(g_SpriteMusicTurnUpVolume, positionMusicVolumePlus);

	g_SpriteSFXTurnUpVolume = sfSprite_create();
	sfTexture* tSFXTurnUpVolume = sfTexture_createFromFile("..\\Resources\\Textures\\volumeUp.png", NULL);
	sfSprite_setTexture(g_SpriteSFXTurnUpVolume, tSFXTurnUpVolume, sfTrue);
	sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);
	sfSprite_setPosition(g_SpriteSFXTurnUpVolume, positionSFXVolumePlus);

	g_SpriteGeneralTurnDownVolume = sfSprite_create();
	sfTexture* tGeneralTurnDownVolume = sfTexture_createFromFile("..\\Resources\\Textures\\volumeDown.png", NULL);
	sfSprite_setTexture(g_SpriteGeneralTurnDownVolume, tGeneralTurnDownVolume, sfTrue);
	sfSprite_setTextureRect(g_SpriteGeneralTurnDownVolume, g_GeneralTurnDownVolumeRect);
	sfSprite_setPosition(g_SpriteGeneralTurnDownVolume, positionGeneralVolumeMinus);

	g_SpriteMusicTurnDownVolume = sfSprite_create();
	sfTexture* tMusicTurnDownVolume = sfTexture_createFromFile("..\\Resources\\Textures\\volumeDown.png", NULL);
	sfSprite_setTexture(g_SpriteMusicTurnDownVolume, tMusicTurnDownVolume, sfTrue);
	sfSprite_setTextureRect(g_SpriteMusicTurnDownVolume, g_MusicTurnDownVolumeRect);
	sfSprite_setPosition(g_SpriteMusicTurnDownVolume, positionMusicVolumeMinus);

	g_SpriteSFXTurnDownVolume = sfSprite_create();
	sfTexture* tSFXTurnDownVolume = sfTexture_createFromFile("..\\Resources\\Textures\\volumeDown.png", NULL);
	sfSprite_setTexture(g_SpriteSFXTurnDownVolume, tSFXTurnDownVolume, sfTrue);
	sfSprite_setTextureRect(g_SpriteSFXTurnDownVolume, g_SFXTurnDownVolumeRect);
	sfSprite_setPosition(g_SpriteSFXTurnDownVolume, positionSFXVolumeMinus);

}

void updateOptions(sfRenderWindow* _window)
{
	sfVector2i mousePixelPos = sfMouse_getPositionRenderWindow(_window);
	sfFloatRect rectGeneralSoundTurnUpVolumeButton = sfRectangleShape_getGlobalBounds(g_GeneralSoundButtonVolumePlus);
	sfFloatRect rectMusicSoundTurnUpVolumeButton = sfRectangleShape_getGlobalBounds(g_MusicSoundButtonVolumePlus);
	sfFloatRect rectSFXSoundTurnUpVolumeButton = sfRectangleShape_getGlobalBounds(g_SFXSoundButtonVolumePlus);

	sfVector2f mouseWorldPos = sfRenderWindow_mapPixelToCoords(_window, mousePixelPos, g_viewGame);

	// General Turn Up Volume Hover Animation
	if (sfFloatRect_contains(&rectGeneralSoundTurnUpVolumeButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		g_GeneralTurnUpVolumeRect.left = g_GeneralTurnUpVolumeRect.width;
		sfSprite_setTextureRect(g_SpriteGeneralTurnUpVolume, g_GeneralTurnUpVolumeRect);
	}
	else
	{
		g_GeneralTurnUpVolumeRect.left = 0;
		sfSprite_setTextureRect(g_SpriteGeneralTurnUpVolume, g_GeneralTurnUpVolumeRect);
	}

	// Music Turn Up Volume Hover Animation
	if (sfFloatRect_contains(&rectMusicSoundTurnUpVolumeButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		g_MusicTurnUpVolumeRect.left = g_MusicTurnUpVolumeRect.width;
		sfSprite_setTextureRect(g_SpriteMusicTurnUpVolume, g_MusicTurnUpVolumeRect);
	}
	else
	{
		g_MusicTurnUpVolumeRect.left = 0;
		sfSprite_setTextureRect(g_SpriteMusicTurnUpVolume, g_MusicTurnUpVolumeRect);
	}

	// SFX Turn Up Volume Hover Animation
	if (sfFloatRect_contains(&rectSFXSoundTurnUpVolumeButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		g_SFXTurnUpVolumeRect.left = g_SFXTurnUpVolumeRect.width;
		sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);
	}
	else
	{
		g_SFXTurnUpVolumeRect.left = 0;
		sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);
	}

	// General Turn Down Volume Hover Animation
	if (sfFloatRect_contains(&rectSFXSoundTurnUpVolumeButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		g_SFXTurnUpVolumeRect.left = g_SFXTurnUpVolumeRect.width;
		sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);
	}
	else
	{
		g_SFXTurnUpVolumeRect.left = 0;
		sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);
	}
}

void displayOptions(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, sTitleScreen, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_DisplayOptions, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_GeneralSoundButton_IsMuted, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_GeneralSoundButtonVolumeMinus, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_GeneralSoundButtonVolumePlus, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteGeneralSound, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteGeneralTurnUpVolume, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteGeneralTurnDownVolume, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_MusicSoundButton_IsMuted, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_MusicSoundButtonVolumeMinus, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_MusicSoundButtonVolumePlus, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteMusicSound, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteMusicTurnUpVolume, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteMusicTurnDownVolume, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_SFXSoundButton_IsMuted, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_SFXSoundButtonVolumeMinus, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_SFXSoundButtonVolumePlus, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteSFXSound, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteSFXTurnUpVolume, NULL);
	sfRenderWindow_drawSprite(_window, g_SpriteSFXTurnDownVolume, NULL);
}
