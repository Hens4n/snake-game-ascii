#include "../include/fruit.h"

struct fruit create_fruit()
{
        struct fruit fruit;
        srand((unsigned)time(NULL));
        
        fruit.y = (Y_SIZE / 2) - 2;
        fruit.x = X_SIZE / 2;
        fruit. generate_fruit = to_generate_fruit;
        return fruit;
}

void to_generate_fruit(struct snake *snake, struct fruit *fruit)
{
        fruit->y = rand() % (Y_SIZE - 1);
        fruit->x = rand() % (X_SIZE - 1);

        for (int i = 0; i < snake->size; i++) {
                if (fruit->y == snake->tail_cords[i][0]) {
                        fruit->y = rand() % (Y_SIZE - 1);
                }
                if (fruit->x == snake->tail_cords[i][1]) {
                        fruit->x = rand() % (X_SIZE - 1);
                }
        }
        if (fruit->y == Y_UPPER_LIMIT) fruit->y++;
        else if (fruit->y == Y_LOWER_LIMIT) fruit->y--;
        if (fruit->x == X_LEFT_LIMIT) fruit->x++;
        else if (fruit->x == X_RIGHT_LIMIT) fruit->x--;
}