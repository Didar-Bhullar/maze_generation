#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct maze {
  cell *cells;
  int neighbor_list[4];
  int maze_size;
} maze;

void maze_init(maze *m, int maze_s);

bool top_neighbor(cell *c, int *storage, maze *m);
bool bottom_neighbor(cell *c, int *storage, maze *m);
bool left_neighbor(cell *c, int *storage, maze *m);
bool right_neighbor(cell *c, int *storage, maze *m);

void clear_neighbor_list(maze *m);
bool has_neighbor(cell *c, maze *m);
int random_neighbor(maze *m);

void break_wall(maze *m, int *c_index, int *t_index);

void print_maze(maze *m);

#endif