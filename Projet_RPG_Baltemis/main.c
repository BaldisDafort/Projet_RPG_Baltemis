#include "Tools.h"

int main()
{
	sfVideoMode mode = { 800,600,32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML", sfResize | sfClose, NULL);

	sfEvent event;

	while (sfRenderWindow_isOpen(window)) // Boucle de jeu
	{
		// Boucle de gestion des events
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed) //Gestion de la croix de la barre de titre
			{
				sfRenderWindow_close(window); // Ferme la fenêtre et coupe la boucle de jeu
			}
		}
		sfRenderWindow_clear(window, sfBlue); 

		sfRenderWindow_display(window); // Affiche tout ce qui a été dessiné entre le clear et cette ligne
	}
}