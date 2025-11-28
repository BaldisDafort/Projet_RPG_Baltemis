#include "dialogue.h"

void initDialogue()
{
	//global
	dial.spDial = sfSprite_create();
	dial.texDial = sfTexture_createFromFile("..\\Resources\\Textures\\dialogue.png", NULL);
	dial.portraitRect;
	dial.dialRect;
	dial.portraitPos = (sfVector2f){ 42.0f, 477.0f };
	dial.dialoguePos = (sfVector2f){ 150.0f, 477.0f };
	dial.dialSize = (sfVector2f){ 4.0f, 4.0f };
	dial.isTalking = 0;
	dial.chest = 0;
	dial.talkingTimer = 0.0f;
	sfSprite_setTexture(dial.spDial, dial.texDial, sfTrue);
	sfSprite_setPosition(dial.spDial, dial.dialoguePos);
	sfSprite_setScale(dial.spDial, dial.dialSize);

	//portait du pnj
	dial.spPnjPortrait = sfSprite_create();
	dial.texPnjPortrait = sfTexture_createFromFile("..\\Resources\\Textures\\pnjportrait.png", NULL);
	sfSprite_setTexture(dial.spPnjPortrait, dial.texPnjPortrait, sfTrue);
	sfSprite_setPosition(dial.spPnjPortrait, dial.portraitPos);
	sfSprite_setScale(dial.spPnjPortrait, dial.dialSize);

	
	// portrait du skelette
	dial.spSkeletonPortrait = sfSprite_create();
	dial.texSkeletonPortrait = sfTexture_createFromFile("..\\Resources\\Textures\\skeletonportrait.png", NULL);
	sfSprite_setTexture(dial.spSkeletonPortrait, dial.texSkeletonPortrait, sfTrue);
	sfSprite_setPosition(dial.spSkeletonPortrait, dial.portraitPos);
	sfSprite_setScale(dial.spSkeletonPortrait, dial.dialSize);

}

void updateDialogue()
{
	dial.talkingTimer += GetDeltaTime();

	
	if (dial.talkingTimer > 0.3f)
	{
		//parler avec le pnj
		if (talkToPnj() && dial.isTalking == 0)
		{
			dial.isTalking = 1;
		}
		else if (talkToPnj() && dial.isTalking == 1)
		{
			dial.isTalking = 0;
		}
		//dialogue optention de clée 
		if (open_chest() && dial.chest == 0)
		{
			dial.chest = 1;
		}
		else if (open_chest() && dial.chest == 1)
		{
			dial.chest = 0;
		}
		dial.talkingTimer = 0.0f;
	}

}

void displayDialogue(sfRenderWindow* _window)
{
	//draw dialogue box
	if (dial.isTalking == 1)
	{
		sfRenderWindow_drawSprite(_window, dial.spPnjPortrait, NULL);
		sfRenderWindow_drawSprite(_window, dial.spDial, NULL);
	}
	if (dial.chest == 1)
	{
		sfRenderWindow_drawSprite(_window, dial.spSkeletonPortrait, NULL);
		sfRenderWindow_drawSprite(_window, dial.spDial, NULL);
	}
}
