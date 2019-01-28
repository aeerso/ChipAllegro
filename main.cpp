#include <iostream>
#include <allegro5/allegro.h>

#include "chip8.h"
#include "emulate_display.h"

using namespace std;


int main(int argc, char **argv){




//     float sx = 800 / (float)64;
//     float sy = 600 / (float)32;

//     ALLEGRO_TRANSFORM trans;
//     al_identity_transform(&trans);
//     al_scale_transform(&trans, sx, sy);
//     al_use_transform(&trans);

//    al_clear_to_color(al_map_rgb(0,0,0));

//     for(unsigned i = 0; i < 800; i++){
//         for(unsigned j = 0; j < 300; j++){
//             al_draw_pixel(i, j, al_map_rgb(255,255,255));
//         }
//     }


//   al_flip_display();
//   al_rest(300);





    Chip8 system;
    Graphics graphics(system.getPixelMatrix());
    system.load("pong.rom");
    while(true){
    system.emulate_cycle();
    graphics.draw();
    }




    // while(true){
    //     system.emulate_cycle();
    //     if(system.getDrawFlag()){
    //         cout << "PAPERA" << endl;
    //         system.resetDrawFlag();
    //         //void al_draw_pixel(float x, float y, ALLEGRO_COLOR color)
    //         for(unsigned i = 0; i < 2048; i++){
    //             for(unsigned j = 0; j < 2048; j++){
    //                  if(unsigned(system.getPixelMatrix()[i]) == 0){
    //                      al_draw_pixel(i % 64, j % 32, al_map_rgb(0,0,0));
    //                      al_flip_display();
    //                  } else if(unsigned(system.getPixelMatrix()[i]) == 255){
    //                      al_draw_pixel(i % 64, j % 32, al_map_rgb(255,255,255));
    //                      al_flip_display();
    //                  }
    //             }
    //          }
    //         cout << "ALPACA" << endl;

            //al_clear_to_color(al_map_rgb(255,255,255));
            //al_flip_display();
            //cout << unsigned(system.getPixelMatrix()[1]) << endl;
            //break;
    //    }
    //}
       //al_rest(10.0);


}