#include "editor.h"

//view map dezoome
sfView* viewEditor;
sfVector2f posViewEditor = { mapsizeX * tileSize / 2 + 1.5 * tileSize, mapsizeY * tileSize / 2 };
sfFloatRect rectViewEditor = { mapsizeX * tileSize / 2 + 1.5 * tileSize, mapsizeY * tileSize / 2, mapsizeX * tileSize, mapsizeY * tileSize };

//tilemap
sfSprite* tilesetGround;
sfTexture* textmapGround;
sfSprite* tilesetWall;
sfTexture* textmapWall;
sfIntRect rectile = { 0, 0, tileSize, tileSize };
sfVector2f pos = { 0.0f, 0.0f };
sfVector2f origin = { 0.0f, 0.0f };


//rectangle noir pour les tiles
sfRectangleShape* rectTile;
sfVector2f rectpos = { (mapsizeX) * tileSize, -2*tileSize };
sfVector2f rectSize = { 3 * tileSize, mapsizeY * tileSize + 4*tileSize};

//tile choix
sfSprite* tileEditorGround;
sfSprite* tileEditorWall;
sfVector2f posEditor = { 0.0f, 0.0f };
sfVector2f originEditorGround = { (mapsizeX) * tileSize, tileSize };
sfVector2f originEditorWall = { (mapsizeX)*tileSize, -1*tileSize };


//tableau
int mapGround[mapsizeY][mapsizeX];
int mapWall[mapsizeY][mapsizeX];
int tileGround[2][13];
int tileWall[2][28];
int tileWall1[2][28];
int tileWall2[2][28];
int tileWall3[2][28];

//timer
float posTimer = 0.0f;
float timer = 0.0f;

//block selectionne
int blockGround = 0.0f;
int blockWall = 0.0f;

void initMap()
{
	//view map dezoome
	viewEditor = sfView_create();
	sfView_reset(viewEditor, rectViewEditor);

	//int i
	int i = 0;

	//tilesetGround
	tilesetGround = sfSprite_create();
	textmapGround = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetground.png", NULL);
	sfSprite_setTexture(tilesetGround, textmapGround, sfTrue);
	sfSprite_setPosition(tilesetGround, origin);
	//tilesetWall 
	tilesetWall = sfSprite_create();
	textmapWall = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetwall.png", NULL);
	sfSprite_setTexture(tilesetWall, textmapWall, sfTrue);
	sfSprite_setPosition(tilesetWall, origin);
	

	//rectangle noir pour les tiles
	rectTile = sfRectangleShape_create();
	sfRectangleShape_setFillColor(rectTile, sfBlack);
	sfRectangleShape_setPosition(rectTile, rectpos);
	sfRectangleShape_setSize(rectTile, rectSize);

	//choix
	tileEditorGround = sfSprite_create();
	sfSprite_setTexture(tileEditorGround, textmapGround, sfTrue);
	sfSprite_setPosition(tileEditorGround, originEditorGround);
	tileEditorWall = sfSprite_create();
	sfSprite_setTexture(tileEditorWall, textmapWall, sfTrue);
	sfSprite_setPosition(tileEditorWall, originEditorWall);

	//innitialiser les tableau des tiles a selectionner
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			tileGround[y][x] = i;
			i++;
		}
	}
	i = 0;
	for (int x = 0; x < 27; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			tileWall[y][x] = i;
			tileWall1[y][x] = i;
			tileWall2[y][x] = i;
			tileWall3[y][x] = i;	
			i++;
		}
	}
}

