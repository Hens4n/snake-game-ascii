#ifndef FRUIT_H
#define FRUIT_H

#include <stdlib.h>
#include <time.h>
#ifndef SNAKE_H
#include "snake.h"
#endif
#ifndef CONSTANTS_H
#include "constants.h"
#endif

struct fruit {
        int y;
        int x;
        void (*generate_fruit)(struct snake *,struct fruit *);
};

struct fruit create_fruit();

void to_generate_fruit(struct snake *snake, struct fruit *fruit);

#endif