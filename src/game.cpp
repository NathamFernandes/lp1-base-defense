#include "game.h"

using namespace std;

Game::Game()
{
    memset(this->key, 0, sizeof(this->key));
    this->running = true;
    this->redraw = true;
    this->destinationX = 0;
    this->destinationY = 0;
    this->objAmount = 20;
    this->frames = 0;
    this->quota = 0;
    this->enemiesKilled = 0;
    this->isGameOver = false;
    this->isGamePaused = false;
    this->pauseDelay = 10;
    /** Lógica botão esquerdo - feature opcional - não tá funcionando */
    // this->isLeftButtonPressed = false;

    this->player = new Player();
    this->base = new Base();

    this->enemies.resize(OBJECTS_AMOUNT);
    this->shots.resize(OBJECTS_AMOUNT);
    this->drops.resize(OBJECTS_AMOUNT);
    for (int i = 0; i < OBJECTS_AMOUNT; i++)
    {
        this->enemies[i] = new Enemy();
        this->shots[i] = new Shot();
        this->drops[i] = new Drop();
    }
}

Game::~Game()
{
    this->deinit();

    delete this->player;
    delete this->base;

    for (auto enemy : this->enemies)
    {
        delete enemy;
    }

    for (auto shot : this->shots)
    {
        delete shot;
    }

    for (auto drop : this->drops)
    {
        delete drop;
    }
}

bool Game::must_init(bool test, string description)
{
    if (test)
        return true;

    cout << "Could not initialize " << description << endl;
    return false;
}

bool Game::init()
{
    if (!must_init(al_init(), "allegro"))
        return false;

    if (!must_init(al_install_keyboard(), "keyboard"))
        return false;

    if (!must_init(al_install_mouse(), "mouse"))
        return false;

    // Antialiasing
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    if (!must_init(al_init_primitives_addon(), "primitives"))
        return false;

    if (!must_init(al_init_image_addon(), "image"))
        return false;

    this->timer = al_create_timer(1.0 / 60.0);
    if (!must_init(this->timer, "timer"))
        return false;

    this->queue = al_create_event_queue();
    if (!must_init(this->queue, "queue"))
        return false;

    this->display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if (!must_init(this->display, "display"))
        return false;

    this->font = al_create_builtin_font();
    if (!must_init(this->font, "font"))
        return false;

    if (!must_init(al_init_primitives_addon(), "primitives"))
        return false;

    al_register_event_source(
        this->queue, al_get_keyboard_event_source());
    al_register_event_source(
        this->queue, al_get_display_event_source(this->display));
    al_register_event_source(
        this->queue, al_get_timer_event_source(this->timer));
    al_register_event_source(
        this->queue, al_get_mouse_event_source());

    al_start_timer(this->timer);
    return true;
}

void Game::run()
{
    while (running)
    {
        this->handleEvents();
        this->render();
    }
}

