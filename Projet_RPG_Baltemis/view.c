#include "view.h"

//view in game
sfView* g_viewGame;
sfVector2f posViewGame = { 400, 300 };
sfFloatRect rectViewGame = { 400, 300, 800, 600 };


void initView()
{
	g_viewGame = sfView_create();
	sfView_reset(g_viewGame, rectViewGame);
}

void updateView(sfRenderWindow* _window)
{
	sfView_setCenter(g_viewGame, posViewGame);
}

//view
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, g_viewGame);
}
