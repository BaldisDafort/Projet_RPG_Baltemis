#include "editor.h"

//timer
float posTimer;
float timer;

//block selectionne
int blockGround = 0.0f;
int blockWall = 0.0f;

void initMap()
{
	//view map dezoome
	viewEditor.viewEditor = sfView_create();
	viewEditor.posViewEditor = (sfVector2f){ mapsizeX * tileSize / 2 + 1.5 * tileSize, mapsizeY * tileSize / 2 };
	viewEditor.rectViewEditor = (sfFloatRect){mapsizeX * tileSize / 2 + 1.5 * tileSize, mapsizeY * tileSize / 2, mapsizeX * tileSize, mapsizeY * tileSize};
	sfView_reset(viewEditor.viewEditor, viewEditor.rectViewEditor);

	//tilemap
	tilemap.rectile = (sfIntRect){ 0.0f, 0.0f, tileSize, tileSize };
	tilemap.pos = (sfVector2f){ 0.0f, 0.0f };
	tilemap.origin = (sfVector2f){ 0.0f, 0.0f };
	//tilesetGround
	tilemap.tilesetGround = sfSprite_create();
	tilemap.textmapGround = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetground.png", NULL);
	sfSprite_setTexture(tilemap.tilesetGround, tilemap.textmapGround, sfTrue);
	sfSprite_setPosition(tilemap.tilesetGround, tilemap.origin);
	//tilesetWall
	tilemap.tilesetWall = sfSprite_create();
	tilemap.textmapWall = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetwall.png", NULL);
	sfSprite_setTexture(tilemap.tilesetWall, tilemap.textmapWall, sfTrue);
	sfSprite_setPosition(tilemap.tilesetWall, tilemap.origin);


	//rectangle noir pour les tiles
	rectBlack.rectangle = sfRectangleShape_create();
	rectBlack.position = (sfVector2f){ (mapsizeX)*tileSize, -2*tileSize };
	rectBlack.size = (sfVector2f){ 3 * tileSize, mapsizeY * tileSize + 4*tileSize };
	sfRectangleShape_setFillColor(rectBlack.rectangle, sfBlack);
	sfRectangleShape_setPosition(rectBlack.rectangle, rectBlack.position);
	sfRectangleShape_setSize(rectBlack.rectangle, rectBlack.size);

	//tile choix
	tileEditor.tileEditorGround = sfSprite_create();
	tileEditor.tileEditorWall = sfSprite_create();
	tileEditor.posEditor = (sfVector2f){ 0.0f, 0.0f };
	tileEditor.originEditorGround = (sfVector2f){ (mapsizeX)*tileSize, tileSize };
	tileEditor.originEditorWall = (sfVector2f){ (mapsizeX)*tileSize, -1 * tileSize };
	sfSprite_setTexture(tileEditor.tileEditorGround, tilemap.textmapGround, sfTrue);
	sfSprite_setPosition(tileEditor.tileEditorGround, tileEditor.originEditorGround);
	sfSprite_setTexture(tileEditor.tileEditorWall, tilemap.textmapWall, sfTrue);
	sfSprite_setPosition(tileEditor.tileEditorWall, tileEditor.originEditorWall);

	//timer
	posTimer = 0.0f;
	timer = 0.0f;

	//innitialiser les tableau des tiles a selectionner
	int i = 0;
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			arr.tileGround[y][x] = i;
			i++;
		}
	}
	i = 0;
	for (int x = 0; x < 27; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			arr.tileWall[y][x] = i;
			i++;
		}
	}
}

