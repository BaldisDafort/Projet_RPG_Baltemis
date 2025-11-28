#pragma once.
#include "tools.h"

#define GENERAL_OFFSET 0
#define MUSIC_OFFSET 1
#define SFX_OFFSET 2

extern sfMusic* g_musicTitleScreen;
extern sfMusic* g_MusicDeadlyLevel;
extern sfMusic* g_MusicToxicLevel;
extern sfMusic* g_MusicLavaLevel;
extern sfSound* g_SoundButton;
extern sfSoundBuffer* g_SoundBufferButton;
extern sfSoundStatus g_SoundStatusButton;
extern float g_VolumeMusic;

enum AudioSettingsFlags
{
	GENERAL_MUTED = 1 << GENERAL_OFFSET,
	MUSIC_MUTED = 1 << MUSIC_OFFSET,
	SFX_MUTED = 1 << SFX_OFFSET

};


extern char g_audioSettingsFlags;
float sTimer;

void initSound();
void updateSound();

void ChangeVolume(sfMusic* _music, float _volume);
void SetGeneralMuted(char _value);
void SetMusicMuted(char _value);
void SetSFXMuted(char _value);
char GetGeneralMuted();
char GetMusicMuted();
char GetSFXMuted();