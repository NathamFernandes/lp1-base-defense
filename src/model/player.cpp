#include "player.h"

#include <iostream>
#include <cmath>

using namespace std;

Player::Player()
{
    // Valores não definitivos.
    this->x = 320;
    this->y = 240;
    this->dx = 0;
    this->dy = 0;
    this->life = 100;
    this->ammunition = 100;
    this->shotDelay = 0;
}

Player::~Player()
{
    // this->deinit();
}

bool Player::init()
{
    return true;
}

void Player::update()
{
    this->x += this->dx;
    this->y += this->dy;
    if (this->shotDelay > 0)
        this->shotDelay--;
}
void Player::render()
{
    al_draw_filled_circle(this->x, this->y, 10, al_map_rgb_f(1, 0, 1));
}

// Mecânica

bool Player::moveToDestination(int destinationX, int destinationY)
{
    int percursoX = destinationX - this->x;
    int percursoY = destinationY - this->y;

    // Caso já esteja no mesmo lugar do clique, não continua a execução
    if (abs(percursoX) <= 3 && abs(percursoY) <= 3)
        return false;

    float hipotenusa = sqrt((percursoX * percursoX) + (percursoY * percursoY));

    float tempo = hipotenusa / 3;

    float velocidadeX = percursoX / tempo;
    float velocidadeY = percursoY / tempo;

    this->dx = velocidadeX;
    this->dy = velocidadeY;

    return true;
}

void Player::checkIfPlayerIsAtDestination(int destinationX, int destinationY)
{
    // Se o player estiver se movimentando e chegar no range de destino, seta a velocidade dx como 0.
    if (this->x <= destinationX + 2 && this->x >= destinationX - 2)
        this->dx = 0;

    // Se o player estiver se movimentando e chegar no range de destino, seta a velocidade dy como 0.
    if (this->y <= destinationY + 2 && this->y >= destinationY - 2)
        this->dy = 0;
}

void Player::shot()
{
    if (this->ammunition > 0 && this->shotDelay == 0)
    {
        this->ammunition--;
        // Valor arbitrário
        this->shotDelay = 10;

        cout << "Pew pew! Agora voce tem: " << this->ammunition << endl;
    }
}

// Getters and Setters

float Player::getPositionX()
{
    return this->x;
}

void Player::setPositionX(float x)
{
    this->x = x;
}

float Player::getPositionY()
{
    return this->y;
}

void Player::setPositionY(float y)
{
    this->y = y;
}

float Player::getDX()
{
    return this->dx;
}

void Player::setDX(float dx)
{
    this->dx = dx;
}

float Player::getDY()
{
    return this->dy;
}

void Player::setDY(float dy)
{
    this->dy = dy;
}

unsigned short Player::getAmmunition()
{
    return this->ammunition;
}

void Player::setAmmunition(unsigned short ammunition)
{
    this->ammunition = ammunition;
}

unsigned short Player::getShotDelay()
{
    return this->shotDelay;
}

void Player::setShotDelay(unsigned short shotDelay)
{
    this->shotDelay = shotDelay;
}

short Player::getLife()
{
    return this->life;
}
void Player::setLife(short life)
{
    this->life = life;
}