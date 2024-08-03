#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

class Player
{
private:
    float x, y, dx, dy;
    short life;

public:
    Player();
    ~Player();

    bool init();
    void update();
    void render();
    // void deinit();

    // Getters and Setters
    float getPositionX();
    void setPositionX(float x);

    float getPositionY();
    void setPositionY(float y);

    float getDX();
    void setDX(float dx);

    float getDY();
    void setDY(float dy);
};

#endif