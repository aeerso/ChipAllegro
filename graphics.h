#ifndef _EMULATE_DISPLAY_H_
#define _EMULATE_DISPLAY_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "chip8.h"
using namespace std;


class Graphics {

    private:
        Chip8* chip8;
        ALLEGRO_DISPLAY* display_pnt;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_TIMER *timer;
        bool redraw = true;

        float fps;

        float cell_width;
        float cell_height;
        unsigned screen_width;
        unsigned screen_height;

    public:
        Graphics(Chip8* system);
        void init_allegro();
        void draw();

};
#endif
