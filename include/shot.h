#ifndef SHOT_H
#define SHOT_H

#include <allegro5/allegro_primitives.h>

#include "constants.h"
#include <allegro5/allegro_color.h>

class Shot
{
public:
    Shot();
    ~Shot();

    // bool isUsed();
    // void setUsed(bool used);

    // int getPositionX();
    // void setPositionX(int x);

    // int getPositionY();
    // void setPositionY(int y);

    // bool init();
    // void deinit();
    void render();
    void update();

    bool move(int destinationX, int destinationY);

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

    bool handleIfReachedPlayer();
    bool handleIfReachedBase();
    bool handleIfOutOfScreen();

private:
    float x, y, dx, dy;
    bool fromPlayer, used, moving;
    float destinationX, destinationY;
};

#endif // SHOT_H