#include "view.h"

//view map dezoome
sfView* viewEditor;
sfVector2f posViewEditor = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2 };
sfFloatRect rectViewEditor = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2, mapsizeX * tilesize, mapsizeY * tilesize };

void initView()
{
	//view map dezoome
	viewEditor = sfView_create();
	sfView_reset(viewEditor, rectViewEditor);

}

void updateView(sfRenderWindow* _window)
{
	//view map dezoome
	sfView_setCenter(viewEditor, posViewEditor);
	sfView_setSize(viewEditor, (sfVector2f) { mapsizeX* tilesize + 3 * tilesize, mapsizeY* tilesize + 3 * tilesize });

}

//view map dezoome
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewEditor);
}