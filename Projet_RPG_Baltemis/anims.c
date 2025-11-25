#include "anims.h"

void initAnims()
{
	
}

void updateAnims()
{
	//anim button
	buttonCollision(skeleton.SpritePositionSkeleton);
	if (sfKeyboard_isScancodePressed(sfScanW))
	{
		buttonCollision(bat.SpritePositionBat);
	}

}

void displayAnims(sfRenderWindow* window)
{

}
