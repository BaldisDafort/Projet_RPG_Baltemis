#include "tools.h"
#include "editor.h"
#include "view.h"

int main()
{
	//inits
	initTools();

	sfVideoMode mode = { 800, 600 };
	sfEvent events;
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML", sfResize | sfClose, NULL);

	initView();
	initMap();
	initTitleScreen();

	state = MENU;

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

						rectButton = sfRectangleShape_getGlobalBounds(QuitButton);
						if (sfFloatRect_contains(&rectButton, events.mouseButton.x, events.mouseButton.y))
						{
							state = QUIT;
						}
					}


				}
			}

		}


		//updates
		updateView(window);
		updateMap(window);

		//display
		sfRenderWindow_clear(window, sfColor_fromRGBA(70, 70, 70, 255));



		if (state == MENU)
		{
			displayTitleScreen(window);
		}

		else if (state == EDITOR)
		{
			displayView(window);
			displayMap(window);
		}


		sfRenderWindow_display(window);
	}
}