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

public:
    Player();
    ~Player();

    bool init();
    void update();
    void render();
    // void deinit();

    // Mecânica

    /**
     * Move o Player para o destino do clique.
     *
     * @return true, caso a operação seja concluída.
     * @return false, caso o player já esteja no local.
     */
    bool moveToDestination(int destinationX, int destinationY);

    /**
     * Caso o Player estiver no destino, seta DX e DY como 0.
     */
    void checkIfPlayerIsAtDestination(int destinationX, int destinationY);

    /**
     * Lida com os valores da munição e do delay entre os tiros.
     */
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
};

#endif