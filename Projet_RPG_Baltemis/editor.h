#pragma once

#include "tools.h"

#define mapSizeX 34
#define mapSizeY 25
#define tileSize 16

//tileset
typedef enum Tileset Tileset;
typedef enum Tileset
{ 
	GROUND,
	OBJ,
	SPAWN,
	WALL,
	WALL1, 
	WALL2, 
	WALL3,
};
Tileset currentTileset;

//map
typedef enum Map
{
	MAP,
	MAP1,
	MAP2,
	MAP3,

}Map;
Map currentMap;


typedef struct ViewEditor
{
	//view editor (dezomme)
	sfView* viewEditor;
	sfVector2f posViewEditor;
	sfFloatRect rectViewEditor;

}ViewEditor;
ViewEditor viewEditor;

typedef struct Tilemap
{
	//tilemap
	sfSprite* tilesetGround;
	sfTexture* textmapGround;
	sfSprite* tilesetWall;
	sfTexture* textmapWall;
	sfSprite* tilesetSpawn;
	sfTexture* textmapSpawn;
	sfSprite* tilesetObj;
	sfTexture* textmapObj;
	sfIntRect rectile;
	sfVector2f pos;
	sfVector2f origin;

}Tilemap;
Tilemap tilemap;

typedef struct TileEditor
{
	//tile choix
	sfSprite* tileEditorGround;
	sfSprite* tileEditorWall;
	sfSprite* tileEditorObj;
	sfSprite* tileEditorSpawn;
	sfVector2f posEditor;
	sfVector2f posEditorObj;
	sfVector2f originEditorGround;
	sfVector2f originEditorWall;
	sfVector2f originEditorObj;
	sfVector2f originEditorSpawn;

}TileEditor;
TileEditor tileEditor;

typedef struct rectangleBlack
{
	sfRectangleShape* rectangle;
	sfVector2f position;
	sfVector2f size;

}rectangleBlack;
rectangleBlack rectBlack;

typedef struct Array
{
	//tableau
	int mapGround[mapSizeY][mapSizeX];
	int mapSpawn[mapSizeY][mapSizeX];
	sfVector2i mapObj[mapSizeY][mapSizeX];
	int mapWall[mapSizeY][mapSizeX];
	int mapWall1[mapSizeY][mapSizeX];
	int mapWall2[mapSizeY][mapSizeX];
	int mapWall3[mapSizeY][mapSizeX];
	int tileGround[2][13];
	int tileSpawn[2][2];
	int tileWall[2][28];
	int tileWall1[2][28];
	int tileWall2[2][28];
	int tileWall3[2][28];
	//int tileObj[2][11];
}Array;
Array arr;


//extern
extern float firstPosTimer;
extern sfVector2f posBaseBat;
extern sfVector2f posBaseSkeleton;

//map creation
void initMap();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
void displayEditor(sfRenderWindow* _window);

//map save and load
void saveMap();
void loadMap();