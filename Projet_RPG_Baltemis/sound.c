#include "sound.h"

sfMusic* g_musicTitleScreen;
sfMusic* g_MusicDeadlyLevel;
sfSoundStatus g_MusicStatusMusicDeadlyLevel;

sfSound* g_SoundButton;
sfSoundBuffer* g_SoundBufferButton;
sfSoundStatus g_SoundStatusButton;


int musicTitleScreenIsPlaying = 0;
int musicDeadlyLevelIsPlaying = 0;

float sTimer = 0.0f;
float g_VolumeMusic = 25.f;

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
	g_MusicDeadlyLevel = sfMusic_createFromFile("..\\Resources\\Musics\\musicDeadlyLevel.ogg");
	g_MusicStatusMusicDeadlyLevel = sfMusic_getStatus(g_MusicDeadlyLevel);
	
	g_SoundButton = sfSound_create();
	g_SoundBufferButton = sfSoundBuffer_createFromFile("..\\Resources\\SoundsFX\\soundButton.ogg");
	sfSound_setBuffer(g_SoundButton, g_SoundBufferButton);
	sfMusic_setLoop(g_musicTitleScreen, sfTrue);
	musicTitleScreenIsPlaying = 1;

	sfMusic_setVolume(g_musicTitleScreen, g_VolumeMusic);

	if (state == MENU || state == OPTION)
	{
		sfMusic_play(g_musicTitleScreen);
	}
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
			musicDeadlyLevelIsPlaying = 0;
			sTimer = 0.0f;
		}

	}
	else if (state == GAME && sTimer > 0.1f)
	{
		if (musicDeadlyLevelIsPlaying == 0)
		{
			if (g_MusicStatusMusicDeadlyLevel == sfStopped)
			{
				sfMusic_play(g_MusicDeadlyLevel);
				musicDeadlyLevelIsPlaying = 1;
				sTimer = 0.0f;
			}
		}
	}
}