#include <iostream>
#include <string>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

using namespace std;

void must_init(bool test, string description) {
    if (test) return;

    cout << "Could not initialize " << description << endl;
    exit(1);
}


int main() {
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY* display = al_create_display(640, 480);
    must_init(display, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (true) {
        al_wait_for_event(queue, &event);

        switch (event.type) {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here
                redraw = true;
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if (done) break;

        if (redraw & al_event_queue_is_empty(queue)) {
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_text(
                font, al_map_rgb(0, 0, 0),
                320, 240, ALLEGRO_ALIGN_CENTRE,
                "HELLO, WORLD!"
            );
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}