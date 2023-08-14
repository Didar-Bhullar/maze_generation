#include "cell.h"
#include <stdio.h>

void cell_init(cell *c){
    c-> x = -1;
    c-> y = -1;
    c-> index = -1;
    c-> visited = false;
    c-> top_wall = true;
    c-> bottom_wall = true;
    c-> left_wall = true;
    c-> right_wall = true;
};

void print_cell(cell *c){
    printf("x: %d\n", c->x);
    printf("y: %d\n", c->y);
    printf("index: %d\n", c->index);
    printf("visited: %d\n", c->visited);
    printf("top_wall: %d\n", c->top_wall);
    printf("bottom_wall: %d\n", c->bottom_wall);
    printf("left_wall: %d\n", c->left_wall);
    printf("right_wall: %d\n", c->right_wall);
}