void updateMap(sfRenderWindow* _window)
{
	//view map dezoome
	sfView_setCenter(viewEditor, posViewEditor);
	sfView_setSize(viewEditor, (sfVector2f) { mapsizeX* tileSize + 3 * tileSize, mapsizeY* tileSize + 3 * tileSize });

	sfVector2f originEditor = { (mapsizeX) * tileSize, tileSize };
	sfVector2i nexPosInTab = { 0, 0 };
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_window);
	sfVector2f worldGet = sfRenderWindow_mapPixelToCoords(_window, posMouse, viewEditor);

	sfSprite_setPosition(tileEditorGround, originEditor);
	sfSprite_setPosition(tileEditorWall, originEditor);

	posTimer += GetDeltaTime();

	if (sfMouse_isButtonPressed(sfMouseLeft) && posTimer >= 0.002f)
	{
		//recuperer les tuiles du ground
		if (worldGet.x > (mapsizeX) * tileSize && worldGet.x < originEditor.x + 2*tileSize && worldGet.y < 13 * tileSize && worldGet.y > tileSize && currentTileset == GROUND)
		{
			worldGet.x -= (mapsizeX) * tileSize;
			worldGet.y -= tileSize;

			blockGround = tileGround[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];

		}
		else if (worldGet.x > mapsizeX * tileSize) //recuperer les tuiles du wall
		{
			worldGet.x -= (mapsizeX)*tileSize;
			worldGet.y -= -1*tileSize;
			switch (currentTileset)
			{
			case WALL:
				blockWall = tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			case WALL1:
				blockWall = tileWall1[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			case WALL2:
				blockWall = tileWall2[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			case WALL3:
				blockWall = tileWall3[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			}
			printf("%d", blockGround);
		}

		//poser les tuiles
		else if (worldGet.x < mapsizeX * tileSize)
		{
			nexPosInTab.x = worldGet.x / tileSize;
			nexPosInTab.y = worldGet.y / tileSize;

			switch (currentTileset)
			{
			case GROUND:
				mapGround[nexPosInTab.y][nexPosInTab.x] = blockGround;
				break;
			default:
				mapWall[nexPosInTab.y][nexPosInTab.x] = blockWall;
				break;
			}
		}

		posTimer = 0.0f;
	}

	if ((sfKeyboard_isScancodePressed(sfScanUp)) && (timer >= 0.2f))
	{
		if (currentTileset == GROUND)
			currentTileset = WALL3;
		else
			currentTileset--;
		timer = 0.0f;
	}
	else if ((sfKeyboard_isScancodePressed(sfScanDown)) && (timer >= 0.2f))
	{
		if (currentTileset == WALL3)
			currentTileset = GROUND;
		else
			currentTileset++;
		timer = 0.0f;
	}

	sfVector2f originEditor = { (mapsizeX) * tilesize, tilesize };
	sfVector2i nexPosInTab = { 0, 0 };
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_window);
	sfVector2f worldGet = sfRenderWindow_mapPixelToCoords(_window, posMouse, viewEditor);

	sfSprite_setPosition(tileEditor, originEditor);

	posTimer += GetDeltaTime();

	if (sfMouse_isButtonPressed(sfMouseLeft) && posTimer >= 0.002f)
	{
		//recuperer les tuiles
		if (worldGet.x > (mapsizeX) * tilesize && worldGet.x < originEditor.x + 2*tilesize && worldGet.y < 13 * tilesize && worldGet.y > tilesize)
		{
			worldGet.x -= (mapsizeX) * tilesize;
			worldGet.y -= tilesize;

			block = tileChoice[(int)worldGet.x / tilesize][(int)worldGet.y / tilesize];
		}


		//poser les tuiles
		else if (worldGet.x < mapsizeX * tilesize)
		{
			nexPosInTab.x = worldGet.x / tilesize;
			nexPosInTab.y = worldGet.y / tilesize;

			map[nexPosInTab.y][nexPosInTab.x] = block;
		}

		posTimer = 0.0f;
	}

}

void displayMap(sfRenderWindow* _window)
{
	//view map dezoome
	sfRenderWindow_setView(_window, viewEditor);

	//valeurs
	int posGroundX = 0;
	int posWallX = 0;
	int posy = 0;
	sfVector2f origin = { 0.0f, 0.0f };
	//timer
	timer += GetDeltaTime();

	int posEditorx = mapsizeX * tileSize;
	int posEditory = 0;
	sfVector2f originEditorGround = { (mapsizeX) * tileSize, tileSize };
	sfVector2f originEditorWall = { (mapsizeX)*tileSize, -1*tileSize };

	//dessiner la map
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			posGroundX = mapGround[y][x] * tileSize;
			posWallX = mapWall[y][x] * tileSize;
			sfIntRect rectileGround = { posGroundX, posy, tileSize, tileSize };
			sfIntRect rectileWall = { posWallX, posy, tileSize, tileSize };
			sfVector2f pos = { origin.x, origin.y };
				sfSprite_setPosition(tilesetGround, pos);
				sfSprite_setTextureRect(tilesetGround, rectileGround);
				sfRenderWindow_drawSprite(_window, tilesetGround, NULL);
				sfSprite_setPosition(tilesetWall, pos);
				sfSprite_setTextureRect(tilesetWall, rectileWall);
				sfRenderWindow_drawSprite(_window, tilesetWall, NULL);

			origin.x += tileSize;

			if (origin.x >= mapsizeX * tileSize)
			{
				origin.x = 0;
				origin.y += tileSize;
			}
		}
	}

	//dessiner le rectangle noir pour les tiles
	sfRenderWindow_drawRectangleShape(_window, rectTile, NULL);

	//dessiner les tiles a selectionner
	switch (currentTileset)
	{
	case GROUND:
		for (int y = 0; y < 12; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = tileGround[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, posEditory, tileSize, tileSize };
				sfVector2f pos = { originEditorGround.x, originEditorGround.y };
				sfSprite_setTextureRect(tileEditorGround, rectile);
				sfSprite_setPosition(tileEditorGround, pos);
				sfRenderWindow_drawSprite(_window, tileEditorGround, NULL);
				originEditorGround.x += tileSize;

				if (originEditorGround.x >= 2 * tileSize + (mapsizeX)*tileSize)
				{
					originEditorGround.x = (mapsizeX)*tileSize;
					originEditorGround.y += tileSize;
				}
			}
		}
		break;

	case WALL:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = tileWall[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, posEditory, tileSize, tileSize };
				sfVector2f pos = { originEditorWall.x, originEditorWall.y };
				sfSprite_setTextureRect(tileEditorWall, rectile);
				sfSprite_setPosition(tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditorWall, NULL);
				originEditorWall.x += tileSize;

				if (originEditorWall.x >= 2 * tileSize + (mapsizeX)*tileSize)
				{
					originEditorWall.x = (mapsizeX)*tileSize;
					originEditorWall.y += tileSize;
				}
			}
		}
		break;
	}
}