void Game::update()
{
    Enemy *enemy;
    Shot *shot;
    Drop *drop;

    this->player->update();
    if (shots_collide(true, this->player->getPositionX(), this->player->getPositionY(), 10, 10))
    {
        short life = this->player->getLife();
        this->player->setLife(life - 1);
    }

    this->base->update();
    if (shots_collide(true, this->base->getPositionX1(), this->base->getPositionY1(), this->base->getPositionX2() - this->base->getPositionX1(), this->base->getPositionY2() - this->base->getPositionY1()))
    {
        short life = this->base->getLife();
        this->base->setLife(life - 1);
    }

    if (this->quota == 0 && this->frames % 150 == 0)
        this->quota = Random::randint(1, 4);

    // Substituição do for (auto enemy : enemies) para abrigar o shots
    for (int i = 0; i < OBJECTS_AMOUNT; i++)
    {
        enemy = this->enemies[i];
        shot = this->shots[i];
        drop = this->drops[i];

        if (!enemy->isUsed() && this->quota > 0)
        {
            enemy->setUsed(true);
            enemy->defineRandomPosition();
            enemy->setVelocity(Random::randfloat(0.2f, 0.8f));

            this->quota--;
        }

        if (enemy->isUsed())
        {
            enemy->update(
                this->player->getPositionX(),
                this->player->getPositionY());

            if (shots_collide(false, enemy->getPositionX(), enemy->getPositionY(), 11, 11))
            {
                enemy->setUsed(false);
                this->enemiesKilled++;
                this->addDrop(enemy->getPositionX(), enemy->getPositionY());
            }

            if (enemy->getShotDelay() == 0 && enemy->isUsed())
                this->addShot(false, enemy->getPositionX(), enemy->getPositionY(), this->player->getPositionX(), this->player->getPositionY(), enemy);

            // Colisão do inimigo com a base
            if (this->collide(
                    this->base->getPositionX1(),
                    this->base->getPositionY1(),
                    this->base->getPositionX2() + BASE_THICKNESS,
                    this->base->getPositionY2() + BASE_THICKNESS,
                    enemy->getPositionX(),
                    enemy->getPositionY(),
                    enemy->getPositionX() + ENEMY_RADIUS,
                    enemy->getPositionY() + ENEMY_RADIUS))
            {
                enemy->setUsed(false);
                int baseLife = this->base->getLife();
                this->base->setLife(baseLife - 5);
            }

            // Colisão dos inimigos com o player
            if (pointsDistance(
                    this->player->getPositionX(),
                    this->player->getPositionY(),
                    enemy->getPositionX(),
                    enemy->getPositionY()) < (PLAYER_RADIUS + ENEMY_RADIUS - 2))
            {
                enemy->setUsed(false);
                int playerLife = this->player->getLife();
                this->player->setLife(playerLife - 5);
            }
        }

        if (drop->isUsed())
        {
            drop->update();
            if (this->collide(
                    this->player->getPositionX(),
                    this->player->getPositionY(),
                    this->player->getPositionX() + 10,
                    this->player->getPositionY() + 10,
                    drop->getPositionX(),
                    drop->getPositionY(),
                    drop->getPositionX() + DROP_WIDTH,
                    drop->getPositionY() + DROP_HEIGHT))
            {
                drop->setUsed(false);
                int points = drop->getPoints();

                switch (drop->getDropType())
                {
                case BASE_LIFE_DROP:
                {
                    int baseLife = this->base->getLife();
                    int newBaseLife = baseLife + points;
                    this->base->setLife(newBaseLife > BASE_LIFE ? BASE_LIFE : newBaseLife);
                    break;
                }
                case PLAYER_LIFE_DROP:
                {
                    int playerLife = this->player->getLife();
                    int newPlayerLife = playerLife + points;
                    this->player->setLife(newPlayerLife > PLAYER_LIFE ? PLAYER_LIFE : newPlayerLife);
                    break;
                }
                case AMMUNITION_DROP:
                {
                    this->player->setAmmunition(this->player->getAmmunition() + points);
                    break;
                }
                case LAST_DROP:
                default:
                    break;
                }
            }
        }

        if (shot->isUsed())
            shot->update();
    }
}

void Game::handleEvents()
{
    ALLEGRO_EVENT event;

    al_wait_for_event(queue, &event);
    switch (event.type)
    {
    case ALLEGRO_EVENT_TIMER:
        if (key[ALLEGRO_KEY_ESCAPE] && this->pauseDelay == 0)
        {
            this->isGamePaused = !this->isGamePaused;
            this->pauseDelay = 10;
        }

        if (key[ALLEGRO_KEY_Q] && !this->isGamePaused && !this->isGameOver)
            this->handlePlayerShot();

        // Faz com que a tecla não fique "apertada" infinitamente
        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
            key[i] &= KEY_SEEN;

        if (!this->isGameOver && !this->isGamePaused)
            this->update();

        if (this->player->getLife() <= 0 || this->base->getLife() <= 0)
            this->isGameOver = true;

        if (this->pauseDelay > 0)
            this->pauseDelay--;
        this->redraw = true;
        this->frames++;
        break;
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
        switch (event.mouse.button)
        {
        case 2: // Botão direito do mouse
        {
            if (!this->player->move(event.mouse.x, event.mouse.y))
                break;

            break;
        }
        default:
            break;
        }

        break;

    case ALLEGRO_EVENT_KEY_DOWN:
        this->key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
        break;
    case ALLEGRO_EVENT_KEY_UP:
        this->key[event.keyboard.keycode] &= KEY_RELEASED;
        break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
        this->running = false;
        break;
    }
}

void Game::render()
{
    if (this->redraw && al_event_queue_is_empty(this->queue))
    {
        al_clear_to_color(al_map_rgb(255, 255, 255));

        for (auto drop : drops)
        {
            drop->render(this->font);
        }

        this->base->render();
        this->player->render();
        this->renderScoreboard();

        if (this->isGameOver)
        {
            al_draw_text(
                this->font,
                al_map_rgb(0, 0, 0),
                DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2,
                ALLEGRO_ALIGN_CENTRE,
                "GAME OVER!");
        }
        else if (this->isGamePaused)
        {
            al_draw_text(
                this->font,
                al_map_rgb(0, 0, 0),
                DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2,
                ALLEGRO_ALIGN_CENTRE,
                "JOGO PAUSADO!");
        }

        // Pode ser substituido com um for tradicional
        for (auto enemy : enemies)
        {
            enemy->render();
        }

        for (auto shot : shots)
        {
            shot->render();
        }

        al_flip_display();

        this->redraw = false;
    }
}

