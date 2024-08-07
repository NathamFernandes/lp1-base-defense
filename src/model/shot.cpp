#include "shot.h"

#include <iostream>

using namespace std;

Shot::Shot()
{
    this->dx = 0;
    this->dy = 0;
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