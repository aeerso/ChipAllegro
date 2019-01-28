#ifndef _EMULATE_DISPLAY_H_
#define _EMULATE_DISPLAY_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;


class Graphics {

    private:
        ALLEGRO_DISPLAY* display_pnt;
        //Dimension are hard-coded as 64 * 32 = 2048
        uint8_t* pixel_matrix;

        float cell_width;
        float cell_height;
        unsigned screen_width;
        unsigned screen_height;

    public:
        Graphics(uint8_t *pixels);
        ALLEGRO_DISPLAY* init_allegro();
        void draw();

};
#endif
