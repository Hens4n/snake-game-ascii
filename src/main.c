#include "../include/snake.h"
#include "../include/engine.h"
#include "../include/fruit.h"
#include <unistd.h>
#ifdef _WIN32
#define clear() system("cls")
#else
#define clear() printf("\033[H\033[J")
#endif

void main()
{
        struct snake snake = create_snake();
        struct fruit fruit = create_fruit();
        create_map();
        
        while (snake.alive) {
                clear();
                update_map(&snake, &fruit);
                render_map();
                snake.move(&snake, &fruit);
                usleep(MICROSECONDS_PER_FRAME);
        }
        printf("\nScore: %d\n\n", snake.size - 1 - INITIAL_TAILS);
}
