#include "../include/snake.h"

struct snake create_snake()
{
        struct snake snake;

        snake.size = 1 + INITIAL_TAILS;
        for (int i = 0; i < snake.size; i++) {
                snake.tail_cords[i][0] = ((Y_SIZE) / 2) + 1 + i;
                snake.tail_cords[i][1] = ((X_SIZE) / 2);
        }
        snake.y = -1;
        snake.x = 0;
        snake.last_cords[0] = JUNK;
        snake.last_cords[1] = JUNK;
        snake.has_eaten = 0;
        snake.alive = 1;
        snake.key_value = 'w';
        snake.is_alive = is_snake_alive;
        snake.move = to_move;
        snake.eat = to_eat;

        return snake;
}

int block_move(int cord_ref_a, int cord_ref_b)
{
        return (cord_ref_a > cord_ref_b);
}

void to_eat(struct snake *snake, struct fruit *fruit)
{
        if (snake->tail_cords[0][HEAD_Y] == fruit->y &&
            snake->tail_cords[0][HEAD_X] == fruit->x) {
                snake->size++;
                snake->has_eaten = 1;
                fruit->generate_fruit(snake, fruit);
        }
}

void is_snake_alive(struct snake *snake)
{
        if (snake->tail_cords[0][HEAD_Y] == Y_UPPER_LIMIT ||
            snake->tail_cords[0][HEAD_Y] == Y_LOWER_LIMIT ||
            snake->tail_cords[0][HEAD_X] == X_LEFT_LIMIT  ||
            snake->tail_cords[0][HEAD_X] == X_RIGHT_LIMIT) {
                snake->alive = 0;
                return ;
            }
        for (int i = 1; i < snake->size; i++) {
                if (snake->tail_cords[0][HEAD_Y] == snake->tail_cords[i][0] &&
                    snake->tail_cords[0][HEAD_X] == snake->tail_cords[i][1]) {
                        snake->alive = 0;
                        return ;
                    }
        }
}

void to_move(struct snake *snake, struct fruit *fruit)
{
        if (kbhit()) {
                snake->key_value = getch();
        }
        switch (snake->key_value)
        {
        case 'W':
        case 'w':
                if (snake->y != DOWN) {
                        snake->y = UP;
                        snake->x = 0;
                }
                break;
        case 'A':
        case 'a':
                if (snake->x != RIGHT) {
                        snake->y = 0;
                        snake->x = LEFT;
                }
                break;
        case 'S':
        case 's':
                if (snake->y != UP) {
                        snake->y = DOWN;
                        snake->x = 0;
                }
                break;
        case 'D':
        case 'd':
                if (snake->x != LEFT) {
                        snake->y = 0;
                        snake->x = RIGHT;
                }
                break;
        default:
                break;
        }
        change_cords(snake->x, snake->y, snake, fruit);
}

void change_cords(int x, int y, struct snake *snake, struct fruit *fruit)
{
        int tmp_y0 = snake->tail_cords[0][HEAD_Y];
        int tmp_x0 = snake->tail_cords[0][HEAD_X];
        snake->last_cords[0] = snake->tail_cords[snake->size-1][0];
        snake->last_cords[1] = snake->tail_cords[snake->size-1][1];
        snake->tail_cords[0][HEAD_Y] += y;
        snake->tail_cords[0][HEAD_X] += x;
        snake->is_alive(snake);
        snake->eat(snake, fruit);
        for (int i = 1; i <= snake->size-1; i++) {
                int tmp_y1 = snake->tail_cords[i][0];
                int tmp_x1 = snake->tail_cords[i][1];
                snake->tail_cords[i][0] = tmp_y0;
                snake->tail_cords[i][1] = tmp_x0;
                tmp_y0 = tmp_y1;
                tmp_x0 = tmp_x1;
        }
}