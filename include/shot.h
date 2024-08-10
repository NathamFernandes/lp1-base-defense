#ifndef SHOT_H
#define SHOT_H

#include <allegro5/allegro_primitives.h>

#include "constants.h"
#include <allegro5/allegro_color.h>

class Shot
{
private:
    float x, y;
    float dx, dy;
    float destinationX, destinationY;
    bool fromPlayer, used, moving;

public:
    Shot();
    ~Shot();

    void update();
    void render();

    // Mecânica
    bool move(int destinationX, int destinationY);

    // Aux
    bool handleIfReachedPlayer();
    bool handleIfReachedBase();
    bool handleIfOutOfScreen();

    // Getters and Setters
    int getPositionX();
    void setPositionX(int x);

    int getPositionY();
    void setPositionY(int y);

    int getDX();
    void setDX(int dx);

    int getDY();
    void setDY(int dy);

    bool isUsed();
    void setUsed(bool used);

    bool isMoving();
    void setMoving(bool moving);

    bool isFromPlayer();
    void setFromPlayer(bool fromPlayer);
};

#endif // SHOT_H