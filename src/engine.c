#include "../include/engine.h"

char map[Y_SIZE][X_SIZE];

void create_map()
{
        for (int i = 0; i < X_SIZE-1; i++)
                map[0][i] = '#';
        map[0][X_SIZE-1] = '\0';

        for (int i = 1; i < Y_SIZE-1; i++) {
                map[i][0] = '#';
                for (int j = 1; j < X_SIZE-2; j++)
                        map[i][j] = ' ';
                map[i][X_SIZE-2] = '#';
                map[i][X_SIZE-1] = '\0';
        }

        for (int i = 0; i < X_SIZE-1; i++)
                map[Y_SIZE-1][i] = '#';
        map[Y_SIZE-1][X_SIZE-1] = '\0';
}

void update_map(struct snake *snake, struct fruit *fruit)
{
        map[fruit->y][fruit->x] = '*';  
        int *s_cords = snake->tail_cords[0];
        for (int i = 0; i < snake->size; i++)
                map[*s_cords++][*s_cords++] = '@';
        s_cords = snake->last_cords;
        if (snake->has_eaten) {
                map[*s_cords++][*s_cords] = '@';
                snake->has_eaten = 0;
                return ;
        }
        else map[*s_cords++][*s_cords] = ' ';
}

void render_map()
{
        for (int i = 0; i < Y_SIZE; i++)
                printf("%s\n", map[i]);
}
