#include "player.h"

#include <iostream>
#include <cmath>

using namespace std;

Player::Player()
{
    // Valores random.
    this->x = 100;
    this->y = 100;
    this->dx = 0;
    this->dy = 0;
    this->life = 5;
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
}
void Player::render()
{
    al_draw_filled_circle(this->x, this->y, 10, al_map_rgb_f(1, 0, 1));
}

// Movimentação

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
