#include "game.h"

#include <iostream>

using namespace std;

Game::Game() {
    this->running = true;
    this->redraw = true;
    this->base = new Base(640, 480);
}

Game::~Game() {
    this->deinit();
}

bool Game::must_init(bool test, string description) {
    if (test) return true;

    cout << "Could not initialize " << description << endl;
    return false;
}

bool Game::init() {
    if (!must_init(al_init(), "allegro")) return false;

    this->timer = al_create_timer(1.0 / 60.0);
    if (!must_init(this->timer, "timer")) return false;

    this->queue = al_create_event_queue();
    if (!must_init(this->queue, "queue")) return false;

    this->display = al_create_display(640, 480);
    if (!must_init(this->display, "display")) return false;

    this->font = al_create_builtin_font();
    must_init(this->font, "font");

    if (!must_init(al_init_primitives_addon(), "primitives")) return false;

    al_register_event_source(
        this->queue, al_get_display_event_source(this->display)
    );
    al_register_event_source(
        this->queue, al_get_timer_event_source(this->timer)
    );

    al_start_timer(this->timer);
    return true;
}

void Game::run() {
    while (running) {
        this->handleEvents();
        // Atualizar estado dos elementos

        this->base->update();

        this->render();
    }
}

void Game::handleEvents() {
    ALLEGRO_EVENT event;

    al_wait_for_event(queue, &event);
    switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
            // TODO: criar função para lidar com update dos elementos
            // this->update();
            this->base->update();

            this->redraw = true;
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            this->running = false;
            break;
    }
}

void Game::render() {
    if (this->redraw && al_event_queue_is_empty(this->queue)) {
        al_clear_to_color(al_map_rgb(255, 255, 255));

        this->base->render();

        al_flip_display();

        this->redraw = false;
    }
}

void Game::deinit() {
    al_destroy_font(this->font);
    al_destroy_display(this->display);
    al_destroy_timer(this->timer);
    al_destroy_event_queue(this->queue);

    delete this->base;
}