#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "player.h"
#include "base.h"
#include "enemy.h"

using namespace std;

class Game
{
public:
    Game();
    ~Game();

    bool init();
    void run();
    void deinit();
    void update();

private:
    int displayWidth, displayHeight;
    bool running, redraw;
    long score;
    int objAmount; // Parecido com #define SHOTS_N. esboço.
    // Não sei se realmente necessários
    int mousePositionX;
    int mousePositionY;

    int frames;
    int quota;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;

    Player *player;
    Base *base;
    vector<Enemy*> enemies;

    // Shot shots[objAmount];
    // Boss boss;

    unsigned char key[ALLEGRO_KEY_MAX];

    bool must_init(bool test, string description);
    void handleEvents();
    void render();

    // void keyboard_init();
    // void keyboard_update(ALLEGRO_EVENT *event);
};

#endif // GAME_H