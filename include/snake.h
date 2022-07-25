#ifndef SNAKE_H
#define SNAKE_H

#ifdef _WIN32
#include <conio.h>
#else
#include "conio.h"
#endif
#include "fruit.h"
#ifndef CONSTANTS_H
#include "constants.h"
#endif


struct snake {
        int tail_cords[TAIL_SIZE][2];
        int last_cords[2];
        int size;
        int has_eaten;
        int alive;
        int y;
        int x;
        char key_value;
        void (*is_alive)(struct snake *);
        void (*eat)(struct snake *, struct fruit *);
        void (*move)(struct snake *, struct fruit *);
};

struct snake create_snake();

int block_move(int cord_ref_a, int cord_ref_b);

void to_eat(struct snake *snake, struct fruit *fruit);

void is_snake_alive(struct snake *snake);

void to_move(struct snake *snake, struct fruit *fruit);

void change_cords(int x, int y, struct snake *snake, struct fruit *fruit);


#endif
