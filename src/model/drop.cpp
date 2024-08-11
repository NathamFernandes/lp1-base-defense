#include "drop.h"

#include <iostream>

Drop::Drop()
{
    this->x = 0;
    this->y = 0;
    this->points = 0;
    this->type = BASE_LIFE_DROP;
    this->used = false;
}

void Drop::render(ALLEGRO_FONT *font)
{
    al_draw_filled_rectangle(
        this->x, this->y,
        this->x + DROP_WIDTH, this->y + DROP_HEIGHT,
        al_map_rgb(180, 245, 150));
    al_draw_text(
        font,
        al_map_rgb(0, 0, 0),
        this->x + (DROP_WIDTH / 2),
        this->y + (DROP_HEIGHT / 2) - 2,
        ALLEGRO_ALIGN_CENTER,
        to_string(this->points).c_str());
}

int Drop::getPositionX()
{
    return this->x;
}

void Drop::setPositionX(int x)
{
    this->x = x;
}

int Drop::getPositionY()
{
    return this->y;
}

void Drop::setPositionY(int y)
{
    this->y = y;
}

int Drop::getPoints()
{
    return this->points;
}

void Drop::setPoints(int points)
{
    this->points = points;
}

DropType Drop::getDropType()
{
    return this->type;
}

void Drop::setDropType(DropType type)
{
    this->type = type;
}

bool Drop::isUsed()
{
    return this->used;
}

void Drop::setUsed(int used)
{
    this->used = used;
}