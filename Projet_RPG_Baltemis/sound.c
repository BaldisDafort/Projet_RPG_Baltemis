#include "sound.h"

sfMusic* g_musicTitleScreen;
float sTimer = 0.0f;
int musicTitleScreenIsPlaying = 0;
char g_audioSettingsFlags = 0;

void ChangeVolume(sfMusic* _music, float _volume)
{
	sfMusic_setVolume(_music, (GetGeneralMuted() | GetMusicMuted()) ? 0.f : _volume);
}

void SetGeneralMuted(char _value)
{
	if (_value == 0)
	{

		g_audioSettingsFlags &= ~GENERAL_MUTED;
	}
	else if (_value == 1)
	{
		g_audioSettingsFlags |= GENERAL_MUTED;
	}
	else
	{
		printf("Set General Muted value out of range : must be 0 or 1");
	}
}

void SetMusicMuted(char _value)
{
	if (_value == 0)
	{

		g_audioSettingsFlags &= ~MUSIC_MUTED;
	}
	else if (_value == 1)
	{
		g_audioSettingsFlags |= MUSIC_MUTED;
	}
	else
	{
		printf("Set Music Muted value out of range : must be 0 or 1");
	}
}

void SetSFXMuted(char _value)
{
	if (_value == 0)
	{

		g_audioSettingsFlags &= ~SFX_MUTED;
	}
	else if (_value == 1)
	{
		g_audioSettingsFlags |= SFX_MUTED;
	}
	else
	{
		printf("Set SFX Muted value out of range : must be 0 or 1");
	}
}

char GetGeneralMuted()
{
	return((g_audioSettingsFlags & GENERAL_MUTED) >> GENERAL_OFFSET);
}

char GetMusicMuted()
{
	return((g_audioSettingsFlags & MUSIC_MUTED) >> MUSIC_OFFSET);
}

char GetSFXMuted()
{
	return((g_audioSettingsFlags & SFX_MUTED) >> SFX_OFFSET);
}

void initSound()
{
	g_musicTitleScreen = sfMusic_createFromFile("..\\Resources\\Musics\\musicIntro.ogg");
	sfMusic_play(g_musicTitleScreen);
	sfMusic_setLoop(g_musicTitleScreen, sfTrue);
	musicTitleScreenIsPlaying = 1;
}

void updateSound()
{
	sTimer += GetDeltaTime();
	if ((state != MENU && state != OPTION) && sTimer > 0.2f)
	{

		sfMusic_pause(g_musicTitleScreen);
		musicTitleScreenIsPlaying = 0;
		sTimer = 0.0f;
	}
	else if ((state == MENU || state == OPTION) && sTimer > 0.2f)
	{
		if (musicTitleScreenIsPlaying == 0)
		{
			sfMusic_play(g_musicTitleScreen);
			musicTitleScreenIsPlaying = 1;
			sTimer = 0.0f;
		}

	}
}