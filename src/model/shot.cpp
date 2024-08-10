#include "shot.h"

#include <iostream>
#include <cmath>

#include "constants.h"

using namespace std;

Shot::Shot()
{
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
    this->moving = false;
    this->fromPlayer = false;
    this->used = false;
}

Shot::~Shot()
{
    // this->deinit();
}

void Shot::update()
{
    if (this->moving && (this->x < 0 || this->x > DISPLAY_WIDTH || this->y < 0 || this->y > DISPLAY_HEIGHT))
    {
        this->used = false;
        return;
    }

    this->x += this->dx;
    this->y += this->dy;
}

void Shot::render()
{
    if (!this->isUsed())
        return;

    al_draw_filled_circle(this->x, this->y, SHOT_RADIUS, al_map_rgb(128, 128, 128));
}

// Mecânica

bool Shot::move(int destinationX, int destinationY)
{
    int percursoX = destinationX - this->x;
    int percursoY = destinationY - this->y;

    if (abs(percursoX) <= 5 && abs(percursoY) <= 5)
        return false;

    float hipotenusa = sqrt((percursoX * percursoX) + (percursoY * percursoY));

    float tempo = hipotenusa / (this->fromPlayer ? 9 : 3);

    float velocidadeX = percursoX / tempo;
    float velocidadeY = percursoY / tempo;

    this->dx = velocidadeX;
    this->dy = velocidadeY;
    this->destinationX = destinationX;
    this->destinationY = destinationY;

    this->moving = true;

    return true;
}

// Getters and Setters

int Shot::getPositionX()
{
    return this->x;
}

void Shot::setPositionX(int x)
{
    this->x = x;
}

int Shot::getPositionY()
{
    return this->y;
}

void Shot::setPositionY(int y)
{
    this->y = y;
}

int Shot::getDX()
{
    return this->dx;
}

void Shot::setDX(int dx)
{
    this->dx = dx;
}

int Shot::getDY()
{
    return this->dy;
}

void Shot::setDY(int dy)
{
    this->dy = dy;
}

bool Shot::isUsed()
{
    return this->used;
}

bool Shot::isMoving()
{
    return this->moving;
}

void Shot::setMoving(bool moving)
{
    this->moving = moving;
}

void Shot::setUsed(bool used)
{
    this->used = used;
}

bool Shot::isFromPlayer()
{
    return this->fromPlayer;
}

void Shot::setFromPlayer(bool fromPlayer)
{
    this->fromPlayer = fromPlayer;
}