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

	state = GAME;

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
		}


		//updates
		updateView(window);
		updateMap(window);

		//display
		sfRenderWindow_clear(window, sfColor_fromRGBA(70, 70, 70, 255));

		displayView(window);
		displayMap(window);
		if (state == MENU)
			displayTitleScreen(window);

		sfRenderWindow_display(window);
	}
}