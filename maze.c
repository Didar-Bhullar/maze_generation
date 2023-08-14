#include "maze.h"

void maze_init(maze *m) {
    cell c;
    for(int i = 0; i < (MAZE_SIZE * MAZE_SIZE); i++) { 
        cell_init(&c);
        c.y = i % MAZE_SIZE;
        c.x = i / MAZE_SIZE;
        c.index = i;
        m->cells[i] = c;
    }
}

int top_index(cell *c){
    return (((c->x) - 1) * MAZE_SIZE) + ((c->y));
};

int bottom_index(cell *c){
    return (((c->x) + 1) * MAZE_SIZE) + ((c->y));
};

int left_index(cell *c){
    return (((c->x)) * MAZE_SIZE) + ((c->y) -1);
};

int right_index(cell *c){
    return (((c->x)) * MAZE_SIZE) + ((c->y)+1);
};



void print_maze(maze *m) { 
    for(int i = 0; i < MAZE_SIZE * MAZE_SIZE; i++ ) {
        cell c = m->cells[i];
        print_cell(&c);
        puts("******************");
    }
}

