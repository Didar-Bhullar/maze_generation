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

bool top_neighbor(cell *c, int *storage);
int bottom_neighbor(cell *c, int *storage);
int left_neighbor(cell *c, int *storage);
int right_neighbor(cell *c, int *storage);

void print_maze(maze *m);

#endif