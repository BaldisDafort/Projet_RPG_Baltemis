#include "editor.h"

//tilemap
sfSprite* tileset;
sfTexture* textmap;
sfIntRect rectile = { 0, 0, tilesize, tilesize };
sfVector2f pos = { 0.0f, 0.0f };
sfVector2f origin = { 0.0f, 0.0f };

//tableaux
int map[mapsizeY][mapsizeX];

//timer
float posTimer = 0.0f;

void initMap()
{
	//int
	int block = 0.0f;
	int i = 0;

	//tileset
	tileset = sfSprite_create();
	textmap = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetground.png", NULL);
	sfSprite_setTexture(tileset, textmap, sfTrue);
	sfSprite_setPosition(tileset, origin);

	
	//initialiser les case du tableau a 1 pour pas que la map soit invisible
	for (int x = 0; x < mapsizeX; x++)
	{
		for (int y = 0; y < mapsizeX; y++)
		{
			map[y][x] = 1;
		}
	}
}

void updateMap(sfRenderWindow* _window)
{
}

void displayMap(sfRenderWindow* _window)
{
	//int
	int posx = 0;
	int posy = 0;
	sfVector2f origin = { 0.0f, 0.0f };

	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			posx = map[y][x] * tilesize;
			sfIntRect rectile = { posx, posy, tilesize, tilesize };
			sfVector2f pos = { origin.x, origin.y };
			sfSprite_setPosition(tileset, pos);
			sfSprite_setTextureRect(tileset, rectile);
			sfRenderWindow_drawSprite(_window, tileset, NULL);
			origin.x += tilesize;

			if (origin.x >= mapsizeX * tilesize)
			{
				origin.x = 0;
				origin.y += tilesize;
			}
		}
	}
}

