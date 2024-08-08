#include "shot.h"

#include <iostream>

using namespace std;

Shot::Shot()
{
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
    this->isMoving = false;
    this->isFromPlayer = false;
    this->used = false;
}

void Shot::update()
{
    // if (this->isMoving)
    //     this->stopIfAtDestination();
    this->x += this->dx;
    this->y += this->dy;
}

Shot::~Shot()
{
    // this->deinit();
}

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

void Shot::render()
{
    al_draw_filled_circle(this->x, this->y, SHOT_RADIUS, al_map_rgb(128, 128, 128));
}