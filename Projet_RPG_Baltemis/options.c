#include "options.h"
#include "SFML/Graphics.h"

sfRectangleShape* g_DisplayOptions;
sfRectangleShape* g_GeneralSoundButton_IsMuted;
sfRectangleShape* g_GeneralSoundButtonVolumePlus;
sfRectangleShape* g_GeneralSoundButtonVolumeMinus;
sfRectangleShape* g_SFXSoundButton_IsMuted;
sfRectangleShape* g_SFXSoundButtonVolumePlus;
sfRectangleShape* g_SFXSoundButtonVolumeMinus;

// Les boutons pour le son en g�n�ral
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
	sfColor displayOptionsColor = sfColor_fromRGBA(139, 0, 139, 255);
	sfRectangleShape_setSize(g_DisplayOptions, sizeDisplayOptions);
	sfRectangleShape_setFillColor(g_DisplayOptions, displayOptionsColor);
	sfRectangleShape_setPosition(g_DisplayOptions, positionDisplayOptions);
	sfRectangleShape_setOutlineThickness(g_DisplayOptions, 5.f);
	sfRectangleShape_setOutlineColor(g_DisplayOptions, sfYellow);

	// GENERAL
	g_GeneralSoundButton_IsMuted = sfRectangleShape_create();
	sfVector2f sizeGeneralSound = { 575.f, 50.f };
	sfVector2f positionGeneralSound = { 110.f, 90.f };
	sfRectangleShape_setSize(g_GeneralSoundButton_IsMuted, sizeGeneralSound);
	sfRectangleShape_setFillColor(g_GeneralSoundButton_IsMuted, sfBlack);
	sfRectangleShape_setPosition(g_GeneralSoundButton_IsMuted, positionGeneralSound);
	sfRectangleShape_setOutlineThickness(g_GeneralSoundButton_IsMuted, 5.f);
	sfRectangleShape_setOutlineColor(g_GeneralSoundButton_IsMuted, sfYellow);

	g_GeneralSoundButtonVolumeMinus = sfRectangleShape_create();
	sfVector2f sizeGeneralVolumeMinus = { 75.f, 50.f };
	sfVector2f positionGeneralVolumeMinus = { 515.f, 160.f };
	sfRectangleShape_setSize(g_GeneralSoundButtonVolumeMinus, sizeGeneralVolumeMinus);
	sfRectangleShape_setFillColor(g_GeneralSoundButtonVolumeMinus, sfBlack);
	sfRectangleShape_setPosition(g_GeneralSoundButtonVolumeMinus, positionGeneralVolumeMinus);
	sfRectangleShape_setOutlineThickness(g_GeneralSoundButtonVolumeMinus, 5.f);
	sfRectangleShape_setOutlineColor(g_GeneralSoundButtonVolumeMinus, sfYellow);

	g_GeneralSoundButtonVolumePlus = sfRectangleShape_create();
	sfVector2f sizeGeneralVolumePlus = { 75.f, 50.f };
	sfVector2f positionGeneralVolumePlus = { 610.f, 160.f };
	sfRectangleShape_setSize(g_GeneralSoundButtonVolumePlus, sizeGeneralVolumePlus);
	sfRectangleShape_setFillColor(g_GeneralSoundButtonVolumePlus, sfBlack);
	sfRectangleShape_setPosition(g_GeneralSoundButtonVolumePlus, positionGeneralVolumePlus);
	sfRectangleShape_setOutlineThickness(g_GeneralSoundButtonVolumePlus, 5.f);
	sfRectangleShape_setOutlineColor(g_GeneralSoundButtonVolumePlus, sfYellow);
	
	// MUSIC
	g_MusicSoundButton_IsMuted = sfRectangleShape_create();
	sfVector2f sizeMusicSound = { 575.f, 50.f };
	sfVector2f positionMusicSound = { 110.f, 240.f };
	sfRectangleShape_setSize(g_MusicSoundButton_IsMuted, sizeMusicSound);
	sfRectangleShape_setFillColor(g_MusicSoundButton_IsMuted, sfBlack);
	sfRectangleShape_setPosition(g_MusicSoundButton_IsMuted, positionMusicSound);
	sfRectangleShape_setOutlineThickness(g_MusicSoundButton_IsMuted, 5.f);
	sfRectangleShape_setOutlineColor(g_MusicSoundButton_IsMuted, sfYellow);

	g_MusicSoundButtonVolumeMinus = sfRectangleShape_create();
	sfVector2f sizeMusicVolumeMinus = { 75.f, 50.f };
	sfVector2f positionMusicVolumeMinus = { 515.f, 310.f };
	sfRectangleShape_setSize(g_MusicSoundButtonVolumeMinus, sizeMusicVolumeMinus);
	sfRectangleShape_setFillColor(g_MusicSoundButtonVolumeMinus, sfBlack);
	sfRectangleShape_setPosition(g_MusicSoundButtonVolumeMinus, positionMusicVolumeMinus);
	sfRectangleShape_setOutlineThickness(g_MusicSoundButtonVolumeMinus, 5.f);
	sfRectangleShape_setOutlineColor(g_MusicSoundButtonVolumeMinus, sfYellow);

	g_MusicSoundButtonVolumePlus = sfRectangleShape_create();
	sfVector2f sizeMusicVolumePlus = { 75.f, 50.f };
	sfVector2f positionMusicVolumePlus = { 610.f, 310.f };
	sfRectangleShape_setSize(g_MusicSoundButtonVolumePlus, sizeMusicVolumePlus);
	sfRectangleShape_setFillColor(g_MusicSoundButtonVolumePlus, sfBlack);
	sfRectangleShape_setPosition(g_MusicSoundButtonVolumePlus, positionMusicVolumePlus);
	sfRectangleShape_setOutlineThickness(g_MusicSoundButtonVolumePlus, 5.f);
	sfRectangleShape_setOutlineColor(g_MusicSoundButtonVolumePlus, sfYellow);

	// SOUND
	g_SFXSoundButton_IsMuted = sfRectangleShape_create();
	sfVector2f sizeSFXSound = { 575.f, 50.f };
	sfVector2f positionSFXSound = { 110.f, 390.f };
	sfRectangleShape_setSize(g_SFXSoundButton_IsMuted, sizeSFXSound);
	sfRectangleShape_setFillColor(g_SFXSoundButton_IsMuted, sfBlack);
	sfRectangleShape_setPosition(g_SFXSoundButton_IsMuted, positionSFXSound);
	sfRectangleShape_setOutlineThickness(g_SFXSoundButton_IsMuted, 5.f);
	sfRectangleShape_setOutlineColor(g_SFXSoundButton_IsMuted, sfYellow);

	g_SFXSoundButtonVolumeMinus = sfRectangleShape_create();
	sfVector2f sizeSFXVolumeMinus = { 75.f, 50.f };
	sfVector2f positionSFXVolumeMinus = { 515.f, 460.f };
	sfRectangleShape_setSize(g_SFXSoundButtonVolumeMinus, sizeSFXVolumeMinus);
	sfRectangleShape_setFillColor(g_SFXSoundButtonVolumeMinus, sfBlack);
	sfRectangleShape_setPosition(g_SFXSoundButtonVolumeMinus, positionSFXVolumeMinus);
	sfRectangleShape_setOutlineThickness(g_SFXSoundButtonVolumeMinus, 5.f);
	sfRectangleShape_setOutlineColor(g_SFXSoundButtonVolumeMinus, sfYellow);

	g_SFXSoundButtonVolumePlus = sfRectangleShape_create();
	sfVector2f sizeSFXVolumePlus = { 75.f, 50.f };
	sfVector2f positionSFXVolumePlus = { 610.f, 460.f };
	sfRectangleShape_setSize(g_SFXSoundButtonVolumePlus, sizeSFXVolumePlus);
	sfRectangleShape_setFillColor(g_SFXSoundButtonVolumePlus, sfBlack);
	sfRectangleShape_setPosition(g_SFXSoundButtonVolumePlus, positionSFXVolumePlus);
	sfRectangleShape_setOutlineThickness(g_SFXSoundButtonVolumePlus, 5.f);
	sfRectangleShape_setOutlineColor(g_SFXSoundButtonVolumePlus, sfYellow);

}

void displayOptions(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, sTitleScreen, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_DisplayOptions, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_GeneralSoundButton_IsMuted, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_GeneralSoundButtonVolumeMinus, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_GeneralSoundButtonVolumePlus, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_MusicSoundButton_IsMuted, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_MusicSoundButtonVolumeMinus, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_MusicSoundButtonVolumePlus, NULL);

	sfRenderWindow_drawRectangleShape(_window, g_SFXSoundButton_IsMuted, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_SFXSoundButtonVolumeMinus, NULL);
	sfRenderWindow_drawRectangleShape(_window, g_SFXSoundButtonVolumePlus, NULL);
}
