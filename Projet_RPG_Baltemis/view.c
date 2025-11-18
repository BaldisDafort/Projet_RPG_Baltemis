#pragma once

#include "view.h"

//view map dezoome
sfView* view;
sfVector2f posView = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2 };
sfFloatRect rectView = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2, mapsizeX * tilesize, mapsizeY * tilesize };

void initView()
{
	//view map dezoome
	view = sfView_create();
	sfView_reset(view, rectView);

}

void updateView(sfRenderWindow* _window)
{
	//view map dezzome
	sfView_setCenter(view, posView);
	sfView_setSize(view, (sfVector2f) { mapsizeX* tilesize + 3 * tilesize, mapsizeY* tilesize + 3 * tilesize });

}

//view map dezoome
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);
}