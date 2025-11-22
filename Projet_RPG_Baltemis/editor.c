#include "editor.h"

//timer
float firstPosTimer = 0.0f;
float posTimer;
float timer;

//block selectionne
int blockGround = 0.0f;
int blockWall = 0.0f;
int blockObjX = 0.0f;
int blockObjY = 0.0f;

//initialiser le tableau des tiles a selectionner pour les objets (que je gere un peut differemmen car je ne souhaite pas afficher toutes les tiles
int tileObj[22] = {  0, 2, 0, 6, 4, 6, 0, 2, 4, 6, 7,  1, 1, 1, 3, 3, 1, 1, 1, 1, 1 };
int tileObjY[22] = { 0, 1, 1, 0, 1, 1, 2, 2, 2, 2, 2, 3, 4, 5, 6, 8, 10, 11, 12, 13, 14, 15};

void initMap()
{
	//view map dezoome
	viewEditor.viewEditor = sfView_create();
	viewEditor.posViewEditor = (sfVector2f){ mapSizeX * tileSize / 2 + 1.5 * tileSize, mapSizeY * tileSize / 2 };
	viewEditor.rectViewEditor = (sfFloatRect){mapSizeX * tileSize / 2 + 1.5 * tileSize, mapSizeY * tileSize / 2, mapSizeX * tileSize, mapSizeY * tileSize};
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
	//tilesetObj
	tilemap.tilesetObj = sfSprite_create();
	tilemap.textmapObj = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetobj.png", NULL);
	sfSprite_setTexture(tilemap.tilesetObj, tilemap.textmapObj, sfTrue);
	sfSprite_setPosition(tilemap.tilesetObj, tilemap.origin);

	//rectangle noir pour les tiles
	rectBlack.rectangle = sfRectangleShape_create();
	rectBlack.position = (sfVector2f){ (mapSizeX)*tileSize, -2*tileSize };
	rectBlack.size = (sfVector2f){ 3 * tileSize, mapSizeY * tileSize + 4*tileSize };
	sfRectangleShape_setFillColor(rectBlack.rectangle, sfWhite); //mais finalement il est blanc
	sfRectangleShape_setPosition(rectBlack.rectangle, rectBlack.position);
	sfRectangleShape_setSize(rectBlack.rectangle, rectBlack.size);

	//tile choix
	tileEditor.tileEditorGround = sfSprite_create();
	tileEditor.tileEditorWall = sfSprite_create();
	tileEditor.tileEditorObj = sfSprite_create();
	tileEditor.posEditor = (sfVector2f){ 0.0f, 0.0f };
	tileEditor.posEditorObj = (sfVector2f){ 0.0f, 0.0f };
	tileEditor.originEditorGround = (sfVector2f){ (mapSizeX)*tileSize, tileSize };
	tileEditor.originEditorWall = (sfVector2f){ (mapSizeX)*tileSize, -1 * tileSize };
	
	sfSprite_setTexture(tileEditor.tileEditorGround, tilemap.textmapGround, sfTrue);
	sfSprite_setPosition(tileEditor.tileEditorGround, tileEditor.originEditorGround);
	sfSprite_setTexture(tileEditor.tileEditorWall, tilemap.textmapWall, sfTrue);
	sfSprite_setPosition(tileEditor.tileEditorWall, tileEditor.originEditorWall);
	sfSprite_setTexture(tileEditor.tileEditorObj, tilemap.textmapObj, sfTrue);
	sfSprite_setPosition(tileEditor.tileEditorObj, tileEditor.originEditorObj);

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
			arr.tileWall1[y][x] = i;
			arr.tileWall2[y][x] = i;
			arr.tileWall3[y][x] = i;
			i++;
		}
	}
}

