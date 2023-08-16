#ifndef DRAWER_H
#define DRAWER_H
#include "maze.h"

void drawer_init();
void drawer_render(maze *m, int delay_ms);
void drawer_input();
void drawer_delay(int delay_ms);

#endif