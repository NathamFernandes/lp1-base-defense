#ifndef DROP_H
#define DROP_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

#include "constants.h"

// Poderia fazer outros buffs/nerfs, como um freeze na tela, uma diminuição no tempo do jogo, etc...
enum DropType
{
    AMMUNITION_DROP = 0,
    PLAYER_LIFE_DROP,
    BASE_LIFE_DROP,
};

class Drop
{
private:
    float x, y, dx, dy;

public:
    Drop();
    // void render();
    // void update();

    // int getPositionX();
    // void setPositionX(int x);

    // int getPositionY();
    // void setPositionY(int y);
};

#endif