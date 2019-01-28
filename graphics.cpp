#include "graphics.h"

Graphics::Graphics(Chip8 *system)
{
    init_allegro();
    redraw = true;
    fps = 30;
    chip8 = system;
    screen_width = al_get_display_width(display_pnt);
    screen_height = al_get_display_height(display_pnt);

    cell_width = screen_width / 64;
    cell_height = screen_height / 32;

    if (screen_width % 64 != 0 || screen_height % 32 != 0)
    {
        cout << "[Graphics] Display size is not optimal for this emulation. Expect issues." << endl;
    }

    cout << "[Graphics] Loaded correctly. Block size is: " << cell_width * cell_height << endl;
}

void Graphics::init_allegro()
{

    if (display_pnt != NULL)
    {
        al_destroy_display(display_pnt);
    }

    if (!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
    }

    display_pnt = al_create_display(1024, 768);
    if (!display_pnt)
    {
        fprintf(stderr, "failed to create display!\n");
    }

    timer = al_create_timer(1.0 / 200);
    if (!timer)
    {
        fprintf(stderr, "failed to create timer!\n");
    }

    event_queue = al_create_event_queue();
    if (!event_queue)
    {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(display_pnt);
        al_destroy_timer(timer);
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
    }
}

void Graphics::draw()
{

    al_register_event_source(event_queue, al_get_display_event_source(display_pnt));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_flip_display();
    al_start_timer(timer);

    while (1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        chip8->emulate_cycle();
        if (chip8->getDrawFlag())
        {
            chip8->resetDrawFlag();
            uint32_t pixels[2048];
            for (int i = 0; i < 2048; ++i)
            {
                uint8_t pixel = chip8->getGFX()[i];
                //RGB Colors: 00 - Transparency; FF = R  FF = G FF = B
                pixels[i] = (0x00FFFFFF * pixel) | 0xFF000000;
            }

            float x1 = 0;
            float x2 = cell_width;
            float y1 = 0;
            float y2 = cell_height;
            unsigned pixel_count = 0;

            for (unsigned y_index = 0; y_index < screen_height; y_index += cell_height)
            {
                for (unsigned x_index = 0; x_index < screen_width; x_index += cell_width)
                {

                    //Kinda shitty conversion, will get better via bit shifting and stuff idk
                    int current = (int)pixels[pixel_count];
                    if (current == -1)
                    {
                        al_draw_filled_rectangle(x_index, y_index, x_index + cell_width, y_index + cell_height, al_map_rgb(255, 255, 255));
                    }
                    else
                    {
                        al_draw_filled_rectangle(x_index, y_index, x_index + cell_width, y_index + cell_height, al_map_rgb(0, 0, 0));
                    }
                    pixel_count += 1;
                }
            }
            al_flip_display();
        }
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            return;
        }
    }
}