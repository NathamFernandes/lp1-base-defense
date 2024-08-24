#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

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
    void update(int playerPositionX, int playerPositionY);

    bool isUsed();
    void setUsed(bool used);

    int getPositionX();
    void setPositionX(int x);

    int getPositionY();
    void setPositionY(int y);

    float getVelocity();
    void setVelocity(float velocity);

    void defineRandomPosition();
    void updatePosition(int playerPositionX, int playerPositionY);

    short getShotDelay();
    void setShotDelay(short shotDelay);

private:
    float x, y;
    float dx, dy;
    int life;
    float velocity;
    bool used;
    Direction direction;
    short shotDelay;
};

#endif