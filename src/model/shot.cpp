#include "shot.h"

#include <iostream>

using namespace std;

Shot::Shot()
{
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
}

Shot::~Shot()
{
    // this->deinit();
}