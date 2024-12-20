#include "Menu.h"

typedef enum MenuState
{
	Menu,

}MenuState;

MenuState menuState;
MenuData menuData;


void LoadMenu(void)
{
	//printf("LOAD MENU\n");

	LoadMenuMusic();

	//Origin : Bottom Left

	//Background
	menuData.background.sprite = sfSprite_create();

	menuData.background.texture = sfTexture_createFromFile("Assets/Sprites/Menu/MenuBackGround.png", NULL);

	sfSprite_setTexture(menuData.background.sprite, menuData.background.texture, sfTrue);

	sfVector2f position = { 0,SCREEN_HEIGHT };
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(menuData.background.sprite);

	sfSprite_setOrigin(menuData.background.sprite, (sfVector2f) { 0, globalBounds.height });
	sfSprite_setPosition(menuData.background.sprite, position);


	sfVector2f screen = { SCREEN_WIDTH,SCREEN_HEIGHT };

	//BUTTON TEXTURE
	menuData.userInterface.Button = sfTexture_createFromFile("Assets/Sprites/Menu/Buttons.png", NULL);

	sfVector2u size = sfTexture_getSize(menuData.userInterface.Button);

		//PlayButton
	sfIntRect rect = { 0,0,size.x / NB_BUTTON_IN_SPRITESHEET,size.y };
	sfVector2f origin = (sfVector2f){ 0, 0 };
	position = (sfVector2f){ 1551,303 };
	CreateSprite(&menuData.userInterface.playButtonSprite, menuData.userInterface.Button, position, rect, origin);

	//ExitButton
	rect = (sfIntRect){ size.x / NB_BUTTON_IN_SPRITESHEET,0,size.x / NB_BUTTON_IN_SPRITESHEET,size.y };
	origin = (sfVector2f){ 0, 0 };
	position = (sfVector2f){ 1551 , 555 };
	CreateSprite(&menuData.userInterface.exitButtonSprite, menuData.userInterface.Button, position, rect, origin);

}

void KeyPressedMenu(sfRenderWindow* _renderWindow, sfKeyEvent _key)
{
	switch (_key.code)
	{
	case sfKeyEscape:
		sfRenderWindow_close(_renderWindow);
		break;
	case sfKeySpace:
		SetGameState(GAME);
		break;
	default:
		break;
	}
}

void MouseButtonPressedMenu(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{

	if (MouseClickOnSprite(_mouseButton, menuData.userInterface.playButtonSprite))
	{
		SetGameState(GAME);
	}
	else if (MouseClickOnSprite(_mouseButton, menuData.userInterface.exitButtonSprite))
	{
		sfRenderWindow_close(_renderWindow);
	}

}

void MouseMovedMenu(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{
	sfColor red = { 219,  24,  24, 255 };
	sfColor white = { 255, 255, 255, 255 };

	sfSprite_setColor(menuData.userInterface.playButtonSprite, white);
	sfSprite_setColor(menuData.userInterface.exitButtonSprite, white);

	if (MouseMoveOnSprite(_mouseMove, menuData.userInterface.playButtonSprite))
	{
		sfSprite_setColor(menuData.userInterface.playButtonSprite, red);
	}
	else if (MouseMoveOnSprite(_mouseMove, menuData.userInterface.exitButtonSprite))
	{
		sfSprite_setColor(menuData.userInterface.exitButtonSprite, red);
	}
}

void UpdateMenu(float _dt)
{
	UpdateMenuMusic(_dt);
}

void DrawMenu(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_setMouseCursorVisible(_renderWindow, sfTrue);

	sfRenderWindow_drawSprite(_renderWindow, menuData.background.sprite, NULL);

	sfRenderWindow_drawSprite(_renderWindow, menuData.userInterface.playButtonSprite, NULL);
	sfRenderWindow_drawSprite(_renderWindow, menuData.userInterface.exitButtonSprite, NULL);

}

void CleanupMenu(void)
{
	CleanupMenuMusic();
	//BackGround
	sfTexture_destroy(menuData.background.texture);
	menuData.background.texture = NULL;
	sfSprite_destroy(menuData.background.sprite);
	menuData.background.sprite = NULL;
	//BUTTON TEXTURE
	sfTexture_destroy(menuData.userInterface.Button);
	menuData.userInterface.Button = NULL;
	//PlayButton
	sfSprite_destroy(menuData.userInterface.playButtonSprite);
	menuData.userInterface.playButtonSprite = NULL;
	//ExitButton
	sfSprite_destroy(menuData.userInterface.exitButtonSprite);
	menuData.userInterface.exitButtonSprite = NULL;
}