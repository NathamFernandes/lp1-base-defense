#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "base.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Game
{
public:
    Game();
    ~Game();

    bool init();
    void run();
    void deinit();

private:
    int displayWidth, displayHeight;
    bool running, redraw;
    long score;
    int destinationX, destinationY;
    /** Lógica botão esquerdo - feature opicional - não tá funcionando */
    // bool isLeftButtonPressed;

    // unsigned int objAmount = 128; // Parecido com #define SHOTS_N. esboço.

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;

    Player *player;
    Base *base;

    // Enemy enemy[objAmount];
    // Shot shots[objAmount];
    // Drop drops[objAmount];

    unsigned char key[ALLEGRO_KEY_MAX];

    bool must_init(bool test, string description);
    void handleEvents();
    void render();

    // void keyboard_init();
    // void keyboard_update(ALLEGRO_EVENT *event);
};

#endif // GAME_H