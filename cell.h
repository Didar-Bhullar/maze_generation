#ifndef CELL_H
#define CELL_H

#include <stdbool.h>

typedef struct cell {
    int x;
    int y;
    int index;
    bool visited;
    bool top_wall;
    bool bottom_wall;
    bool left_wall;
    bool right_wall;
} cell;

void cell_init(cell *c);
void print_cell(cell *c);

#endif