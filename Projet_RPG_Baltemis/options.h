#pragma once

#include "tools.h"


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

void initOptions();
void displayOptions(sfRenderWindow* _window);