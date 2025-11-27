#include "sound.h"

sfMusic* g_musicTitleScreen;
sfMusic* g_MusicDeadlyLevel;
sfSoundStatus g_MusicStatusMusicDeadlyLevel;
sfMusic* g_MusicToxicLevel;
sfMusic* g_MusicLavaLevel;

sfSound* g_SoundButton;
sfSoundBuffer* g_SoundBufferButton;
sfSoundStatus g_SoundStatusButton;

sfSound* g_SoundDeadlyTrap;
sfSoundBuffer* g_SoundBufferDeadlyTrap;
sfSoundStatus g_SoundStatusDeadlyTrap;

sfSound* g_SoundToxicTrap;
sfSoundBuffer* g_SoundBufferToxicTrap;
sfSoundStatus g_SoundStatusToxicTrap;

sfSound* g_SoundLavaTrap;
sfSoundBuffer* g_SoundBufferLavaTrap;
sfSoundStatus g_SoundStatusLavaTrap;


int musicTitleScreenIsPlaying = 0;
int g_musicDeadlyLevelIsPlaying = 0;
int g_musicToxicLevelIsPlaying = 0;
int g_musicLavaLevelIsPlaying = 0;

float sTimer = 0.0f;
float g_VolumeMusic = 50.f;
float g_VolumeSound = 50.f;

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
	g_MusicToxicLevel = sfMusic_createFromFile("..\\Resources\\Musics\\musicToxicLevel.ogg");
	g_MusicLavaLevel = sfMusic_createFromFile("..\\Resources\\Musics\\musicLavaLevel.ogg");

	sfMusic_setVolume(g_musicTitleScreen, g_VolumeMusic);
	sfMusic_setLoop(g_musicTitleScreen, sfTrue);
	sfMusic_setVolume(g_MusicDeadlyLevel, g_VolumeMusic);
	sfMusic_setLoop(g_MusicDeadlyLevel, sfTrue);
	sfMusic_setVolume(g_MusicToxicLevel, g_VolumeMusic);
	sfMusic_setLoop(g_MusicToxicLevel, sfTrue);
	sfMusic_setVolume(g_MusicLavaLevel, g_VolumeMusic);
	sfMusic_setLoop(g_MusicLavaLevel, sfTrue);

	// Sound Button
	g_SoundButton = sfSound_create();
	g_SoundBufferButton = sfSoundBuffer_createFromFile("..\\Resources\\SoundsFX\\soundButton.ogg");
	sfSound_setBuffer(g_SoundButton, g_SoundBufferButton);
	// Sound Deadly Trap
	g_SoundDeadlyTrap = sfSound_create();
	g_SoundBufferDeadlyTrap = sfSoundBuffer_createFromFile("..\\Resources\\SoundsFX\\soundDeadlyTrap.ogg");
	sfSound_setBuffer(g_SoundDeadlyTrap, g_SoundBufferDeadlyTrap);
	// Sound Toxic Trap
	g_SoundToxicTrap = sfSound_create();
	g_SoundBufferToxicTrap = sfSoundBuffer_createFromFile("..\\Resources\\SoundsFX\\soundToxicTrap.ogg");
	sfSound_setBuffer(g_SoundToxicTrap, g_SoundBufferToxicTrap);
	// Sound Lava Trap
	g_SoundLavaTrap = sfSound_create();
	g_SoundBufferLavaTrap = sfSoundBuffer_createFromFile("..\\Resources\\SoundsFX\\soundLavaTrap.ogg");
	sfSound_setBuffer(g_SoundLavaTrap, g_SoundBufferLavaTrap);

	sfSound_setVolume(g_SoundButton, g_VolumeSound);
	sfSound_setVolume(g_SoundDeadlyTrap, g_VolumeSound);
	sfSound_setVolume(g_SoundToxicTrap, g_VolumeSound);
	sfSound_setVolume(g_SoundLavaTrap, g_VolumeSound);

	musicTitleScreenIsPlaying = 1;



	if (state == MENU || state == OPTION)
	{
		sfMusic_play(g_musicTitleScreen);
	}
}

void updateSound()
{
	sTimer += GetDeltaTime();
	if (state != MENU && state != OPTION)
	{

		sfMusic_pause(g_musicTitleScreen);
		musicTitleScreenIsPlaying = 0;

	}
	else if (state == MENU || state == OPTION)
	{
		if (g_PreviewState != 1)
		{
			if (musicTitleScreenIsPlaying == 0)
			{
				sfMusic_play(g_musicTitleScreen);
				musicTitleScreenIsPlaying = 1;
				g_musicDeadlyLevelIsPlaying = 0;
				g_musicToxicLevelIsPlaying = 0;
				g_musicLavaLevelIsPlaying = 0;

			}
		}


	}
	if (state != GAME && state != OPTION)
	{
		sfMusic_pause(g_MusicDeadlyLevel);
		g_musicDeadlyLevelIsPlaying = 0;
	}
	else if (state == GAME || state == OPTION)
	{
		if (g_PreviewState == 1)
		{
			if (currentMap == MAP)
			{
				if (g_musicDeadlyLevelIsPlaying == 0)
				{

					sfMusic_play(g_MusicDeadlyLevel);
					sfMusic_stop(g_MusicToxicLevel);
					sfMusic_stop(g_MusicLavaLevel);
					g_musicDeadlyLevelIsPlaying = 1;
					musicTitleScreenIsPlaying = 0;
					g_musicToxicLevelIsPlaying = 0;
					g_musicLavaLevelIsPlaying = 0;
				}

			}
			if (currentMap == MAP1)
			{
				if (g_musicToxicLevelIsPlaying == 0)
				{

					sfMusic_play(g_MusicToxicLevel);
					sfMusic_stop(g_MusicDeadlyLevel);
					sfMusic_stop(g_MusicLavaLevel);
					g_musicToxicLevelIsPlaying = 1;
					g_musicDeadlyLevelIsPlaying = 0;
					g_musicLavaLevelIsPlaying = 0;
					musicTitleScreenIsPlaying = 0;
				}

			}
			if (currentMap == MAP2)
			{
				if (g_musicLavaLevelIsPlaying == 0)
				{

					sfMusic_play(g_MusicLavaLevel);
					sfMusic_stop(g_MusicToxicLevel);
					sfMusic_stop(g_MusicDeadlyLevel);
					sfMusic_stop(g_MusicDeadlyLevel);
					g_musicLavaLevelIsPlaying = 1;
					g_musicToxicLevelIsPlaying = 0;
					g_musicDeadlyLevelIsPlaying = 0;
					musicTitleScreenIsPlaying = 0;
				}

			}
		}

	}


}