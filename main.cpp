#include <iostream>
#include <allegro5/allegro.h>

#include "chip8.h"
#include "graphics.h"

using namespace std;

int main(int argc, char **argv)
{

    if (argc == 1)
    {
        cerr << "No rom supplied! Quitting.." << endl;
        return -1;
    }

    Chip8 system;
    Graphics graphics(&system);
    system.load(argv[1]);
    
    graphics.draw();

    return 0;
}