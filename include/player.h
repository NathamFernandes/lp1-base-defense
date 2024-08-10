#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

class Player
{
private:
    float x, y;
    float dx, dy;
    float destinationX, destinationY;
    short life, ammunition, shotDelay;
    bool isMoving;

public:
    Player();
    ~Player();

    void update();
    void render();

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

    short getAmmunition();
    void setAmmunition(short ammunition);

    short getShotDelay();
    void setShotDelay(short shotDelay);

    short getLife();
    void setLife(short life);

    float getDestinationX();
    void setDestinationX(float destinationX);

    float getDestinationY();
    void setDestinationY(float destinationY);
};

#endif