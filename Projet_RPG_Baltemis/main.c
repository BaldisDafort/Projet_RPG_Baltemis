#include "tools.h"
#include "editor.h"
#include "view.h"

int main()
{
	//inits
	initTools();

	sfVideoMode mode = { 800, 600 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "RPG", sfDefaultStyle, NULL);
	sfEvent events;

	initView();
	initMap();

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

		sfRenderWindow_display(window);
	}
}