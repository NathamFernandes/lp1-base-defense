#include "drop.h"

#include <iostream>

Drop::Drop()
{
    this->points = 0;
    this->type = BASE_LIFE_DROP;
    this->used = false;
}

void Drop::render(ALLEGRO_FONT *font)
{
    if (!this->isUsed())
        return;

    ALLEGRO_COLOR dropColor;

    switch (this->getDropType())
    {
    case AMMUNITION_DROP:
        dropColor = al_map_rgb(120, 140, 130);
        break;
    case PLAYER_LIFE_DROP:
        dropColor = al_map_rgb(255, 130, 110);
        break;
    case BASE_LIFE_DROP:
        dropColor = al_map_rgb(255, 230, 0);
        break;
    case LAST_DROP:
    default:
        break;
    }

    al_draw_filled_rectangle(
        this->x, this->y,
        this->x + DROP_WIDTH, this->y + DROP_HEIGHT,
        dropColor);
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

void Drop::setUsed(bool used)
{
    this->used = used;
}