void Game::deinit()
{
    al_destroy_font(this->font);
    al_destroy_display(this->display);
    al_destroy_timer(this->timer);
    al_destroy_event_queue(this->queue);
}

// Aux

void Game::renderScoreboard()
{
    al_draw_textf(
        this->font,
        al_map_rgb(0, 0, 0),
        40, 20,
        ALLEGRO_ALIGN_LEFT,
        "Munição: %d", this->player->getAmmunition());
    al_draw_textf(
        this->font,
        al_map_rgb(0, 0, 0),
        40, 50,
        ALLEGRO_ALIGN_LEFT,
        "Vida do Herói: %d", this->player->getLife());
    al_draw_textf(
        this->font,
        al_map_rgb(0, 0, 0),
        40, 80,
        ALLEGRO_ALIGN_LEFT,
        "Vida da base: %d", this->base->getLife());
    al_draw_textf(
        this->font,
        al_map_rgb(0, 0, 0),
        40, 110,
        ALLEGRO_ALIGN_LEFT,
        "Inimigos mortos: %d", this->enemiesKilled);
    al_draw_textf(
        this->font,
        al_map_rgb(0, 0, 0),
        40, 140,
        ALLEGRO_ALIGN_LEFT,
        "Tempo: %s", this->showTime().c_str());
}

void Game::handlePlayerShot()
{
    if (this->player->getAmmunition() <= 0 || this->player->getShotDelay() > 0)
        return;

    ALLEGRO_MOUSE_STATE state;
    al_get_mouse_state(&state);

    // Shot *currentShot;
    // float destinationX = state.x, destinationY = state.y;

    this->addShot(true, this->player->getPositionX(), this->player->getPositionY(), state.x, state.y);
    this->player->shot();
}

void Game::addShot(bool fromPlayer, int positionX, int positionY, int destinationX, int destinationY, Enemy *enemy)
{
    Shot *shot;

    for (int i = 0; i < OBJECTS_AMOUNT; i++)
    {
        shot = this->shots[i];
        if (!shot->isUsed())
        {
            shot->setFromPlayer(fromPlayer);
            shot->setUsed(true);
            shot->setPositionX(positionX);
            shot->setPositionY(positionY);
            shot->move(destinationX, destinationY); // Seta o "bool moving = true" dentro da func.
            if (enemy)
                enemy->setShotDelay(400);

            break;
        }
    }
}

string Game::showTime()
{
    int sec = int(al_get_time()) % 60;
    int min = int(al_get_time()) / 60;

    string secStr = (sec > 9) ? to_string(sec) : ("0" + to_string(sec));
    string minStr = (min > 9) ? to_string(min) : ("0" + to_string(min));

    return minStr + ":" + secStr;
}

// From allegro vivace

bool Game::shots_collide(bool fromPlayer, int x, int y, int w, int h)
{
    // Shot *shot;

    for (int i = 0; i < OBJECTS_AMOUNT; i++)
    {
        // shot = this->shots[i];
        if (!shots[i]->isUsed())
            continue;

        // don't collide with one's own shots
        if (shots[i]->isFromPlayer() == fromPlayer)
            continue;

        int sw, sh;
        if (fromPlayer)
        {
            sw = 10;
            sh = 10;
        }
        else
        {
            sw = 5;
            sh = 5;
        }

        if (this->collide(x, y, x + w, y + h, shots[i]->getPositionX(), shots[i]->getPositionY(), shots[i]->getPositionX() + sw, shots[i]->getPositionY() + sh))
        {
            // fx_add(true, shots[i].x + (sw / 2), shots[i].y + (sh / 2));
            shots[i]->setUsed(false);
            return true;
        }
    }

    return false;
}

bool Game::collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    if (ax1 > bx2)
        return false;
    if (ax2 < bx1)
        return false;
    if (ay1 > by2)
        return false;
    if (ay2 < by1)
        return false;

    return true;
}

void Game::addDrop(int positionX, int positionY)
{
    for (auto drop : this->drops)
    {
        if (!drop->isUsed())
        {
            drop->setDropType((DropType)Random::randint(0, LAST_DROP));
            drop->setPoints(Random::randint(1, 8));
            drop->setPositionX(positionX);
            drop->setPositionY(positionY);
            drop->setUsed(true);
            drop->setLifeTime(DROP_LIFETIME);
            break;
        }
    }
}

int Game::pointsDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}