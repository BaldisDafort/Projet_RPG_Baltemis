#include "title_screen.h"

sfSprite* sTitleScreen;


sfRectangleShape* StartButton;
sfSprite* spriteStartButton;
sfIntRect startButtonAnimationRect = { 0,0,100,35 };

sfRectangleShape* EditorButton;
sfSprite* spriteEditorButton;
sfIntRect editorButtonAnimationRect = { 0,0,100,35 };

sfRectangleShape* OptionsButton;
sfSprite* spriteOptionsButton;
sfIntRect optionsButtonAnimationRect = { 0,0,100,35 };

sfRectangleShape* QuitButton;
sfSprite* spriteQuitButton;
sfIntRect quitButtonAnimationRect = { 0,0,100,35 };

void initTitleScreen()
{
	sTitleScreen = sfSprite_create();
	sfTexture* tTitleScreen = sfTexture_createFromFile("..\\Resources\\Images\\titleScreen.png", NULL);
	sfSprite_setTexture(sTitleScreen, tTitleScreen, sfTrue);

	// Start Button
	StartButton = sfRectangleShape_create();
	sfVector2f sizeStartButton = { 100.f, 35.f };
	sfVector2f positionStartButton = { 351.f, 350.f };
	sfColor startButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(StartButton, startButtonColor);
	sfRectangleShape_setSize(StartButton, sizeStartButton);
	sfRectangleShape_setPosition(StartButton, positionStartButton);

	spriteStartButton = sfSprite_create();
	sfTexture* textureStartButton = sfTexture_createFromFile("..\\Resources\\Textures\\start-button-sheet.png", NULL);
	sfSprite_setTexture(spriteStartButton, textureStartButton, sfTrue);
	sfSprite_setTextureRect(spriteStartButton, startButtonAnimationRect);
	sfSprite_setPosition(spriteStartButton, positionStartButton);

	// Editor Button
	EditorButton = sfRectangleShape_create();
	sfVector2f sizeEditorButton = { 100.f, 35.f };
	sfVector2f positionEditorButton = { 351.f, 410.f };
	sfColor editorButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(EditorButton, editorButtonColor);
	sfRectangleShape_setSize(EditorButton, sizeEditorButton);
	sfRectangleShape_setPosition(EditorButton, positionEditorButton);


	spriteEditorButton = sfSprite_create();
	sfTexture* textureEditButton = sfTexture_createFromFile("..\\Resources\\Textures\\edit-button.png", NULL);
	sfSprite_setTexture(spriteEditorButton, textureEditButton, sfTrue);
	sfSprite_setTextureRect(spriteEditorButton, editorButtonAnimationRect);
	sfSprite_setPosition(spriteEditorButton, positionEditorButton);

	// Option Button
	OptionsButton = sfRectangleShape_create();
	sfVector2f sizeOptionsButton = { 100.f, 35.f };
	sfVector2f positionOptionsButton = { 351.f, 470.f };
	sfColor OptionsButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setSize(OptionsButton, sizeOptionsButton);
	sfRectangleShape_setFillColor(OptionsButton, OptionsButtonColor);
	sfRectangleShape_setPosition(OptionsButton, positionOptionsButton);

	spriteOptionsButton = sfSprite_create();
	sfTexture* textureOptionsButton = sfTexture_createFromFile("..\\Resources\\Textures\\settings.png", NULL);
	sfSprite_setTexture(spriteOptionsButton, textureOptionsButton, sfTrue);
	sfSprite_setTextureRect(spriteOptionsButton, optionsButtonAnimationRect);
	sfSprite_setPosition(spriteOptionsButton, positionOptionsButton);

	// Quit Button
	QuitButton = sfRectangleShape_create();
	sfVector2f sizeQuitButton = { 100.f, 35.f };
	sfVector2f positionQuitButton = { 351.f, 530.f };
	sfColor quitButtonColor = sfColor_fromRGBA(255, 255, 255, 0);
	sfRectangleShape_setFillColor(QuitButton, quitButtonColor);
	sfRectangleShape_setSize(QuitButton, sizeQuitButton);
	sfRectangleShape_setPosition(QuitButton, positionQuitButton);

	spriteQuitButton = sfSprite_create();
	sfTexture* textureQuitButton = sfTexture_createFromFile("..\\Resources\\Textures\\exit-button.png", NULL);
	sfSprite_setTexture(spriteQuitButton, textureQuitButton, sfTrue);
	sfSprite_setTextureRect(spriteQuitButton, quitButtonAnimationRect);
	sfSprite_setPosition(spriteQuitButton, positionQuitButton);

}

