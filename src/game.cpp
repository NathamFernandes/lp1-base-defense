#include "game.h"

#include <iostream>
#include <cmath>

using namespace std;

Game::Game()
{
    this->displayWidth = 640;
    this->displayHeight = 480;
    this->running = true;
    this->redraw = true;
    this->destinationX = 0;
    this->destinationY = 0;
    /** Lógica botão esquerdo - feature opcional - não tá funcionando */
    // this->isLeftButtonPressed = false;

    this->player = new Player();
    this->base = new Base(this->displayWidth, this->displayHeight);

    memset(this->key, 0, sizeof(this->key));
    // this->shots[i]->shots_init();
    // this->enemy[i]->enemy_init();
    // this->drops[i]->olollo;
}

Game::~Game()
{
    this->deinit();

    delete this->player;
    delete this->base;
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

    this->display = al_create_display(this->displayWidth, this->displayHeight);
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

void Game::handleEvents()
{
    ALLEGRO_EVENT event;

    al_wait_for_event(queue, &event);

    switch (event.type)
    {
    case ALLEGRO_EVENT_TIMER:
        // TODO: criar função para lidar com update dos elementos
        // this->update();

        if (key[ALLEGRO_KEY_ESCAPE])
        {
            this->running = false;
            // TODO: feature opcional de pause
            // this->pause = true;
        }
        if (key[ALLEGRO_KEY_Q])
        {
            this->player->shot();
        }

        // Não sei o que isso faz direito, mas faz com
        // que a tecla não fique "apertada" infinitamente
        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
            key[i] &= KEY_SEEN;

        this->player->checkIfPlayerIsAtDestination(this->destinationX, this->destinationY);

        this->base->update();
        this->player->update();

        this->redraw = true;
        break;
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
        switch (event.mouse.button)
        {
        case 2: // Botão direito do mouse
        {
            cout << "Apertou o botão direito do Mouse!" << endl;

            if (!this->player->moveToDestination(event.mouse.x, event.mouse.y))
                break;

            this->destinationX = event.mouse.x;
            this->destinationY = event.mouse.y;
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
        al_draw_text(
            this->font,
            al_map_rgb(0, 0, 0),
            320, 240,
            ALLEGRO_ALIGN_CENTRE,
            "HELLO, WORLD!");
        this->renderScoreboard();
        this->player->render();
        this->base->render();

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
        60, 20,
        ALLEGRO_ALIGN_CENTRE,
        "Munição: %d", this->player->getAmmunition());
    al_draw_textf(
        this->font,
        al_map_rgb(0, 0, 0),
        60, 50,
        ALLEGRO_ALIGN_CENTRE,
        "Vida: %d", this->player->getLife());
}