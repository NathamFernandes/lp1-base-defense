#ifndef BASE_H
#define BASE_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

#include "constants.h"

class Base
{
public:
    Base();

    void update();
    void render();
    void reset();

    // Getters and Setters

    int getLife();
    void setLife(int life);

    int getPositionX1();
    int getPositionY1();
    int getPositionX2();
    int getPositionY2();

private:
    int width, height;
    int life;

    int x1, y1, x2, y2;
    int red, green, blue;

    void setRGBColor(int r, int g, int b);
};

#endif // BASE_H