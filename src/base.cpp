#include "base.h"

Base::Base()
{
    this->width = 200;
    this->height = 180;
    this->life = 10;

    // 640: DISPLAY_WIDTH
    // 480: DISPLAY_HEIGHT
    // TODO: obter automaticamente os valores de DISPLAY_WIDTH e DISPLAY_HEIGHT
    this->x1 = (640 / 2) - (this->width / 2);
    this->y1 = (480 / 2) - (this->height / 2);
    this->x2 = (640 / 2) + (this->width / 2);
    this->y2 = (480 / 2) + (this->height / 2);

    this->red = 0;
    this->green = 255;
    this->blue = 0;
}

void Base::update()
{
    this->red = 0;
    this->green = 0;
    this->blue = 0;

    if (this->life >= 80) // green
    {
        this->green = 255;
    }
    else if (this->life >= 50) // orange
    {
        this->red = 255;
        this->green = 165;
    }
    else if (this->life >= 20) // yellow
    {
        this->red = 255;
        this->green = 255;
    }
    else // red
    {
        this->red = 255;
    }
}

void Base::render() {
    al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(red, green, blue), 7);
}