#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "base.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define KEY_SEEN 1
#define KEY_RELEASED 2

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
    /** Lógica botão esquerdo - feature opcional - não tá funcionando */
    // bool isLeftButtonPressed;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;

    Player *player;
    Base *base;
    // Enemy enemy[120];
    // Shot shots[120];
    // Drop drops[120];

    unsigned char key[ALLEGRO_KEY_MAX];

    bool must_init(bool test, string description);
    void handleEvents();
    void render();
    void renderScoreboard();

    // void keyboard_init();
    // void keyboard_update(ALLEGRO_EVENT *event);
};

#endif // GAME_H