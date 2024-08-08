#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

class Player
{
private:
    float x, y, dx, dy;
    short life;
    unsigned short ammunition, shotDelay;
    float destinationX, destinationY;
    bool isMoving;

public:
    Player();
    ~Player();

    bool init();
    void update();
    void render();
    // void deinit();

    // Mecânica

    bool move(int destinationX, int destinationY);
    void stopIfAtDestination();
    void shot();

    // Getters and Setters

    float getPositionX();
    void setPositionX(float x);

    float getPositionY();
    void setPositionY(float y);

    float getDX();
    void setDX(float dx);

    float getDY();
    void setDY(float dy);

    unsigned short getAmmunition();
    void setAmmunition(unsigned short ammunition);

    unsigned short getShotDelay();
    void setShotDelay(unsigned short shotDelay);

    short getLife();
    void setLife(short life);

    float getDestinationX();
    void setDestinationX(float destinationX);

    float getDestinationY();
    void setDestinationY(float destinationY);
};

#endif