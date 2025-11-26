#include "collisions.h"

sfVector2i nexPosInTab = { 0, 0 };
sfVector2i nexPosInTab2 = { 0, 0 };
sfBool buttonCollision(sfVector2f _playerPos);

//la collision de la chauve-souris est de 1 pixel de hauteur, et 16 pixel de largeur (sans collision = 14 en haut et 1 en bas)
sfBool batCollisions(sfFloatRect _spriteRect, batDir _direction, sfVector2f* _velocite, float* _anim)
{
	if (_direction == B_HAUT)
	{
		//calcul la position dans le tableau au prochian mouvement vers le haut
		nexPosInTab.x = (_spriteRect.left + 1) / 16;
		nexPosInTab.y = ((_spriteRect.top + 14) - _velocite->y * GetDeltaTime()) / 16;
		nexPosInTab2.x = (_spriteRect.left + _spriteRect.width - 1) / 16;
		nexPosInTab2.y = ((_spriteRect.top + 14) - _velocite->y * GetDeltaTime()) / 16;
	}

	if (_direction == B_BAS)
	{
		//calcul la position dans le tableau au prochian mouvement vers le bas
		nexPosInTab.x = (_spriteRect.left + 1) / 16;
		nexPosInTab.y = (_spriteRect.top + 15 + _velocite->y * GetDeltaTime()) / 16;
		nexPosInTab2.x = (_spriteRect.left + _spriteRect.width - 1) / 16;
		nexPosInTab2.y = (_spriteRect.top + 15 + _velocite->y * GetDeltaTime()) / 16;
	}
	if (_direction == B_DROITE)
	{
		//calcul la position dans le tableau au prochian mouvement vers la droite
		nexPosInTab.x = (_spriteRect.left + _spriteRect.width -1 + _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab.y = (_spriteRect.top + 14) / 16;
		nexPosInTab2.x = (_spriteRect.left + _spriteRect.width -1 + _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab2.y = (_spriteRect.top + 15) / 16;
	}

	if (_direction == B_GAUCHE)
	{
		//calcul la position dans le tableau au prochian mouvement vers la gauche
		nexPosInTab.x = (_spriteRect.left + 1 - _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab.y = (_spriteRect.top + 14) / 16;
		nexPosInTab2.x = (_spriteRect.left + 1 - _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab2.y = (_spriteRect.top + 15) / 16;
	}

	//si case avec collision
	if (arr.mapWall[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		arr.mapWall1[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall1[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		arr.mapWall2[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall2[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		arr.mapWall3[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall3[nexPosInTab2.y][nexPosInTab2.x] != 0)
	{
		return sfTrue; //retourn sfTrue si collision
	}
	else
	{
		_velocite->x = 100.0f;
		_velocite->y = 100.0f;
		return sfFalse; //retourne sfFalse si pas collision 
	}
}


//la collision du squelette est de 3 pixel de hauteur, et 13 pixel de largeur (sans collision =  13 en haut et 2 a droite et 1 a gauche)
sfBool skeletonCollisions(sfFloatRect _spriteRect, skeletonDir _direction, sfVector2f* _velocite, float* _anim)
{
	if (_direction == SK_HAUT)
	{
		//calcul la position dans le tableau au prochian mouvement vers le haut
		nexPosInTab.x = (_spriteRect.left) / 16;
		nexPosInTab.y = ((_spriteRect.top + 13) - _velocite->y * GetDeltaTime()) / 16;
		nexPosInTab2.x = (_spriteRect.left + _spriteRect.width - 2) / 16;
		nexPosInTab2.y = ((_spriteRect.top + 13) - _velocite->y * GetDeltaTime()) / 16;
	}

	if (_direction == SK_BAS)
	{
		//calcul la position dans le tableau au prochian mouvement vers le bas
		nexPosInTab.x = _spriteRect.left / 16;
		nexPosInTab.y = (_spriteRect.top + 16 + _velocite->y * GetDeltaTime()) / 16;
		nexPosInTab2.x = (_spriteRect.left + _spriteRect.width - 2) / 16;
		nexPosInTab2.y = (_spriteRect.top + 16 + _velocite->y * GetDeltaTime()) / 16;
	}
	if (_direction == SK_DROITE)
	{
		//calcul la position dans le tableau au prochian mouvement vers la droite
		nexPosInTab.x = (_spriteRect.left + _spriteRect.width - 2 + _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab.y = (_spriteRect.top + 13) / 16;
		nexPosInTab2.x = (_spriteRect.left + _spriteRect.width - 2 + _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab2.y = (_spriteRect.top + 16) / 16;
	}

	if (_direction == SK_GAUCHE)
	{
		//calcul la position dans le tableau au prochian mouvement vers la gauche
		nexPosInTab.x = (_spriteRect.left - _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab.y = (_spriteRect.top + 13) / 16;
		nexPosInTab2.x = (_spriteRect.left - _velocite->x * GetDeltaTime()) / 16;
		nexPosInTab2.y = (_spriteRect.top + 16) / 16;
	}

	//si case avec collision
	if (//les murs
		arr.mapWall[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		arr.mapWall1[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall1[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		arr.mapWall2[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall2[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		arr.mapWall3[nexPosInTab.y][nexPosInTab.x] != 0 || arr.mapWall3[nexPosInTab2.y][nexPosInTab2.x] != 0 ||
		//les objets
		//les coffres
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 1 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].x <= 6 ) || 
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 1 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x <= 6) ||
		//le crane et le trou piquant
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].x >= 6 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 2) ||
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x >= 6 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 2) ||
		//trou toxic
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].x <= 7 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 3) ||
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x <= 7 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 3) ||
		//trou de feu
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].x <= 7 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 4) ||
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x <= 7 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 4) ||
		//le piege piquant
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].x <= 6 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 6) ||
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x <= 6 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 6) ||
		//le piege toxique
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].x <= 6 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 8) ||
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x <= 6 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 8) ||
		//le piege de feu
		(arr.mapObj[nexPosInTab.y][nexPosInTab.x].x <= 6 && arr.mapObj[nexPosInTab.y][nexPosInTab.x].y == 10) ||
		(arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].x <= 6 && arr.mapObj[nexPosInTab2.y][nexPosInTab2.x].y == 10)
		)
	{
		return sfTrue; //retourn sfTrue si collision
	}
	else
	{
		_velocite->x = 80.0f;
		_velocite->y = 80.0f;
		return sfFalse; //retourne sfFalse si pas collision
	}
	//return sfFalse; 
}


