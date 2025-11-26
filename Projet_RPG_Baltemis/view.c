#include "view.h"
#include "player.h"

//view in game
sfView* g_viewGame;
sfVector2f posViewGame = { 400, 300 };
sfFloatRect rectViewGame = { 400, 300, 800, 600 };

// Skeleton View 
sfView* g_SkeletonView;
sfVector2f g_PosSkeletonView;
sfFloatRect g_SkeletonViewPort;

// Bat View
sfView* g_BatView;




void initView()
{
	g_viewGame = sfView_create();
	sfView_reset(g_viewGame, rectViewGame);

	// Skeleton View
	g_SkeletonView = sfView_create();
	g_PosSkeletonView = skeleton.SpritePositionSkeleton;
	sfFloatRect rectSkeletonView = { 90.f, 133.f ,181.f ,400.f };
	sfView_reset(g_SkeletonView, rectSkeletonView);
	sfFloatRect g_SkeletonViewPort = { 0.f, 0.f, 0.5f, 1.f };
	sfView_setViewport(g_SkeletonView, g_SkeletonViewPort);

	// Bat View
	g_BatView = sfView_create();
	sfVector2f g_PosBatView = bat.SpritePositionBat;
	sfFloatRect rectBatView = { 90.f, 133.f ,181.f ,400.f };
	sfView_reset(g_BatView, rectBatView);
	sfFloatRect g_BatViewPort = { 0.5f, 0.f, 0.5f, 1.f };
	sfView_setViewport(g_BatView, g_BatViewPort);


}

void updateView(sfRenderWindow* _window)
{
	sfView_setCenter(g_viewGame, posViewGame);

	//Skeleton View
	sfView_setCenter(g_SkeletonView, skeleton.SpritePositionSkeleton);

	// Bat View
	sfView_setCenter(g_BatView, bat.SpritePositionBat);
}

//view
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, g_viewGame);
}

void displaySkeletonView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, g_SkeletonView);
}

void displayBatView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, g_BatView);
}