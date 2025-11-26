#pragma once
#include "tools.h"
#include "player.h"
#include "editor.h"

sfBool batCollisions(sfFloatRect _spriteRect, batDir _direction, sfVector2f* _velocite, float* _anim);
sfBool skeletonCollisions(sfFloatRect _spriteRect, skeletonDir _direction, sfVector2f* _velocite, float* _anim);
extern sfBool buttonCollision(sfVector2f _playerPos);


 