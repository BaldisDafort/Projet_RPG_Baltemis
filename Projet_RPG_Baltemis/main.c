#include "tools.h"
#include "editor.h"
#include "view.h"
#include "options.h"
#include "player.h"

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
						if (sfFloatRect_contains(&rectButton, events.mouseButton.x, events.mouseButton.y))
						{
							state = GAME;
						}

						rectButton = sfRectangleShape_getGlobalBounds(EditorButton);
						if (sfFloatRect_contains(&rectButton, events.mouseButton.x, events.mouseButton.y))
						{
							firstPosTimer = 0.0f;
							state = EDITOR;
							printf(" Current Map : %d \n", currentMap);
							loadMap();
						}

						rectButton = sfRectangleShape_getGlobalBounds(OptionsButton);
						if (sfFloatRect_contains(&rectButton, events.mouseButton.x, events.mouseButton.y))
						{
							state = OPTION;
						}

						rectButton = sfRectangleShape_getGlobalBounds(QuitButton);
						if (sfFloatRect_contains(&rectButton, events.mouseButton.x, events.mouseButton.y))
						{
							state = QUIT;
						}
					}
					else if (state == OPTION)
					{
						sfFloatRect rectGeneralButton = sfRectangleShape_getGlobalBounds(g_GeneralSoundButton_IsMuted);
						if (sfFloatRect_contains(&rectGeneralButton, events.mouseButton.x, events.mouseButton.y))
						{

							printf("Ici");
							SetGeneralMuted(!GetGeneralMuted());
							ChangeVolume(g_musicTitleScreen, 100.0f);
						}
					}

				}
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
		updateOptions(window);
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