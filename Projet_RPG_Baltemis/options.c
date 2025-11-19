#include "options.h"
#include "SFML/Graphics.h"

sfRectangleShape* g_DisplayOptions;

void initOptions()
{
	g_DisplayOptions = sfRectangleShape_create();
	sfVector2f sizeDisplayOptions = { 640.f, 480.f };
	sfVector2f positionDisplayOptions = { 80.f, 60.f };
	sfColor displayOptionsColor = sfColor_fromRGBA(139, 0, 139, 255);
	sfRectangleShape_setSize(g_DisplayOptions, sizeDisplayOptions);
	sfRectangleShape_setFillColor(g_DisplayOptions, displayOptionsColor);
	sfRectangleShape_setPosition(g_DisplayOptions, positionDisplayOptions);
	sfRectangleShape_setOutlineThickness(g_DisplayOptions, 5.f);
	sfRectangleShape_setOutlineColor(g_DisplayOptions, sfYellow);
}

void displayOptions(sfRenderWindow* _window)
{
	sfRenderWindow_drawRectangleShape(_window, g_DisplayOptions, NULL);
}
