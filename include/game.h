#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define KEY_SEEN 1
#define KEY_RELEASED 2

#include "player.h"
#include "base.h"
#include "enemy.h"
#include "shot.h"
#include "drop.h"

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
    bool running, redraw;
    long score;
    int destinationX, destinationY;
    /** Lógica botão esquerdo - feature opcional - não tá funcionando */
    // bool isLeftButtonPressed;
    int objAmount; // Parecido com #define SHOTS_N. esboço.
    int frames;
    int quota;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;

    Player *player;
    Base *base;
    vector<Enemy *> enemies;
    vector<Shot *> shots;
    vector<Drop *> drops;

    unsigned char key[ALLEGRO_KEY_MAX];

    bool must_init(bool test, string description);
    void handleEvents();
    void render();
    void renderScoreboard();
    void handlePlayerShot();

    void addShot(bool fromPlayer, int positionX, int positionY, int destinationX, int destinationY, Enemy *enemy = nullptr);
    string showTime();
    bool shots_collide(bool fromPlayer, int x, int y, int w, int h);
    bool collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
};

#endif // GAME_H