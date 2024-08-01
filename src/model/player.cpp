#include "player.h"

#include <iostream>

using namespace std;

Player::Player()
{
    // Valores random.
    this->x = 100;
    this->y = 100;
    this->dx = 1;
    this->dy = 1;
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

// Getters and Setters

int Player::getPositionX()
{
    return this->x;
}

void Player::setPositionX(int x)
{
    this->x = x;
}

int Player::getPositionY()
{
    return this->y;
}

void Player::setPositionY(int y)
{
    this->y = y;
}