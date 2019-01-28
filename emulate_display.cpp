#include "emulate_display.h"

Graphics::Graphics(uint8_t *pixels) {
    display_pnt = init_allegro();
    pixel_matrix = pixels;
    screen_width = al_get_display_width(display_pnt);
    screen_height = al_get_display_height(display_pnt);
    
    cell_width = screen_width / 64;
    cell_height = screen_height / 32;

    if(screen_width % 64 != 0 || screen_height % 32 != 0){
        cout << "[Graphics] Display size is not optimal for this emulation. Expect issues." << endl;
    }

    cout << "[Graphics] Loaded correctly. Block size is: " << cell_width * cell_height << endl;
}



ALLEGRO_DISPLAY* Graphics::init_allegro(){
    
    if(display_pnt != NULL){
        al_destroy_display(display_pnt);
    }

    if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return NULL;
    }

    display_pnt = al_create_display(1024, 768);
    if(!display_pnt) {
      fprintf(stderr, "failed to create display!\n");
      return NULL;
    }

    return display_pnt;
}



void Graphics::draw(){

    uint32_t pixels[2048];
 
    for (int i = 0; i < 2048; ++i) {
        uint8_t pixel = pixel_matrix[i];
        //RGB Colors: 00 - Transparency; FF = R  FF = G FF = B
        pixels[i] = (0x00FFFFFF * pixel) | 0xFF000000;
        }

    float x1 = 0;
    float x2 = cell_width;
    float y1 = 0;
    float y2 = cell_height;
    unsigned pixel_count = 0;

    for(unsigned y_index = 0; y_index < screen_height; y_index += cell_height){
        for(unsigned x_index = 0; x_index < screen_width; x_index += cell_width){
            
            //Kinda shitty conversion, will get better via bit shifting and stuff idk
            int current = (int)pixels[pixel_count];
            
            if(current == -1){
            al_draw_filled_rectangle(x_index, y_index, x_index + cell_width, y_index + cell_height, al_map_rgb(255,255,255));
            } else {
            al_draw_filled_rectangle(x_index, y_index, x_index + cell_width, y_index + cell_height, al_map_rgb(0,0,0));    
            }
            pixel_count += 1;   
        }
    }

    cout << "Pixel count: " << pixel_count << endl;
    al_flip_display();



}