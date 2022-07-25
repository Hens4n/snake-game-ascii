#ifndef CONIO_H
#define CONIO_H

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit();        // source: https://bitismyth.wordpress.com/2015/06/18/um-kbhit-para-o-linux/
int getch();        // source: https://bitismyth.wordpress.com/2015/06/10/um-getch-multiplataforma/

#endif