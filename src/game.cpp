#include "game.h"

#include <iostream>

using namespace std;

Game::Game()
{
    this->running = true;
    this->redraw = true;
}

Game::~Game()
{
    this->deinit();
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

    this->display = al_create_display(640, 480);
    if (!must_init(this->display, "display"))
        return false;

    this->font = al_create_builtin_font();
    if (!must_init(this->font, "font"))
        return false;

    al_register_event_source(
        this->queue, al_get_keyboard_event_source());
    al_register_event_source(
        this->queue, al_get_display_event_source(this->display));
    al_register_event_source(
        this->queue, al_get_timer_event_source(this->timer));
    al_register_event_source(
        this->queue, al_get_mouse_event_source());

    // Classes init
    this->player = new Player();
    must_init(this->player->init(), "player");
    // for (int i = 0; i < this->objAmount; i++) {
    // this->shots[i]->shots_init();
    // this->enemy[i]->enemy_init();
    // }
    // this->base->base_init();
    // this->boss->boss_init() ??

    al_start_timer(this->timer);
    return true;
}

void Game::run()
{
    while (running)
    {
        this->handleEvents();
        // Atualizar estado dos elementos
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
        this->redraw = true;
        break;
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
        switch (event.mouse.button)
        {
        case 1: // Botão esquerdo do mouse
            cout << "PRIMEIRO!" << endl;
            // Lógica para seguir o mouse até soltar
            break;
        case 2: // Botão direito do mouse
            cout << "SEGUNDO!" << endl;
            // Lógica para seguir o ponto clicado pelo mouse até chegar ou ser interrompido por outro evento
            break;
        default:
            break;
        }
        // Esboços que podem ser úteis.
        // this->mousePositionX = event.mouse.x;
        // this->mousePositionY = event.mouse.y;
        // player->setPositionX(event.mouse.x);
        // player->setPositionY(event.mouse.y);
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
        al_draw_filled_circle(player->getPositionX(), player->getPositionY(), 10, al_map_rgb_f(1, 0, 1));
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