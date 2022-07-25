#include "../include/conio.h"

int kbhit()
{
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);


        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);


        if (ch != EOF)
        {
                ungetc(ch, stdin);
                return 1;
        }

        return 0;
}

int getch()
{
        struct termios newtios, oldtios;
        int ch;

        tcgetattr(STDIN_FILENO, &oldtios);

        newtios = oldtios;

        newtios.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newtios);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldtios);

        return ch;
}