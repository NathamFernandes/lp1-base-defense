#include "player.h"

#include <iostream>

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
