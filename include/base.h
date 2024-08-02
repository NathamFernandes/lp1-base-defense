#ifndef BASE_H
#define BASE_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

class Base
{
public:
    Base();

    void update();
    void render();
private:
    int width;
    int height;
    int life;

    int x1, y1, x2, y2;
    int red, green, blue;
};

#endif // BASE_H