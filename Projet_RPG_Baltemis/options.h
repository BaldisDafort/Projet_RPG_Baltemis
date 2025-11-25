#pragma once

#include "view.h"

extern sfRectangleShape* g_DisplayOptions;
extern sfRectangleShape* g_GeneralSoundButton_IsMuted;
extern sfRectangleShape* g_SFXSoundButton_IsMuted;

// Les boutons pour le son en général
extern sfRectangleShape* g_GeneralSoundButton_IsMuted;
extern sfRectangleShape* g_GeneralSoundButtonVolumePlus;
extern sfRectangleShape* g_GeneralSoundButtonVolumeMinus;

// Les boutons pour les musiques
extern sfRectangleShape* g_MusicSoundButton_IsMuted;
extern sfRectangleShape* g_MusicSoundButtonVolumePlus;
extern sfRectangleShape* g_MusicSoundButtonVolumeMinus;

// Les boutons pour les sons
extern sfRectangleShape* g_SFXSoundButton_IsMuted;
extern sfRectangleShape* g_SFXSoundButtonVolumePlus;
extern sfRectangleShape* g_SFXSoundButtonVolumeMinus;


extern sfSprite* g_SpriteGeneralSound;
extern sfIntRect g_GeneralSoundRect;
extern sfIntRect g_GeneralTurnUpVolumeRect;
extern sfSprite* g_SpriteGeneralTurnUpVolume;
extern sfSprite* g_SpriteGeneralTurnDownVolume;
extern sfIntRect g_GeneralTurnDownVolumeRect;

extern sfSprite* g_SpriteMusicSound;
extern sfIntRect g_MusicSoundRect;
extern sfIntRect g_MusicTurnUpVolumeRect;
extern sfSprite* g_SpriteMusicTurnUpVolume;
extern sfSprite* g_SpriteMusicTurnDownVolume;
extern sfIntRect g_MusicTurnDownVolumeRect;


extern sfSprite* g_SpriteSFXSound;
extern sfIntRect g_SFXSoundRect;
extern sfIntRect g_SFXTurnUpVolumeRect;
extern sfSprite* g_SpriteSFXTurnUpVolume;
extern sfSprite* g_SpriteSFXTurnDownVolume;
extern sfIntRect g_SFXTurnDownVolumeRect;


void initOptions();
void updateOptions(sfRenderWindow* _window);
void displayOptions(sfRenderWindow* _window);

