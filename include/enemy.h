#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include <allegro5/allegro_primitives.h>

#include "random.h"
#include "constants.h"

enum Direction
{
    TOP = 0,
    RIGHT,
    BOTTOM,
    LEFT,
    LAST
};

class Enemy
{
public:
    Enemy();
    void render();
    void update();

    bool isUsed();
    void setUsed(bool used);

    int getPositionX();
    void setPositionX(int x);

    int getPositionY();
    void setPositionY(int y);

    void defineRandomPosition();
    void calculateVelocity();

private:
    float x, y;
    float dx, dy;
    int life;
    bool used;
    Direction direction;
};

#endif