void updateTitleScreen(sfRenderWindow* _window)
{
	sfVector2i mousePixelPos = sfMouse_getPositionRenderWindow(_window);
	sfVector2f mouseWorldPos = sfRenderWindow_mapPixelToCoords(_window, mousePixelPos, g_viewGame);
	sfFloatRect rectStartButton = sfRectangleShape_getGlobalBounds(StartButton);
	sfFloatRect rectEditorButton = sfRectangleShape_getGlobalBounds(EditorButton);
	sfFloatRect rectOptionsButton = sfRectangleShape_getGlobalBounds(OptionsButton);
	sfFloatRect rectQuitButton = sfRectangleShape_getGlobalBounds(QuitButton);



	// Start Hover Animation
	if (sfFloatRect_contains(&rectStartButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		startButtonAnimationRect.left = startButtonAnimationRect.width;
		sfSprite_setTextureRect(spriteStartButton, startButtonAnimationRect);
	}
	else
	{
		startButtonAnimationRect.left = 0;
		sfSprite_setTextureRect(spriteStartButton, startButtonAnimationRect);
	}
	// Editor Hover Animation
	if (sfFloatRect_contains(&rectEditorButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		editorButtonAnimationRect.left = editorButtonAnimationRect.width;
		sfSprite_setTextureRect(spriteEditorButton, editorButtonAnimationRect);
	}
	else
	{
		editorButtonAnimationRect.left = 0;
		sfSprite_setTextureRect(spriteEditorButton, editorButtonAnimationRect);
	}
	// Option Hover Animation
	if (sfFloatRect_contains(&rectOptionsButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		optionsButtonAnimationRect.left = optionsButtonAnimationRect.width;
		sfSprite_setTextureRect(spriteOptionsButton, optionsButtonAnimationRect);
	}
	else
	{
		optionsButtonAnimationRect.left = 0;
		sfSprite_setTextureRect(spriteOptionsButton, optionsButtonAnimationRect);
	}
	// Exit Hover Animation
	if (sfFloatRect_contains(&rectQuitButton, mouseWorldPos.x, mouseWorldPos.y))
	{
		quitButtonAnimationRect.left = quitButtonAnimationRect.width;
		sfSprite_setTextureRect(spriteQuitButton, quitButtonAnimationRect);
	}
	else
	{
		quitButtonAnimationRect.left = 0;
		sfSprite_setTextureRect(spriteQuitButton, quitButtonAnimationRect);
	}
}

void displayTitleScreen(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, sTitleScreen, NULL);
	
	sfRenderWindow_drawRectangleShape(_window, StartButton, NULL);
	sfRenderWindow_drawSprite(_window, spriteStartButton, NULL);

	
	sfRenderWindow_drawRectangleShape(_window, EditorButton, NULL);
	sfRenderWindow_drawSprite(_window, spriteEditorButton, NULL);

	sfRenderWindow_drawRectangleShape(_window, OptionsButton, NULL);
	sfRenderWindow_drawSprite(_window, spriteOptionsButton, NULL);

	sfRenderWindow_drawRectangleShape(_window, QuitButton, NULL);
	sfRenderWindow_drawRectangleShape(_window, spriteQuitButton, NULL);
}
