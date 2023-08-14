#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 3

typedef struct maze {
    cell cells[MAZE_SIZE * MAZE_SIZE];

} maze;

void maze_init(maze *m);

int top_index(cell *c);

void print_maze(maze *m);

#endif