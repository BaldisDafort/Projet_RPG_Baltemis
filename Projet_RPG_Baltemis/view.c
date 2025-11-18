#include "view.h"

//view in game
sfView* viewGame;
sfVector2f posViewGame = { 400, 300 };
sfFloatRect rectViewGame = { 400, 300, 800, 600 };


void initView()
{
	viewGame = sfView_create();
	sfView_reset(viewGame, rectViewGame);
}

void updateView(sfRenderWindow* _window)
{
	sfView_setCenter(viewGame, posViewGame);
}

//view
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewGame);
}
