#ifndef SHOT_H
#define SHOT_H

#include <allegro5/allegro_primitives.h>

#include "constants.h"

class Shot
{
public:
    Shot();
    ~Shot();

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
    float dx, dy, x, y;
    bool isBulletFromSelf;
};

#endif // SHOT_H