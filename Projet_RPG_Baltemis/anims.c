#include "anims.h"

void trap_boucle()
{
        for (int i = 0; i < mapSizeY; i++)
        {
            for (int j = 0; j < mapSizeX; j++)
            {
                if (arr.mapObj[i][j].y == 6 || arr.mapObj[i][j].y == 8 || arr.mapObj[i][j].y == 10)
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 7) arr.mapObj[i][j].x = 0;
                }
            }
        }
}

//timer
float animPikeTimer;
float animTimerCont;
float animTimerCont_l;
float cooldownLente;
sfBool animLentePlaying;

void initAnims()
{
    //timer
	animTimerCont = 0.0f;
	animTimerCont_l = 0.0f;
    cooldownLente = 0.0f;
    animPikeTimer = 0.0f;
    sfBool animLentePlaying = sfFalse;

}

void updateAnims()
{
	animTimerCont += GetDeltaTime();
	animTimerCont_l += GetDeltaTime();
    animPikeTimer += GetDeltaTime();
   

	//anim button
	buttonCollision(skeleton.SpritePositionSkeleton);
	if (sfKeyboard_isScancodePressed(sfScanW))
	{
		buttonCollision(bat.SpritePositionBat);
	}
    // Anim continue (rapide)
    if (animTimerCont > 0.1f)
    {
        for (int i = 0; i < mapSizeY; i++)
        {
            for (int j = 0; j < mapSizeX; j++)
            {
                if (arr.mapObj[i][j].y == 11 || arr.mapObj[i][j].y == 12 ||
                    arr.mapObj[i][j].y == 3 || arr.mapObj[i][j].y == 4)
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 4) arr.mapObj[i][j].x = 0;
                }
            }
        }

        animTimerCont = 0.0f;
    }

    //anim continue (lente)
    // Lancer l'anim toutes les 4sec
    if (!animLentePlaying && cooldownLente >= 4.0f)
    {
        animLentePlaying = sfTrue;
    }
    if (animLentePlaying && animTimerCont_l > 0.2f)
    {
        for (int i = 0; i < mapSizeY; i++)
        {
            for (int j = 0; j < mapSizeX; j++)
            {
                if (arr.mapObj[i][j].y > 12)
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 4)
                    {
                        arr.mapObj[i][j].x = 0;
                        animLentePlaying = sfFalse;
                        cooldownLente = 0.0f;
                    }
                }
            }
        }
        animTimerCont_l = 0.0f;
    }
    cooldownLente += GetDeltaTime();



    //anime des piege piquant

    if (animPikeTimer > 0.1f)
    {
        trap_boucle();
        animPikeTimer = 0;
    }
    
}

void displayAnims(sfRenderWindow* window)
{

}
