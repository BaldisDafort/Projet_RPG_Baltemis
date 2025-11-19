#pragma once

#include "tools.h"

#define mapsizeX 34
#define mapsizeY 25
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
	int mapGround[mapsizeY][mapsizeX];
	int mapWall[mapsizeY][mapsizeX];
	int mapWall1[mapsizeY][mapsizeX];
	int mapWall2[mapsizeY][mapsizeX];
	int mapWall3[mapsizeY][mapsizeX];
	int tileGround[2][13];
	int tileWall[2][28];
}Array;
Array arr;

void initMap();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);