#include "editor.h"

//view map dezoome
sfView* viewEditor;
sfVector2f posViewEditor = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2 };
sfFloatRect rectViewEditor = { mapsizeX * tilesize / 2 + 1.5 * tilesize, mapsizeY * tilesize / 2, mapsizeX * tilesize, mapsizeY * tilesize };

//tilemap
sfSprite* tileset;
sfTexture* textmap;
sfIntRect rectile = { 0, 0, tilesize, tilesize };
sfVector2f pos = { 0.0f, 0.0f };
sfVector2f origin = { 0.0f, 0.0f };

//rectangle noir pour les tiles
sfRectangleShape* rectTile;
sfVector2f rectpos = { (mapsizeX) * tilesize, -2*tilesize };
sfVector2f rectSize = { 3 * tilesize, mapsizeY * tilesize + 4*tilesize};

//tile choix
sfSprite* tileEditor;
sfVector2f posEditor = { 0.0f, 0.0f };
sfVector2f originEditor = { (mapsizeX) * tilesize, tilesize };

//tableau
int map[mapsizeY][mapsizeX];
int i = 0;
int tileChoice[2][12];

//timer
float posTimer = 0.0f;

//block selectionne
int block = 0.0f;

void initMap()
{
	//view map dezoome
	viewEditor = sfView_create();
	sfView_reset(viewEditor, rectViewEditor);



	//int i
	int i = 0;

	//tileset
	tileset = sfSprite_create();
	textmap = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetground.png", NULL);
	sfSprite_setTexture(tileset, textmap, sfTrue);
	sfSprite_setPosition(tileset, origin);

	//rectangle noir pour les tiles
	rectTile = sfRectangleShape_create();
	sfRectangleShape_setFillColor(rectTile, sfBlack);
	sfRectangleShape_setPosition(rectTile, rectpos);
	sfRectangleShape_setSize(rectTile, rectSize);

	//choix
	tileEditor = sfSprite_create();
	sfSprite_setTexture(tileEditor, textmap, sfTrue);
	sfSprite_setPosition(tileEditor, originEditor);
	
	//initialiser les case du tableau a 1 pour pas que la map soit invisible
	for (int x = 0; x < mapsizeX; x++)
	{
		for (int y = 0; y < mapsizeX; y++)
		{
			map[y][x] = 1;
		}
	}

	//innitialiser le tableau des tiles a selectionner
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			tileChoice[y][x] = i;
			i++;
		}
	}
}

void updateMap(sfRenderWindow* _window)
{
	//view map dezoome
	sfView_setCenter(viewEditor, posViewEditor);
	sfView_setSize(viewEditor, (sfVector2f) { mapsizeX* tilesize + 3 * tilesize, mapsizeY* tilesize + 3 * tilesize });

}

void displayMap(sfRenderWindow* _window)
{
	//view map dezoome
	sfRenderWindow_setView(_window, viewEditor);

	//valeurs
	int posx = 0;
	int posy = 0;
	sfVector2f origin = { 0.0f, 0.0f };

	int posEditorx = mapsizeX * tilesize;
	int posEditory = 0;
	sfVector2f originEditor = { (mapsizeX) * tilesize, tilesize };
	//dessiner la map
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

	//dessiner le rectangle noir pour les tiles
	sfRenderWindow_drawRectangleShape(_window, rectTile, NULL);

	//dessiner les tiles a selectionner
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			posEditorx = tileChoice[x][y] * tilesize;
			sfIntRect rectile = { posEditorx, posEditory, tilesize, tilesize };
			sfVector2f pos = { originEditor.x, originEditor.y };
			sfSprite_setTextureRect(tileEditor, rectile);
			sfSprite_setPosition(tileEditor, pos);
			sfRenderWindow_drawSprite(_window, tileEditor, NULL);
			originEditor.x += tilesize;

			if (originEditor.x >= 2 * tilesize + (mapsizeX) * tilesize)
			{
				originEditor.x = (mapsizeX) * tilesize;
				originEditor.y += tilesize;
			}
		}
	}
}

