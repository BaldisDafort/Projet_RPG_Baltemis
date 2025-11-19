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


void initMap();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);

