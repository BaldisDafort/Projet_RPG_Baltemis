#include "anims.h"

void trap_anims(sfIntRect _irect)
{
    for (int i = 1; i < mapSizeY; i++)
    {
        for (int j = 0; j < mapSizeX; j++)
        {
            if (arr.mapObj[i][j].y == 6 || arr.mapObj[i][j].y == 8 || arr.mapObj[i][j].y == 10)
            {
                if (arr.mapObj[i][j].x == 2 || arr.mapObj[i][j].x == 3 || arr.mapObj[i][j].x == 4)
                {
                    _irect.top = arr.mapObj[i][j].y - 1;
                    _irect.left = arr.mapObj[i][j].x;
                }
                else
                {
                    _irect.top = 0;
                    _irect.left = 0;
                }
                obj.animObj[i - 1][j].y = _irect.top;
                obj.animObj[i - 1][j].x = _irect.left;
            }
        }
    }
}

void activated_trap()
{
    for (int i = 0; i < mapSizeY; i++)
    {
        for (int j = 0; j < mapSizeX; j++)
        {
            if (arr.mapObj[i][j].y == 6)
            {
                if (arr.mapObj[i][j].x == 2)
                {
                    continue;
                }
                else
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 7) arr.mapObj[i][j].x = 0;
                }
            }
            else if (arr.mapObj[i][j].y == 8)
            {
                if (arr.mapObj[i][j].x < 7)
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x == 6) arr.mapObj[i][j].x = 0;
                }
                else
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 7) arr.mapObj[i][j].x = 0;
                }
            }
            else if (arr.mapObj[i][j].y == 10)
            {
                if (arr.mapObj[i][j].x == 2 || arr.mapObj[i][j].x == 3 || arr.mapObj[i][j].x == 4)
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 4) arr.mapObj[i][j].x = 2;
                }
                else
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 7) arr.mapObj[i][j].x = 0;
                }
            }
        }
    }

}

void not_activated_trap()
{
    for (int i = 0; i < mapSizeY; i++)
    {
        for (int j = 0; j < mapSizeX; j++)
        {
            if (arr.mapObj[i][j].y == 6 || arr.mapObj[i][j].y == 8 || arr.mapObj[i][j].y == 10)
            {
                if (arr.mapObj[i][j].x == 7)
                {
                    continue;
                }
                else
                {
                    arr.mapObj[i][j].x++;
                    if (arr.mapObj[i][j].x > 7) arr.mapObj[i][j].x = 0;
                }
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
    animLentePlaying = sfFalse;

    //init objet a animer
    obj.irectObj = (sfIntRect){ 0, 0, tileSize, tileSize };
    obj.posObj = (sfVector2f){ 0.0f, 0.0f };
    obj.frameObjX = 0;
    obj.frameObjY = 0;
    obj.spObj = sfSprite_create();
    obj.texObj = sfTexture_createFromFile("..\\Resources\\Textures\\tilesetobj.png", NULL);
    sfSprite_setTexture(obj.spObj, obj.texObj, sfTrue);
    sfSprite_setTextureRect(obj.spObj, obj.irectObj);
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

    if (animPikeTimer > 0.2f)
    {
        activated_trap();
        animPikeTimer = 0;
    }
    trap_anims(obj.irectObj);
}

void displayAnims(sfRenderWindow* _window)
{
    // Parcourt la grille et dessine uniquement si la cellule d'animation satisfait la condition
    for (int i = 0; i < mapSizeY; ++i)
    {
        for (int j = 0; j < mapSizeX; ++j)
        {
            int ax = obj.animObj[i][j].x; // indice de frame
            int ay = obj.animObj[i][j].y; // ligne du tileset
            // condition : dessiner uniquement quand ax est entre 2 et 4 (ou adaptez selon besoin)
            if (ax >= 2 && ax <= 4)
            {
                sfIntRect rect = { ax * tileSize, ay * tileSize, tileSize, tileSize };
                sfSprite_setTextureRect(obj.spObj, rect);

                sfVector2f pos = { j * (float)tileSize, i * (float)tileSize };
                sfSprite_setPosition(obj.spObj, pos);

                sfRenderWindow_drawSprite(_window, obj.spObj, NULL);
            }
        }
    }
}
