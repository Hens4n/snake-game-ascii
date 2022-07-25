#ifndef ENGINE_H
#define ENGINE_H

#include "snake.h"
#ifndef FRUIT_H
#include "fruit.h"
#endif
#ifndef CONSTANTS_H
#include "constants.h"
#endif

extern char map[Y_SIZE][X_SIZE];

void create_map();

void update_map(struct snake *snake, struct fruit *fruit);

void render_map();

#endif
