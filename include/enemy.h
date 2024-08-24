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

    float getVelocity();
    void setVelocity(float velocity);

    float getDestinationX();
    void setDestionationX(float destinationX);

    float getDestionationY();
    void setDestionationY(float destinationY);

    void defineRandomPosition();
    void updatePosition(float destinationX, float destinationY);

    short getShotDelay();
    void setShotDelay(short shotDelay);

private:
    float x, y;
    float dx, dy;
    float destinationX, destinationY;
    int life;
    float velocity;
    bool used;
    Direction direction;
    short shotDelay;
};

#endif