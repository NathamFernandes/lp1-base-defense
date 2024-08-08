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

    int getPositionX();
    void setPositionX(int x);

    int getPositionY();
    void setPositionY(int y);

    int getDX();
    void setDX(int dx);

    int getDY();
    void setDY(int dy);

private:
    float x, y, dx, dy;
    bool isFromPlayer, used, isMoving;
};

#endif // SHOT_H