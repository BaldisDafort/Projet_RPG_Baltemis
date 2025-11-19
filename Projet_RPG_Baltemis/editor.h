#pragma once

#include "tools.h"

#define mapSizeX 34
#define mapSizeY 25
#define tileSize 16

typedef enum Tileset Tileset;
typedef enum Tileset
{ 
	GROUND,
	WALL,
	WALL1, 
	WALL2, 
	WALL3
};
Tileset currentTileset;

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
	sfVector2f posEditor;
	sfVector2f originEditorGround;
	sfVector2f originEditorWall;

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
	int mapWall[mapSizeY][mapSizeX];
	int mapWall1[mapSizeY][mapSizeX];
	int mapWall2[mapSizeY][mapSizeX];
	int mapWall3[mapSizeY][mapSizeX];
	int tileGround[2][13];
	int tileWall[2][28];
}Array;
Array arr;

//map creation
void initMap();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);

//map save and load
void saveMap();
void loadMap();