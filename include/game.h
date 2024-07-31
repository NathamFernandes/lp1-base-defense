#ifndef GAME_H
#define GAME_H

#include <string>

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
    bool running, redraw;
    long score;
    unsigned int objAmount = 128; // Parecido com #define SHOTS_N. esboço.

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;

    // Player player;
    // Enemy enemy[objAmount];
    // Shot shots[objAmount];
    // Base base;
    // Boss boss;

    unsigned char key[ALLEGRO_KEY_MAX];

    bool must_init(bool test, string description);
    void handleEvents();
    void render();

    // void keyboard_init();
    // void keyboard_update(ALLEGRO_EVENT *event);
};

#endif // GAME_H