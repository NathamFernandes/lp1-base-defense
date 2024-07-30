#ifndef GAME_H
#define GAME_H

#include <string>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

using namespace std;

class Game {
public:
    Game();
    ~Game();

    bool init();
    void run();
    void deinit();
private:
    bool running, redraw;

    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_FONT* font;

    bool must_init(bool test, string description);
    void handleEvents();
    void render();
};

#endif // GAME_H