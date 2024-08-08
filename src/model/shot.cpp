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