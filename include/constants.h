#ifndef CONSTANTS_H
#define CONSTANTS_H

// Map configs
#define Y_SIZE 15
#define X_SIZE 24
#define Y_UPPER_LIMIT 0
#define Y_LOWER_LIMIT Y_SIZE-1
#define X_LEFT_LIMIT 0
#define X_RIGHT_LIMIT X_SIZE-2

// Snake configs
#define TAIL_SIZE (Y_SIZE-2) * (X_SIZE-2)
#define INITIAL_TAILS 2
#define HEAD_Y 0
#define HEAD_X 1
#define JUNK 1

// Movements
#define UP -1
#define LEFT -1
#define DOWN +1
#define RIGHT +1

#define MICROSECONDS_PER_FRAME 166666 // 6 FPS -> 1/6 SPF

#endif