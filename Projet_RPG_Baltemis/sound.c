#include "sound.h"

sfMusic* musicTitleScreen;
float sTimer = 0.0f;
int musicTitleScreenIsPlaying = 0;

void initSound()
{
	musicTitleScreen = sfMusic_createFromFile("..\\Resources\\Musics\\musicIntro.ogg");
	sfMusic_play(musicTitleScreen);
	sfMusic_setLoop(musicTitleScreen, sfTrue);
	musicTitleScreenIsPlaying = 1;
}

void updateSound()
{
	sTimer += GetDeltaTime();
	if ((state != MENU && state != OPTION) && sTimer > 0.2f)
	{
		sfMusic_pause(musicTitleScreen);
		musicTitleScreenIsPlaying = 0;
		sTimer = 0.0f;
	}
	else if ((state == MENU || state == OPTION) && sTimer > 0.2f)
	{
		if (musicTitleScreenIsPlaying == 0)
		{
			sfMusic_play(musicTitleScreen);
			musicTitleScreenIsPlaying = 1;
			sTimer = 0.0f;
		}

	}
}
