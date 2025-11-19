#include "tools.h"
#include "editor.h"
#include "view.h"
#include "options.h"

int main()
{
	//inits
	initTools();

	sfVideoMode mode = { 800, 600 };
	sfEvent events;
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML", sfResize | sfClose, NULL);

	state = MENU;

	initView();
	initMap();
	initTitleScreen();
	initSound();
	initOptions();


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
							state = EDITOR;
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
		keytimer += GetDeltaTime();
		updateView(window);
		updateMap(window);
		updateSound();

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



		if (state == MENU)
		{
			displayView(window);
			displayTitleScreen(window);
		}

		else if (state == EDITOR)
		{
			displayMap(window);
		}

		else if (state == OPTION)
		{
			displayOptions(window);
		}



		sfRenderWindow_display(window);
	}
}