#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    float x, y, dx, dy;
    short life;

public:
    Player();
    ~Player();

    bool init();
    // void deinit();

    // Getters and Setters
    int getPositionX();
    void setPositionX(int x);

    int getPositionY();
    void setPositionY(int y);
};

#endif