//collision et animation du boutton 
sfBool buttonCollision(sfVector2f _playerPos)
{
	sfVector2i _playerTilePos1 = { (_playerPos.x + 1) / tileSize, (_playerPos.y + tileSize) / tileSize };
	sfVector2i _playerTilePos2 = { (_playerPos.x + 15) / tileSize, (_playerPos.y + tileSize) / tileSize };

	if (arr.mapObj[_playerTilePos1.y][_playerTilePos1.x].x == 0 && arr.mapObj[_playerTilePos1.y][_playerTilePos1.x].y == 5)
	{
		//arr.mapObj[_playerTilePos1.y][_playerTilePos1.x].x = 1;
		return sfTrue;
	}
	if (arr.mapObj[_playerTilePos2.y][_playerTilePos2.x].x == 0 && arr.mapObj[_playerTilePos2.y][_playerTilePos2.x].y == 5)
	{
		//arr.mapObj[_playerTilePos2.y][_playerTilePos2.x].x = 1;
		return sfTrue;
	}
	return sfFalse;
}
sfVector2i buttonAnimation(sfVector2f _playerPos)
{
	sfVector2i _playerTilePos1 = { (_playerPos.x + 1) / tileSize, (_playerPos.y + tileSize) / tileSize };
	sfVector2i _playerTilePos2 = { (_playerPos.x + 15) / tileSize, (_playerPos.y + tileSize) / tileSize };
	sfVector2i buttonPos = { -1, -1 };

        if (arr.mapObj[_playerTilePos1.y][_playerTilePos1.x].x == 0 && arr.mapObj[_playerTilePos1.y][_playerTilePos1.x].y == 5)
        {
         
            buttonPos.x = _playerTilePos1.x;
            buttonPos.y = _playerTilePos1.y;
        }
        if (arr.mapObj[_playerTilePos2.y][_playerTilePos2.x].x == 0 && arr.mapObj[_playerTilePos2.y][_playerTilePos2.x].y == 5)
        {
		
            buttonPos.x = _playerTilePos2.x;
            buttonPos.y = _playerTilePos2.y;
        }
		return buttonPos;
}

sfBool levelChangement()
{
	sfVector2i _playerTilePos1 = { (skeleton.SpritePositionSkeleton.x + 1) / tileSize, (skeleton.SpritePositionSkeleton.y + tileSize) / tileSize };
	sfVector2i _playerTilePos2 = { (skeleton.SpritePositionSkeleton.x + 15) / tileSize, (skeleton.SpritePositionSkeleton.y + tileSize) / tileSize };

	if ((arr.mapGround[_playerTilePos1.y][_playerTilePos1.x] >= 11 && arr.mapGround[_playerTilePos1.y][_playerTilePos1.x] <= 14) || (arr.mapGround[_playerTilePos2.y][_playerTilePos2.x] >= 11 && arr.mapGround[_playerTilePos2.y][_playerTilePos2.x] <= 14))
	{
		return sfTrue;
	}
	return sfFalse;
}
