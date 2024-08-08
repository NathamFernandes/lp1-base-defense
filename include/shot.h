#ifndef SHOT_H
#define SHOT_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

class Shot
{
public:
    Shot();
    ~Shot();

    void update();

    // bool isUsed();
    // void setUsed(bool used);

    // int getPositionX();
    // void setPositionX(int x);

    // int getPositionY();
    // void setPositionY(int y);

    // bool init();
    // void deinit();

private:
    float x, y, dx, dy;
    bool isFromPlayer, used, isMoving;
};

#endif