void updateMap(sfRenderWindow* _window)
{

	if (state == EDITOR)
	{
		//view map dezoome
		sfView_setCenter(viewEditor.viewEditor, viewEditor.posViewEditor);
		sfView_setSize(viewEditor.viewEditor, (sfVector2f) { mapSizeX* tileSize + 3 * tileSize, mapSizeY* tileSize + 3 * tileSize });

		//timer
		timer += GetDeltaTime();

		sfVector2f originEditor = { (mapSizeX)*tileSize, tileSize };
		sfVector2i nexPosInTab = { 0, 0 };
		sfVector2i posMouse = sfMouse_getPositionRenderWindow(_window);
		sfVector2f worldGet = sfRenderWindow_mapPixelToCoords(_window, posMouse, viewEditor.viewEditor);

		sfSprite_setPosition(tileEditor.tileEditorGround, originEditor);
		sfSprite_setPosition(tileEditor.tileEditorWall, originEditor);
		sfSprite_setPosition(tileEditor.tileEditorObj, originEditor);

		posTimer += GetDeltaTime();

		if (sfMouse_isButtonPressed(sfMouseLeft) && posTimer >= 0.002f)
		{
			//recuperer les tuiles
			if (worldGet.x > (mapSizeX)*tileSize && worldGet.x < originEditor.x + 2 * tileSize && worldGet.y < 13 * tileSize && worldGet.y > tileSize && (currentTileset == GROUND || currentTileset == OBJ))
			{
				//recuperer les tuiles du ground
				currentTileset = GROUND;
				worldGet.x -= (mapSizeX)*tileSize;
				worldGet.y -= tileSize;

				blockGround = arr.tileGround[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];

			}
			else if (worldGet.x > (mapSizeX)*tileSize && worldGet.x < originEditor.x + 2 * tileSize && worldGet.y > 13 * tileSize && worldGet.y <= 25 * tileSize && (currentTileset == GROUND || currentTileset == OBJ))
			{
				//recuperer les tuiles des objets
				currentTileset = OBJ;
				worldGet.x -= (mapSizeX)*tileSize;
				worldGet.y -= 14 * tileSize;
				blockObjX = tileObj[((int)worldGet.x / tileSize) + ((int)worldGet.y / tileSize*2)];
				blockObjY = tileObjY[((int)worldGet.x / tileSize) + ((int)worldGet.y / tileSize*2)];
			}
			else if (worldGet.x > mapSizeX * tileSize)
			{
				//recuperer les tuiles du wall
				worldGet.x -= (mapSizeX)*tileSize;
				worldGet.y -= -1 * tileSize;
				blockWall = arr.tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				blockWall = arr.tileWall1[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				blockWall = arr.tileWall2[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				blockWall = arr.tileWall3[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
				switch (currentTileset)
				{
				case WALL:
					blockWall = arr.tileWall[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
					break;
				case WALL1:
					blockWall = arr.tileWall1[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
					break;
				case WALL2:
					blockWall = arr.tileWall2[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
					break;
				case WALL3:
					blockWall = arr.tileWall3[(int)worldGet.x / tileSize][(int)worldGet.y / tileSize];
					break;
				}
			}

		//poser les tuiles
		else if (worldGet.x < mapSizeX * tileSize && worldGet.x > 0 && worldGet.y > 0 && worldGet.y < mapSizeY * tileSize && firstPosTimer > 0.2f)
		{
			nexPosInTab.x = worldGet.x / tileSize;
			nexPosInTab.y = worldGet.y / tileSize;

			switch (currentTileset)
			{
			case GROUND:
				arr.mapGround[nexPosInTab.y][nexPosInTab.x] = blockGround;
				break;
			case OBJ:
				arr.mapObj[nexPosInTab.y][nexPosInTab.x] = (sfVector2i){ blockObjX, blockObjY };
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

	//gestion des boutons pour changer de tileset ou de map
		if ((sfKeyboard_isScancodePressed(sfScanUp)) && (timer >= 0.2f))
		{
			if (currentTileset == GROUND || currentTileset == OBJ)
				currentTileset = WALL3;
			else
				currentTileset--;
			timer = 0.0f;
		}
		else if ((sfKeyboard_isScancodePressed(sfScanDown)) && (timer >= 0.2f))
		{
			if (currentTileset == WALL3)
				currentTileset = GROUND;
			else if (currentTileset == GROUND)
				currentTileset = WALL;
			else
				currentTileset++;
			timer = 0.0f;
		}
		if ((sfKeyboard_isScancodePressed(sfScanRight)) && (timer >= 0.2f))
		{
			saveMap();
			if (currentMap == MAP3)
				currentMap = MAP;
			else
				currentMap++;
			printf(" Current Map : %d \n", currentMap);
			loadMap();
			timer = 0.0f;
		}
		else if ((sfKeyboard_isScancodePressed(sfScanLeft)) && (timer >= 0.2f))
		{
			saveMap();
			if (currentMap == MAP)
				currentMap = MAP3;
			else
				currentMap--;
			printf(" Current Map : %d \n", currentMap);
			loadMap();
			timer = 0.0f;
		}
		//gestion des bouton pour save and load
		if ((sfKeyboard_isScancodePressed(sfScanS)) && (timer >= 0.2f))
		{
			saveMap();
			timer = 0.0f;
		}
		else if ((sfKeyboard_isScancodePressed(sfScanL)) && (timer >= 0.2f))
		{
			loadMap();
			timer = 0.0f;
		}
	}
}

void displayMap(sfRenderWindow* _window)
{

	//valeurs
	int posGroundX = 0;
	int posWallX = 0;
	int posWall1X = 0;
	int posWall2X = 0;
	int posWall3X = 0;
	int posObjX = 0;
	int posObjY = 0;
	int posy = 0;
	tilemap.origin = (sfVector2f){ 0.0f, 0.0f };

	int posEditorx = mapSizeX * tileSize;
	int posEditory = 0;


	//dessiner la map
	for (int y = 0; y < mapSizeY; y++)
	{
		for (int x = 0; x < mapSizeX; x++)
		{
			posGroundX = arr.mapGround[y][x] * tileSize;
			posObjX = arr.mapObj[y][x].x * tileSize;
			posObjY = arr.mapObj[y][x].y * tileSize;
			posWallX = arr.mapWall[y][x] * tileSize;
			posWall1X = arr.mapWall1[y][x] * tileSize;
			posWall2X = arr.mapWall2[y][x] * tileSize;
			posWall3X = arr.mapWall3[y][x] * tileSize;

			sfIntRect rectileGround = { posGroundX, posy, tileSize, tileSize };
			sfIntRect rectileObj = { posObjX, posObjY, tileSize, tileSize };
			sfIntRect rectileWall = { posWallX, posy, tileSize, tileSize };
			sfIntRect rectileWall1 = { posWall1X, 1*  tileSize, tileSize, tileSize };
			sfIntRect rectileWall2 = { posWall2X, 2 * tileSize, tileSize, tileSize };
			sfIntRect rectileWall3 = { posWall3X, 3 * tileSize, tileSize, tileSize };
			tilemap.pos = (sfVector2f){ tilemap.origin.x, tilemap.origin.y };
			//dessiner ground
			sfSprite_setPosition(tilemap.tilesetGround, tilemap.pos);
			sfSprite_setTextureRect(tilemap.tilesetGround, rectileGround);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetGround, NULL);
			//dessiner wall
			sfSprite_setPosition(tilemap.tilesetWall, tilemap.pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner wall1
			sfSprite_setPosition(tilemap.tilesetWall, tilemap.pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall1);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner wall2
			sfSprite_setPosition(tilemap.tilesetWall, tilemap.pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall2);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner wall3
			sfSprite_setPosition(tilemap.tilesetWall, tilemap.pos);
			sfSprite_setTextureRect(tilemap.tilesetWall, rectileWall3);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetWall, NULL);
			//dessiner object
			sfSprite_setPosition(tilemap.tilesetObj, tilemap.pos);
			sfSprite_setTextureRect(tilemap.tilesetObj, rectileObj);
			sfRenderWindow_drawSprite(_window, tilemap.tilesetObj, NULL);

			tilemap.origin.x += tileSize;

			if (tilemap.origin.x >= mapSizeX * tileSize)
			{
				tilemap.origin.x = 0;
				tilemap.origin.y += tileSize;
			}
		}
	}
}

void displayEditor(sfRenderWindow* _window)
{
	//valeurs
	int posy = 0;
	int posObjY = 9 * tileSize;
	tilemap.origin = (sfVector2f){ 0.0f, 0.0f };

	int posEditorx = mapSizeX * tileSize;
	int posEditory = 0;
	tileEditor.originEditorGround = (sfVector2f){ (mapSizeX)*tileSize, tileSize };
	tileEditor.originEditorWall = (sfVector2f){ (mapSizeX)*tileSize, -1 * tileSize };
	tileEditor.originEditorObj = (sfVector2f){ (mapSizeX)*tileSize, -8 * tileSize };

	//view map dezoome
	sfRenderWindow_setView(_window, viewEditor.viewEditor);
	//dessiner rectangle noir
	sfRectangleShape_setPosition(rectBlack.rectangle, rectBlack.position);
	sfRenderWindow_drawRectangleShape(_window, rectBlack.rectangle, NULL);
	//dessiner tile choix
	sfSprite_setPosition(tileEditor.tileEditorGround, tileEditor.originEditorGround);
	sfRenderWindow_drawSprite(_window, tileEditor.tileEditorGround, NULL);
	sfSprite_setPosition(tileEditor.tileEditorWall, tileEditor.originEditorWall);
	sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
	sfSprite_setPosition(tileEditor.tileEditorObj, tileEditor.originEditorObj);
	sfRenderWindow_drawSprite(_window, tileEditor.tileEditorObj, NULL);

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
				sfVector2f pos = { tileEditor.originEditorGround.x, tileEditor.originEditorGround.y };
				sfSprite_setTextureRect(tileEditor.tileEditorGround, rectile);
				sfSprite_setPosition(tileEditor.tileEditorGround, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorGround, NULL);
				tileEditor.originEditorGround.x += tileSize;

				if (tileEditor.originEditorGround.x >= 2 * tileSize + (mapSizeX)*tileSize)
				{
					tileEditor.originEditorGround.x = (mapSizeX)*tileSize;
					tileEditor.originEditorGround.y += tileSize;
				}
			}
		}

		// Positionner le panneau des objets juste en dessous des grounds
		tileEditor.originEditorObj.x = (mapSizeX)*tileSize;
		tileEditor.originEditorObj.y = 13 * tileSize + tileSize;

		for (int x = 0; x < 22; x++)
		{
			posEditorx = tileObj[x] * tileSize;
			sfIntRect rectile = { posEditorx, tileObjY[x] * tileSize, tileSize, tileSize };
			sfVector2f pos = { tileEditor.originEditorObj.x, tileEditor.originEditorObj.y };
			sfSprite_setTextureRect(tileEditor.tileEditorObj, rectile);
			sfSprite_setPosition(tileEditor.tileEditorObj, pos);
			sfRenderWindow_drawSprite(_window, tileEditor.tileEditorObj, NULL);
			tileEditor.originEditorObj.x += tileSize;

			if (tileEditor.originEditorObj.x >= 2 * tileSize + (mapSizeX)*tileSize)
			{
				tileEditor.originEditorObj.x = (mapSizeX)*tileSize;
				tileEditor.originEditorObj.y += tileSize;
			}
		}
		break;
	case OBJ://le meme parce que il accepte pas que je fasse 'case GROUND || OBJ:' ( c'est injuste !)

		for (int y = 0; y < 12; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileGround[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, posEditory, tileSize, tileSize };
				sfVector2f pos = { tileEditor.originEditorGround.x, tileEditor.originEditorGround.y };
				sfSprite_setTextureRect(tileEditor.tileEditorGround, rectile);
				sfSprite_setPosition(tileEditor.tileEditorGround, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorGround, NULL);
				tileEditor.originEditorGround.x += tileSize;

				if (tileEditor.originEditorGround.x >= 2 * tileSize + (mapSizeX)*tileSize)
				{
					tileEditor.originEditorGround.x = (mapSizeX)*tileSize;
					tileEditor.originEditorGround.y += tileSize;
				}
			}
		}

		// Positionner le panneau des objets juste en dessous des grounds
		tileEditor.originEditorObj.x = (mapSizeX)*tileSize;
		tileEditor.originEditorObj.y = 13 * tileSize + tileSize;

		for (int x = 0; x < 22; x++)
		{
			posEditorx = tileObj[x] * tileSize;
			sfIntRect rectile = { posEditorx, tileObjY[x] * tileSize, tileSize, tileSize };
			sfVector2f pos = { tileEditor.originEditorObj.x, tileEditor.originEditorObj.y };
			sfSprite_setTextureRect(tileEditor.tileEditorObj, rectile);
			sfSprite_setPosition(tileEditor.tileEditorObj, pos);
			sfRenderWindow_drawSprite(_window, tileEditor.tileEditorObj, NULL);
			tileEditor.originEditorObj.x += tileSize;

			if (tileEditor.originEditorObj.x >= 2 * tileSize + (mapSizeX)*tileSize)
			{
				tileEditor.originEditorObj.x = (mapSizeX)*tileSize;
				tileEditor.originEditorObj.y += tileSize;
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
				sfVector2f pos = { tileEditor.originEditorWall.x, tileEditor.originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				tileEditor.originEditorWall.x += tileSize;

				if (tileEditor.originEditorWall.x >= 2 * tileSize + (mapSizeX)*tileSize)
				{
					tileEditor.originEditorWall.x = (mapSizeX)*tileSize;
					tileEditor.originEditorWall.y += tileSize;
				}
			}
		}
		break;
	case WALL1:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileWall1[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, 1 * tileSize , tileSize, tileSize };
				sfVector2f pos = { tileEditor.originEditorWall.x, tileEditor.originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				tileEditor.originEditorWall.x += tileSize;

				if (tileEditor.originEditorWall.x >= 2 * tileSize + (mapSizeX)*tileSize)
				{
					tileEditor.originEditorWall.x = (mapSizeX)*tileSize;
					tileEditor.originEditorWall.y += tileSize;
				}
			}
		}
		break;
	case WALL2:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileWall2[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, 2 * tileSize, tileSize, tileSize };
				sfVector2f pos = { tileEditor.originEditorWall.x, tileEditor.originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				tileEditor.originEditorWall.x += tileSize;

				if (tileEditor.originEditorWall.x >= 2 * tileSize + (mapSizeX)*tileSize)
				{
					tileEditor.originEditorWall.x = (mapSizeX)*tileSize;
					tileEditor.originEditorWall.y += tileSize;
				}
			}
		}
		break;
	case WALL3:
		for (int y = 0; y < 27; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				posEditorx = arr.tileWall3[x][y] * tileSize;
				sfIntRect rectile = { posEditorx, 3 * tileSize, tileSize, tileSize };
				sfVector2f pos = { tileEditor.originEditorWall.x, tileEditor.originEditorWall.y };
				sfSprite_setTextureRect(tileEditor.tileEditorWall, rectile);
				sfSprite_setPosition(tileEditor.tileEditorWall, pos);
				sfRenderWindow_drawSprite(_window, tileEditor.tileEditorWall, NULL);
				tileEditor.originEditorWall.x += tileSize;

				if (tileEditor.originEditorWall.x >= 2 * tileSize + (mapSizeX)*tileSize)
				{
					tileEditor.originEditorWall.x = (mapSizeX)*tileSize;
					tileEditor.originEditorWall.y += tileSize;
				}
			}
		}
		break;
	}
}

//save and load
void saveMap()
{
	// on doit pas declarer une fonction juste apres un case d un switch apparemment donc je fais comme ca (visual studio m'aime pas je crois)
	FILE* fileGroundMap;
	FILE* fileGroundMap1;
	FILE* fileGroundMap2;
	FILE* fileGroundMap3;
	switch (currentMap)
	{
	case MAP:
		//save map ground
		fileGroundMap = fopen("groundMap.bin", "wb");
		fwrite(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap);
		fclose(fileGroundMap);
		//save map wall
		FILE* fileWallMap = fopen("basicMap.bin", "wb");
		fwrite(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap);
		fclose(fileWallMap);
		//save map wall1
		FILE* fileWallSkeletonMap = fopen("skeletonMap.bin", "wb");
		fwrite(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap);
		fclose(fileWallSkeletonMap);
		//save map wall2
		FILE* fileWallToxicMap = fopen("toxicMap.bin", "wb");
		fwrite(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap);
		fclose(fileWallToxicMap);
		//save map wall3
		FILE* fileWallLavaMap = fopen("lavaMap.bin", "wb");
		fwrite(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap);
		fclose(fileWallLavaMap);
		//save map obj
		FILE * fileObjMap = fopen("objMap.bin", "wb");
		fwrite(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap);
		fclose(fileObjMap);
		break;

	case MAP1:
		//save map ground
		fileGroundMap1 = fopen("groundMap1.bin", "wb");
		fwrite(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap1);
		fclose(fileGroundMap1);
		//save map wall
		FILE* fileWallMap1 = fopen("basicMap1.bin", "wb");
		fwrite(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap1);
		fclose(fileWallMap1);
		//save map wall1
		FILE* fileWallSkeletonMap1 = fopen("skeletonMap1.bin", "wb");
		fwrite(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap1);
		fclose(fileWallSkeletonMap1);
		//save map wall2
		FILE* fileWallToxicMap1 = fopen("toxicMap1.bin", "wb");
		fwrite(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap1);
		fclose(fileWallToxicMap1);
		//save map wall3
		FILE* fileWallLavaMap1 = fopen("lavaMap1.bin", "wb");
		fwrite(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap1);
		fclose(fileWallLavaMap1);
		//save map obj
		FILE* fileObjMap1 = fopen("objMap1.bin", "wb");
		fwrite(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap1);
		fclose(fileObjMap1);
		break;

	case MAP2:
		//save map ground
		fileGroundMap2 = fopen("groundMap2.bin", "wb");
		fwrite(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap2);
		fclose(fileGroundMap2);
		//save map wall
		FILE* fileWallMap2 = fopen("basicMap2.bin", "wb");
		fwrite(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap2);
		fclose(fileWallMap2);
		//save map wall1
		FILE* fileWallSkeletonMap2 = fopen("skeletonMap2.bin", "wb");
		fwrite(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap2);
		fclose(fileWallSkeletonMap2);
		//save map wall2
		FILE* fileWallToxicMap2 = fopen("toxicMap2.bin", "wb");
		fwrite(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap2);
		fclose(fileWallToxicMap2);
		//save map wall3
		FILE* fileWallLavaMap2 = fopen("lavaMap2.bin", "wb");
		fwrite(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap2);
		fclose(fileWallLavaMap2);
		FILE* fileObjMap2 = fopen("objMap2.bin", "wb");
		fwrite(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap2);
		fclose(fileObjMap2);
		break;

	case MAP3:
		//save map ground
		fileGroundMap3 = fopen("groundMap3.bin", "wb");
		fwrite(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap3);
		fclose(fileGroundMap3);
		//save map wall
		FILE* fileWallMap3 = fopen("basicMap3.bin", "wb");
		fwrite(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap3);
		fclose(fileWallMap3);
		//save map wall1
		FILE* fileWallSkeletonMap3 = fopen("skeletonMap3.bin", "wb");
		fwrite(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap3);
		fclose(fileWallSkeletonMap3);
		//save map wall2
		FILE* fileWallToxicMap3 = fopen("toxicMap3.bin", "wb");
		fwrite(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap3);
		fclose(fileWallToxicMap3);
		//save map wall3
		FILE* fileWallLavaMap3 = fopen("lavaMap3.bin", "wb");
		fwrite(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap3);
		fclose(fileWallLavaMap3);
		FILE* fileObjMap3 = fopen("objMap3.bin", "wb");
		fwrite(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap3);
		fclose(fileObjMap3);
		break;
	}
}

void loadMap()
{
	// on doit pas declarer une fonction juste apres un case d un switch apparemment donc je fais comme ca (visual studio m'aime pas je crois)
	FILE* fileGroundMap;
	FILE* fileGroundMap1;
	FILE* fileGroundMap2;
	FILE* fileGroundMap3;
	switch (currentMap)
	{
	case MAP:
		//save map ground
		fileGroundMap = fopen("groundMap.bin", "rb");
		fread(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap);
		fclose(fileGroundMap);
		//save map wall
		FILE* fileWallMap = fopen("basicMap.bin", "rb");
		fread(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap);
		fclose(fileWallMap);
		//save map wall1
		FILE* fileWallSkeletonMap = fopen("skeletonMap.bin", "rb");
		fread(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap);
		fclose(fileWallSkeletonMap);
		//save map wall2
		FILE* fileWallToxicMap = fopen("toxicMap.bin", "rb");
		fread(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap);
		fclose(fileWallToxicMap);
		//save map wall3
		FILE* fileWallLavaMap = fopen("lavaMap.bin", "rb");
		fread(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap);
		fclose(fileWallLavaMap);
		//save map obj
		FILE* fileObjMap = fopen("objMap.bin", "rb");
		fread(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap);
		fclose(fileObjMap);
		break;

	case MAP1:
		//save map ground
		fileGroundMap1 = fopen("groundMap1.bin", "rb");
		fread(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap1);
		fclose(fileGroundMap1);
		//save map wall
		FILE* fileWallMap1 = fopen("basicMap1.bin", "rb");
		fread(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap1);
		fclose(fileWallMap1);
		//save map wall1
		FILE* fileWallSkeletonMap1 = fopen("skeletonMap1.bin", "rb");
		fread(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap1);
		fclose(fileWallSkeletonMap1);
		//save map wall2
		FILE* fileWallToxicMap1 = fopen("toxicMap1.bin", "rb");
		fread(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap1);
		fclose(fileWallToxicMap1);
		//save map wall3
		FILE* fileWallLavaMap1 = fopen("lavaMap1.bin", "rb");
		fread(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap1);
		fclose(fileWallLavaMap1);
		//save map obj
		FILE* fileObjMap1 = fopen("objMap1.bin", "rb");
		fread(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap1);
		fclose(fileObjMap1);
		break;

	case MAP2:
		//save map ground
		fileGroundMap2 = fopen("groundMap2.bin", "rb");
		fread(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap2);
		fclose(fileGroundMap2);
		//save map wall
		FILE* fileWallMap2 = fopen("basicMap2.bin", "rb");
		fread(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap2);
		fclose(fileWallMap2);
		//save map wall1
		FILE* fileWallSkeletonMap2 = fopen("skeletonMap2.bin", "rb");
		fread(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap2);
		fclose(fileWallSkeletonMap2);
		//save map wall2
		FILE* fileWallToxicMap2 = fopen("toxicMap2.bin", "rb");
		fread(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap2);
		fclose(fileWallToxicMap2);
		//save map wall3
		FILE* fileWallLavaMap2 = fopen("lavaMap2.bin", "rb");
		fread(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap2);
		fclose(fileWallLavaMap2);
		//save map obj
		FILE* fileObjMap2 = fopen("objMap2.bin", "rb");
		fread(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap2);
		fclose(fileObjMap2);
		break;

	case MAP3:
		//save map ground
		fileGroundMap3 = fopen("groundMap3.bin", "rb");
		fread(arr.mapGround, sizeof(int), mapSizeX * mapSizeY, fileGroundMap3);
		fclose(fileGroundMap3);
		//save map wall
		FILE* fileWallMap3 = fopen("basicMap3.bin", "rb");
		fread(arr.mapWall, sizeof(int), mapSizeX * mapSizeY, fileWallMap3);
		fclose(fileWallMap3);
		//save map wall1
		FILE* fileWallSkeletonMap3 = fopen("skeletonMap3.bin", "rb");
		fread(arr.mapWall1, sizeof(int), mapSizeX * mapSizeY, fileWallSkeletonMap3);
		fclose(fileWallSkeletonMap3);
		//save map wall2
		FILE* fileWallToxicMap3 = fopen("toxicMap3.bin", "rb");
		fread(arr.mapWall2, sizeof(int), mapSizeX * mapSizeY, fileWallToxicMap3);
		fclose(fileWallToxicMap3);
		//save map wall3
		FILE* fileWallLavaMap3 = fopen("lavaMap3.bin", "rb");
		fread(arr.mapWall3, sizeof(int), mapSizeX * mapSizeY, fileWallLavaMap3);
		fclose(fileWallLavaMap3);
		//save map obj
		FILE* fileObjMap3 = fopen("objMap3.bin", "rb");
		fread(arr.mapObj, sizeof arr.mapObj[0][0], mapSizeX * mapSizeY, fileObjMap3);
		fclose(fileObjMap3);
		break;
	}
}
