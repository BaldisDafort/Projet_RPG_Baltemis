#include "view.h"

//view map dezoome
sfVector2f posViewEditor = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2 };
sfFloatRect rectViewEditor = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2, mapsizeX * tilesize, mapsizeY * tilesize };

//view tuiles a selectionner
sfVector2f posView = { 400, 300 };
sfFloatRect rectView = { 400, 300, 800, 600 };



void initView()
{
	//view map dezoome
	viewEditor = sfView_create();
	sfView_reset(viewEditor, rectViewEditor);

	//view tuiles a selectionner
	view = sfView_create();
	sfView_reset(view, rectView);
}

void updateView(sfRenderWindow* _window)
{
	//view map dezoome
	sfView_setCenter(viewEditor, posViewEditor);
	sfView_setSize(viewEditor, (sfVector2f) { mapsizeX* tilesize + 3 * tilesize, mapsizeY* tilesize + 3 * tilesize });

	//view map dezoome
	sfView_setCenter(view, posView);
}

//view map dezoome
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewEditor);
}

void displayEditorView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);

}
