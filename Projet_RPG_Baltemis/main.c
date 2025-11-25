#include "tools.h"
#include "editor.h"
#include "view.h"
#include "options.h"
#include "player.h"

sfVector2i g_mousePixelPos;
sfVector2f g_mouseWorldPos;

int main()
{
	initTools();

	sfVideoMode mode = { 800, 600 };
	sfEvent events;
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML", sfResize | sfClose, NULL);

	state = MENU;

	//inits
	initView();
	initMap();
	initTitleScreen();
	initSound();
	initOptions();
	initPlayer();

	float keytimer = 0.0f;

	//boucle de jeu
	while (sfRenderWindow_isOpen(window))
	{
		restartClock();
		sfVector2i g_mousePixelPos = sfMouse_getPositionRenderWindow(window);
		sfVector2f g_mouseWorldPos = sfRenderWindow_mapPixelToCoords(window, g_mousePixelPos, g_viewGame);

		//boucle d'events
		while (sfRenderWindow_pollEvent(window, &events))
		{
			if (events.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}

			else if (events.type == sfEvtMouseButtonPressed)
			{
				if (events.mouseButton.button == sfMouseLeft)
				{
					if (state == MENU)
					{
						sfFloatRect rectButton = sfRectangleShape_getGlobalBounds(StartButton);
						if (sfFloatRect_contains(&rectButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
						{
							state = GAME;
						}

						rectButton = sfRectangleShape_getGlobalBounds(EditorButton);
						if (sfFloatRect_contains(&rectButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
						{
							firstPosTimer = 0.0f;
							state = EDITOR;
							printf(" Current Map : %d \n", currentMap);
							loadMap();
						}

						rectButton = sfRectangleShape_getGlobalBounds(OptionsButton);
						if (sfFloatRect_contains(&rectButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
						{
							state = OPTION;
						}

						rectButton = sfRectangleShape_getGlobalBounds(QuitButton);
						if (sfFloatRect_contains(&rectButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
						{
							state = QUIT;
						}
					}
					else if (state == OPTION)
					{
						sfFloatRect rectGeneralButton = sfRectangleShape_getGlobalBounds(g_GeneralSoundButton_IsMuted);
						sfFloatRect rectGeneralSoundTurnUpVolumeButton = sfRectangleShape_getGlobalBounds(g_GeneralSoundButtonVolumePlus);
						sfFloatRect rectGeneralSoundTurnDownVolumeButton = sfRectangleShape_getGlobalBounds(g_GeneralSoundButtonVolumeMinus);
						sfFloatRect rectMusicSoundTurnUpVolumeButton = sfRectangleShape_getGlobalBounds(g_MusicSoundButtonVolumePlus);
						sfFloatRect rectMusicSoundTurnDownVolumeButton = sfRectangleShape_getGlobalBounds(g_MusicSoundButtonVolumeMinus);
						sfFloatRect rectSFXSoundTurnUpVolumeButton = sfRectangleShape_getGlobalBounds(g_SFXSoundButtonVolumePlus);
						sfFloatRect rectSFXSoundTurnDownVolumeButton = sfRectangleShape_getGlobalBounds(g_SFXSoundButtonVolumeMinus);



						if (events.type == sfEvtMouseButtonPressed)
						{
							if (sfFloatRect_contains(&rectGeneralButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{
								SetGeneralMuted(!GetGeneralMuted());
								ChangeVolume(g_musicTitleScreen, 100.0f);
								g_GeneralSoundRect.left = g_GeneralSoundRect.width * GetGeneralMuted();
								sfSprite_setTextureRect(g_SpriteGeneralSound, g_GeneralSoundRect);
							}

							if (sfFloatRect_contains(&rectGeneralSoundTurnUpVolumeButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{
								g_GeneralTurnUpVolumeRect.left = g_GeneralTurnUpVolumeRect.width;
								sfSprite_setTextureRect(g_SpriteGeneralTurnUpVolume, g_GeneralTurnUpVolumeRect);
							}

							if (sfFloatRect_contains(&rectGeneralSoundTurnDownVolumeButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{
								g_GeneralTurnDownVolumeRect.left = g_GeneralTurnDownVolumeRect.width;
								sfSprite_setTextureRect(g_SpriteGeneralTurnDownVolume, g_GeneralTurnDownVolumeRect);
							}

							if (sfFloatRect_contains(&rectMusicSoundTurnUpVolumeButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{
								g_MusicTurnUpVolumeRect.left = g_MusicTurnUpVolumeRect.width;
								sfSprite_setTextureRect(g_SpriteMusicTurnUpVolume, g_MusicTurnUpVolumeRect);
							}

							if (sfFloatRect_contains(&rectMusicSoundTurnDownVolumeButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{
								g_MusicTurnDownVolumeRect.left = g_MusicTurnDownVolumeRect.width;
								sfSprite_setTextureRect(g_SpriteMusicTurnDownVolume, g_MusicTurnDownVolumeRect);
							}

							if (sfFloatRect_contains(&rectSFXSoundTurnUpVolumeButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{

								g_SFXTurnUpVolumeRect.left = g_SFXTurnUpVolumeRect.width;
								sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);
							}

							if (sfFloatRect_contains(&rectSFXSoundTurnDownVolumeButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
							{
								g_SFXTurnDownVolumeRect.left = g_SFXTurnDownVolumeRect.width;
								sfSprite_setTextureRect(g_SpriteSFXTurnDownVolume, g_SFXTurnDownVolumeRect);
							}





						}


						sfFloatRect rectMusicButton = sfRectangleShape_getGlobalBounds(g_MusicSoundButton_IsMuted);
						if (sfFloatRect_contains(&rectMusicButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
						{
							if (events.type == sfEvtMouseButtonPressed)
							{
								SetMusicMuted(!GetMusicMuted());
								//ChangeVolume(g_musicTitleScreen, 100.0f);
								g_MusicSoundRect.left = g_MusicSoundRect.width * GetMusicMuted();
								sfSprite_setTextureRect(g_SpriteMusicSound, g_MusicSoundRect);
							}

						}

						sfFloatRect rectSFXButton = sfRectangleShape_getGlobalBounds(g_SFXSoundButton_IsMuted);
						if (sfFloatRect_contains(&rectSFXButton, g_mouseWorldPos.x, g_mouseWorldPos.y))
						{
							if (events.type == sfEvtMouseButtonPressed)
							{
								SetSFXMuted(!GetSFXMuted());
								//ChangeVolume(g_musicTitleScreen, 100.0f);
								g_SFXSoundRect.left = g_SFXSoundRect.width * GetSFXMuted();
								sfSprite_setTextureRect(g_SpriteSFXSound, g_SFXSoundRect);
							}

						}
					}

				}
			}
			if (events.type == sfEvtMouseButtonReleased)
			{
				g_GeneralTurnUpVolumeRect.left = 0;
				sfSprite_setTextureRect(g_SpriteGeneralTurnUpVolume, g_GeneralTurnUpVolumeRect);

				g_GeneralTurnDownVolumeRect.left = 0;
				sfSprite_setTextureRect(g_SpriteGeneralTurnDownVolume, g_GeneralTurnDownVolumeRect);

				g_MusicTurnUpVolumeRect.left = 0;
				sfSprite_setTextureRect(g_SpriteMusicTurnUpVolume, g_GeneralTurnUpVolumeRect);

				g_MusicTurnDownVolumeRect.left = 0;
				sfSprite_setTextureRect(g_SpriteMusicTurnDownVolume, g_MusicTurnDownVolumeRect);

				g_SFXTurnUpVolumeRect.left = 0;
				sfSprite_setTextureRect(g_SpriteSFXTurnUpVolume, g_SFXTurnUpVolumeRect);

				g_SFXTurnDownVolumeRect.left = 0;
				sfSprite_setTextureRect(g_SpriteSFXTurnDownVolume, g_SFXTurnDownVolumeRect);
			}

		}


		//updates
		if (state == GAME)
		{
			currentMap = MAP;
			loadMap();
		}
		keytimer += GetDeltaTime();
		updateView(window);
		updateTitleScreen(window);
		updateMap(window);
		//updateOptions(window);
		updateSound();
		updatePlayer();

		if (sfKeyboard_isKeyPressed(sfKeyEscape) && keytimer > 0.5f)
		{
			if (state != MENU)
			{
				state = MENU;
				keytimer = 0.0f;
			}
		}

		if (state == QUIT)
		{
			sfRenderWindow_close(window);
		}

		//display
		sfRenderWindow_clear(window, sfColor_fromRGBA(70, 70, 70, 255));



		switch (state)
		{
		case GAME:
				displayView(window);
				displayMap(window);
				displayPlayer(window);
				break;
		case MENU:
				displayView(window);
				displayTitleScreen(window);
				break;
		case EDITOR:
				displayEditor(window);
				displayMap(window);
				break;
		case OPTION:
				displayOptions(window);
				break;
		}


		sfRenderWindow_display(window);
	}
}