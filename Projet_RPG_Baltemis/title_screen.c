#include "title_screen.h"

sfSprite* sTitleScreen;

sfRectangleShape* StartButton;
sfSprite* spriteStartButton;
sfIntRect startButtonAnimationRect = { 0,0,100,35 };

sfRectangleShape* EditorButton;
sfRectangleShape* OptionsButton;
sfRectangleShape* QuitButton;

void initTitleScreen()
{
	sTitleScreen = sfSprite_create();
	sfTexture* tTitleScreen = sfTexture_createFromFile("..\\Resources\\Images\\sketch_title_screen.png", NULL);
	sfSprite_setTexture(sTitleScreen, tTitleScreen, sfTrue);

	sfVector2f scale = { 2.f,2.65f };
	sfSprite_scale(sTitleScreen, scale);

	StartButton = sfRectangleShape_create();
	sfVector2f sizeStartButton = { 100.f, 35.f };
	sfVector2f positionStartButton = { 375.f, 350.f };
	sfRectangleShape_setSize(StartButton, sizeStartButton);
	sfRectangleShape_setPosition(StartButton, positionStartButton);

	spriteStartButton = sfSprite_create();
	sfTexture* textureStartButton = sfTexture_createFromFile("..\\Resources\\Textures\\start-button-sheet.png", NULL);
	sfSprite_setTexture(spriteStartButton, textureStartButton, sfTrue);
	sfSprite_setTextureRect(spriteStartButton, startButtonAnimationRect);
	sfSprite_setPosition(spriteStartButton, positionStartButton);

	EditorButton = sfRectangleShape_create();
	sfVector2f sizeEditorButton = { 100.f, 35.f };
	sfVector2f positionEditorButton = { 375.f, 410.f };
	sfRectangleShape_setSize(EditorButton, sizeEditorButton);
	sfRectangleShape_setFillColor(EditorButton, sfGreen);
	sfRectangleShape_setPosition(EditorButton, positionEditorButton);
	sfRectangleShape_setOutlineThickness(EditorButton, 5.f);
	sfRectangleShape_setOutlineColor(EditorButton, sfYellow);

	OptionsButton = sfRectangleShape_create();
	sfVector2f sizeOptionsButton = { 100.f, 35.f };
	sfVector2f positionOptionsButton = { 375.f, 470.f };
	sfColor OptionsButtonColor = sfColor_fromRGBA(70, 70, 70, 255);
	sfRectangleShape_setSize(OptionsButton, sizeOptionsButton);
	sfRectangleShape_setFillColor(OptionsButton, OptionsButtonColor);
	sfRectangleShape_setPosition(OptionsButton, positionOptionsButton);
	sfRectangleShape_setOutlineThickness(OptionsButton, 5.f);
	sfRectangleShape_setOutlineColor(OptionsButton, sfYellow);

	QuitButton = sfRectangleShape_create();
	sfVector2f sizeQuitButton = { 100.f, 35.f };
	sfVector2f positionQuitButton = { 375.f, 530.f };
	sfRectangleShape_setSize(QuitButton, sizeQuitButton);
	sfRectangleShape_setFillColor(QuitButton, sfBlue);
	sfRectangleShape_setPosition(QuitButton, positionQuitButton);
	sfRectangleShape_setOutlineThickness(QuitButton, 5.f);
	sfRectangleShape_setOutlineColor(QuitButton, sfYellow);

}

void displayTitleScreen(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, sTitleScreen, NULL);
	sfRenderWindow_drawRectangleShape(_window, StartButton, NULL);
	sfRenderWindow_drawSprite(_window, spriteStartButton, NULL);
	sfRenderWindow_drawRectangleShape(_window, EditorButton, NULL);
	sfRenderWindow_drawRectangleShape(_window, OptionsButton, NULL);
	sfRenderWindow_drawRectangleShape(_window, QuitButton, NULL);
}
