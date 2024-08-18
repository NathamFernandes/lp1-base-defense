#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

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
    int enemiesKilled;
    bool isGameOver, isGamePaused, isGameFinished;
    int pauseDelay;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font;
    ALLEGRO_AUDIO_STREAM *music;
    ALLEGRO_SAMPLE *shotSample;
    ALLEGRO_SAMPLE *hitSample[3];
    ALLEGRO_SAMPLE *powerUpSample;
    ALLEGRO_SAMPLE *gameOverSample;
    ALLEGRO_SAMPLE *gameFinishedSample;

    Player *player;
    Base *base;
    vector<Enemy *> enemies;
    vector<Shot *> shots;
    vector<Drop *> drops;
    Drop *drop;

    unsigned char key[ALLEGRO_KEY_MAX];

    bool must_init(bool test, string description);
    void handleEvents();
    void render();
    void renderScoreboard();
    void handlePlayerShot();

    void addShot(bool fromPlayer, int positionX, int positionY, int destinationX, int destinationY, Enemy *enemy = nullptr);
    void playSample(ALLEGRO_SAMPLE *sample, bool louder = false);
    string showTime();
    bool shots_collide(bool fromPlayer, int x, int y, int w, int h);
    bool collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
    void addDrop(int positionX, int positionY);
    bool collectDrop(int x, int y, int w, int h);

    int pointsDistance(int x1, int y1, int x2, int y2);
};

#endif // GAME_H