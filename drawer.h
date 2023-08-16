#ifndef DRAWER_H
#define DRAWER_H
#include "maze.h"

void drawer_init(maze *m);
void drawer_render(maze *m);
void drawer_input();
void drawer_delay(int delay_ms);

#endif