#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 4

typedef struct maze {
    cell cells[MAZE_SIZE * MAZE_SIZE];
    int neighbor_list[4];
} maze;

void maze_init(maze *m);

bool top_neighbor(cell *c, int *storage);
bool bottom_neighbor(cell *c, int *storage);
bool left_neighbor(cell *c, int *storage);
bool right_neighbor(cell *c, int *storage);

void clear_neighbor_list(maze *m);
bool has_neighbor(cell *c, maze *m);
int random_neighbor(maze *m);

void break_wall(maze *m, int *c_index, int *t_index);

void print_maze(maze *m);

#endif