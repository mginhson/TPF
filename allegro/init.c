#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

void init_allegro(void){
    al_init();
    al_install_keyboard();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(320, 200);
}