void updateMap(sfRenderWindow* _window)
{
	//view map dezoome
	sfView_setCenter(viewEditor.viewEditor, viewEditor.posViewEditor);
	sfView_setSize(viewEditor.viewEditor, (sfVector2f) { mapsizeX* tileSize + 3 * tileSize, mapsizeY* tileSize + 3 * tileSize });

	sfVector2f originEditor = { (mapsizeX)*tileSize, tileSize };
	sfVector2i nexPosInTab = { 0, 0 };
	sfVector2i posMouse = sfMouse_getPositionRenderWindow(_window);
	sfVector2f worldGet = sfRenderWindow_mapPixelToCoords(_window, posMouse, viewEditor.viewEditor);

	sfSprite_setPosition(tileEditor.tileEditorGround, originEditor);
	sfSprite_setPosition(tileEditor.tileEditorWall, originEditor);

	posTimer += GetDeltaTime();

	if (sfMouse_isButtonPressed(sfMouseLeft) && posTimer >= 0.002f)
	{
		//recuperer les tuiles du ground
		if (worldGet.x > (mapsizeX)*tileSize && worldGet.x < originEditor.x + 2 * tileSize && worldGet.y < 13 * tileSize && worldGet.y > tileSize && currentTileset == GROUND)
		{
			worldGet.x -= (mapsizeX)*tileSize;
			worldGet.y -= tileSize;

			blockGround = arr.tileGround[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];

		}
		else if (worldGet.x > mapsizeX * tileSize) //recuperer les tuiles du wall
		{
			worldGet.x -= (mapsizeX)*tileSize;
			worldGet.y -= -1 * tileSize;
			switch (currentTileset)
			{
			case WALL:
				blockWall = arr.tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			case WALL1:
				blockWall = arr.tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			case WALL2:
				blockWall = arr.tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			case WALL3:
				blockWall = arr.tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				break;
			}
		}

		//poser les tuiles
		else if (worldGet.x < mapsizeX * tileSize)
		{
			nexPosInTab.x = worldGet.x / tileSize;
			nexPosInTab.y = worldGet.y / tileSize;

			switch (currentTileset)
			{
			case GROUND:
				arr.mapGround[nexPosInTab.y][nexPosInTab.x] = blockGround;
				break;
			case WALL:
				arr.mapWall[nexPosInTab.y][nexPosInTab.x] = blockWall;
				break;
			case WALL1:
				arr.mapWall1[nexPosInTab.y][nexPosInTab.x] = blockWall;
				break;
			case WALL2:
				arr.mapWall2[nexPosInTab.y][nexPosInTab.x] = blockWall;
				break;
			case WALL3:
				arr.mapWall3[nexPosInTab.y][nexPosInTab.x] = blockWall;
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

}

void displayMap(sfRenderWindow* _window)
{
	//view map dezoome
	sfRenderWindow_setView(_window, viewEditor.viewEditor);

	//valeurs
	int posGroundX = 0;
	int posWallX = 0;
	int posWall1X = 0;
	int posWall2X = 0;
	int posWall3X = 0;
	int posy = 0;
	sfVector2f origin = { 0.0f, 0.0f };
	//timer
	timer += GetDeltaTime();

	int posEditorx = mapsizeX * tileSize;
	int posEditory = 0;
	sfVector2f originEditorGround = { (mapsizeX)*tileSize, tileSize };
	sfVector2f originEditorWall = { (mapsizeX)*tileSize, -1 * tileSize };

	//dessiner la map
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			posGroundX = arr.mapGround[y][x] * tileSize;
			posWallX = arr.mapWall[y][x] * tileSize;
			posWall1X = arr.mapWall1[y][x] * tileSize;
			posWall2X = arr.mapWall2[y][x] * tileSize;
			posWall3X = arr.mapWall3[y][x] * tileSize;

			sfIntRect rectileGround = { posGroundX, posy, tileSize, tileSize };
			sfIntRect rectileWall = { posWallX, posy, tileSize, tileSize };
			sfIntRect rectileWall1 = { posWall1X, 1*  tileSize, tileSize, tileSize };
			sfIntRect rectileWall2 = { posWall2X, 2 * tileSize, tileSize, tileSize };
			sfIntRect rectileWall3 = { posWall3X, 3 * tileSize, tileSize, tileSize };
			sfVector2f pos = { origin.x, origin.y };
			//dessiner ground
			sfSprite_setPosition(tilemap.tilesetGround, pos);
			sfSprite_setTextureRect(tilemap.tilesetGround, rectileGround);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetGround, NULL);
			//dessiner wall
			sfSprite_setPosition(tilemap.tilesetWall, pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner wall1
			sfSprite_setPosition(tilemap.tilesetWall, pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall1);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner wall2
			sfSprite_setPosition(tilemap.tilesetWall, pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall2);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner wall3
			sfSprite_setPosition(tilemap.tilesetWall, pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall3);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);

			origin.x += tileSize;

			if (origin.x >= mapsizeX * tileSize)
			{
				origin.x = 0;
				origin.y += tileSize;
			}
		}
	}

	//dessiner le rectangle noir pour les tiles
	sfRenderWindow_drawRectangleShape(_window, rectBlack.rectangle, NULL);

	//dessiner les tiles a selectionner
	switch (currentTileset)
	{
	case GROUND:
		for (int y = 0; y < 12; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileGround[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, posEditory, tileSize, tileSize };
				sfVector2f pos = { originEditorGround.x, originEditorGround.y };
				sfSprite_setTextureRect(tileEditor.tileEditorGround, rectile);
				sfSprite_setPosition(tileEditor.tileEditorGround, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorGround, NULL);
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
				posEditorx = arr.tileWall[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, posEditory, tileSize, tileSize };
				sfVector2f pos = { originEditorWall.x, originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				originEditorWall.x += tileSize;

				if (originEditorWall.x >= 2 * tileSize + (mapsizeX)*tileSize)
				{
					originEditorWall.x = (mapsizeX)*tileSize;
					originEditorWall.y += tileSize;
				}
			}
		}
		break;
	case WALL1:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileWall[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, 1 * tileSize , tileSize, tileSize };
				sfVector2f pos = { originEditorWall.x, originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				originEditorWall.x += tileSize;

				if (originEditorWall.x >= 2 * tileSize + (mapsizeX)*tileSize)
				{
					originEditorWall.x = (mapsizeX)*tileSize;
					originEditorWall.y += tileSize;
				}
			}
		}
		break;
	case WALL2:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileWall[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, 2 * tileSize, tileSize, tileSize };
				sfVector2f pos = { originEditorWall.x, originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				originEditorWall.x += tileSize;

				if (originEditorWall.x >= 2 * tileSize + (mapsizeX)*tileSize)
				{
					originEditorWall.x = (mapsizeX)*tileSize;
					originEditorWall.y += tileSize;
				}
			}
		}
		break;
	case WALL3:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileWall[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, 3 * tileSize, tileSize, tileSize };
				sfVector2f pos = { originEditorWall.x, originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
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
