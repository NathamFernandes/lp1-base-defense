#include "base.h"

Base::Base()
{
    this->width = BASE_WIDTH;
    this->height = BASE_HEIGHT;
    this->life = BASE_LIFE;

    this->x1 = (DISPLAY_WIDTH - this->width) / 2;
    this->y1 = (DISPLAY_HEIGHT - this->height) / 2;
    this->x2 = (DISPLAY_WIDTH + this->width) / 2;
    this->y2 = (DISPLAY_HEIGHT + this->height) / 2;

    this->setRGBColor(0, 255, 0);
}

void Base::update()
{
    this->setRGBColor(0, 0, 0);

    if (this->life >= 80)
        this->setRGBColor(0, 255, 0); // green
    else if (this->life >= 50)
        this->setRGBColor(255, 165, 0); // orange
    else if (this->life >= 20)
        this->setRGBColor(255, 255, 0); // yellow
    else
        this->setRGBColor(255, 0, 0); // red
}

void Base::render()
{
    al_draw_rectangle(
        x1, y1, x2, y2,
        al_map_rgb(red, green, blue),
        BASE_THICKNESS);
}

void Base::setRGBColor(int r, int g, int b)
{
    this->red = r;
    this->green = g;
    this->blue = b;
}

int Base::getLife()
{
    return this->life;
}

void Base::setLife(int life)
{
    this->life = life;
}