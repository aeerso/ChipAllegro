#ifndef CHIP_8_H
#define CHIP_8_H
#include <stdint.h>

class Chip8 {
    private:
        uint16_t stack[16];     //Memory stack
        uint16_t sp;            //Stack Pointer

        uint8_t memory[4096];    //4K ram
        uint8_t V[16];           //V register (from V0 to VF)

        uint16_t pc;            //Process counter
        uint16_t opcode;        //opcode
        uint16_t I;             //Index register

        uint8_t delay_timer;
        uint8_t sound_timer;

        uint8_t gfx[64 * 32];   //Graphical matrix
        uint8_t pixels[2048];  //Acutal pixel matrix
        uint8_t key[16];        //NOT in use rn, but for keys input

        bool drawFlag;        //If something was draw
        

    public:
        Chip8();
        ~Chip8();

        void emulate_cycle();
        bool load(const char *file_path);
        void init();
        void show_display();
        bool getDrawFlag();
        void resetDrawFlag();
        uint8_t* getPixelMatrix();
        

};

#endif