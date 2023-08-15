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
bool bottom_neighbor(cell *c, int *storage);
bool left_neighbor(cell *c, int *storage);
bool right_neighbor(cell *c, int *storage);

bool has_neighbor(cell *c, maze *m, int neighbor_list[]);

void print_maze(maze *m);

#endif