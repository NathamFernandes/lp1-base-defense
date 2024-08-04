#include "enemy.h"

#include <iostream>

using namespace std;

Enemy::Enemy()
{
    this->life = 5;
    this->used = false;
    this->defineRandomPosition();
    this->calculateVelocity();
}

bool Enemy::isUsed()
{
    return this->used;
}

void Enemy::setUsed(bool used)
{
    this->used = used;
}

void Enemy::defineRandomPosition()
{
    this->direction = (Direction)Random::randint(0, LAST);
    int xValue = Random::randint(0, 640);
    int yValue = Random::randint(0, 480);

    switch (this->direction)
    {
    case TOP:
        this->setPositionX(xValue); // DISPLAY_WIDTH
        this->setPositionY(0);
        break;
    case RIGHT:
        this->setPositionX(640); // DISPLAY_WIDTH
        this->setPositionY(yValue);
        break;
    case BOTTOM:
        this->setPositionX(xValue);
        this->setPositionY(480);
        break;
    case LEFT:
        this->setPositionX(0);
        this->setPositionY(yValue);
        break;
    default:
        break;
    }
}

void Enemy::calculateVelocity()
{
    int percursoX = (640 / 2) - this->x;
    int percursoY = (480 / 2) - this->y;

    float hypot = sqrt(pow(percursoX, 2) + pow(percursoY, 2));

    float time = hypot;

    float xVelocity = percursoX / time;
    float yVelocity = percursoY / time;

    this->dx = xVelocity;
    this->dy = yVelocity;
}

int Enemy::getPositionX()
{
    return this->x;
}

void Enemy::setPositionX(int x)
{
    this->x = x;
}

int Enemy::getPositionY()
{
    return this->y;
}

void Enemy::setPositionY(int y)
{
    this->y = y;
}

void Enemy::render()
{
    al_draw_filled_circle(this->x, this->y, 9, al_map_rgb(255, 0, 0));
}

void Enemy::update()
{
    if (this->life <= 0)
    {
        this->used = false;
    }

    if (
        !((this->y < 480 && this->y > 330) || (this->y > 0 && this->y < 150)) &&
        !((this->x > 0 && this->x < 220) || (this->x > 420 && this->x < 640)))
    {
        this->used = false;
    }

    this->x += this->dx;
    this->y += this->dy;

    // if (!this->used)
    // {
    //     this->defineRandomPosition();
    //     this->calculateVelocity();
    //     this->used = true;
    // }
}