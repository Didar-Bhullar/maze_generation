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

bool top_neighbor(cell *c, int *storage){
    if ((c->x) > 0){
        *storage = (((c->x) - 1) * MAZE_SIZE) + ((c->y));
        return true;
    }

    return false;
};

bool bottom_neighbor(cell *c, int *storage){
    if ((c->x) < (MAZE_SIZE -1)){
        *storage = (((c->x) + 1) * MAZE_SIZE) + ((c->y));
        return true;
    }
    return false;
};

bool left_neighbor(cell *c, int *storage){
    if ((c->y) > 0){
        *storage =  (((c->x)) * MAZE_SIZE) + ((c->y) -1);
        return true;
    }
    return false;
};

bool right_neighbor(cell *c, int *storage){
    if ((c->y) < (MAZE_SIZE -1)){
        *storage = (((c->x)) * MAZE_SIZE) + ((c->y)+1);
        return true;
    }
    return false;
};

bool has_neighbor(cell *c, maze *m, int neighbor_list[]){
    bool has_neighbor = false;
    int index;

    if (top_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            puts("has neighbor top");
            neighbor_list[0] = index;
            has_neighbor = true;
        }
    };
    if (bottom_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            puts("has neighbor bot");
            neighbor_list[1] = index;
            has_neighbor =  true;
        }
    };
    if (left_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            puts("has neighbor left");
            neighbor_list[2] = index;
            has_neighbor  = true;
        }
    };
    if (right_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            puts("has neighbor right");
            neighbor_list[3] = index;
            has_neighbor  = true;
        }
    };

    if (!has_neighbor) {
        puts("no neighbor");
    };

    return has_neighbor;      
}



void print_maze(maze *m) { 
    for(int i = 0; i < MAZE_SIZE * MAZE_SIZE; i++ ) {
        cell c = m->cells[i];
        print_cell(&c);
        puts("******************");
    }
}

