#ifndef DROP_H
#define DROP_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>

#include "constants.h"
#include "random.h"

// Poderia fazer outros buffs/nerfs, como um freeze na tela, uma diminuição no tempo do jogo, etc...
enum DropType
{
    AMMUNITION_DROP = 0,
    PLAYER_LIFE_DROP,
    BASE_LIFE_DROP,
    LAST_DROP
};

class Drop
{
private:
    float x, y;
    DropType type;
    int points;
    bool used;
    int lifeTime;

public:
    Drop();
    void update();
    void render(ALLEGRO_FONT *font);

    int getPositionX();
    void setPositionX(int x);

    int getPositionY();
    void setPositionY(int y);

    int getPoints();
    void setPoints(int points);

    DropType getDropType();
    void setDropType(DropType type);

    bool isUsed();
    void setUsed(bool used);

    int getLifeTime();
    void setLifeTime(int lifeTime);
};

#endif