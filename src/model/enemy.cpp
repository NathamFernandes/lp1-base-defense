#include "enemy.h"

#include <iostream>

using namespace std;

Enemy::Enemy()
{
    this->life = ENEMY_LIFE;
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
    int xValue = Random::randint(0, DISPLAY_WIDTH);
    int yValue = Random::randint(0, DISPLAY_HEIGHT);

    switch (this->direction)
    {
    case TOP:
        this->setPositionX(xValue);
        this->setPositionY(0);
        break;
    case RIGHT:
        this->setPositionX(DISPLAY_WIDTH); // DISPLAY_WIDTH
        this->setPositionY(yValue);
        break;
    case BOTTOM:
        this->setPositionX(xValue);
        this->setPositionY(DISPLAY_HEIGHT);
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
    int percursoX = (DISPLAY_WIDTH / 2) - this->x;
    int percursoY = (DISPLAY_HEIGHT / 2) - this->y;

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
    al_draw_filled_circle(
        this->x, this->y,
        ENEMY_RADIUS,
        al_map_rgb(255, 0, 0));
}

void Enemy::update()
{
    if (this->life <= 0)
    {
        this->setUsed(false);
        return;
    }

    if (
        !(this->y > 0 && this->y < ((DISPLAY_HEIGHT - BASE_HEIGHT) / 2)) &&
        !(this->y > ((DISPLAY_HEIGHT + BASE_HEIGHT) / 2) && this->y < DISPLAY_HEIGHT) &&
        !(this->x > 0 && this->x < ((DISPLAY_WIDTH - BASE_WIDTH) / 2)) &&
        !(this->x > ((DISPLAY_WIDTH + BASE_WIDTH) / 2) && this->x < DISPLAY_WIDTH)
    )
    {
        this->setUsed(false);
        return;
    }

    // TODO: Adicionar lógica de colisão com os tiros do herói

    this->x += this->dx;
    this->y += this->dy;
}