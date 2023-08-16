#include "maze.h"
#include "time.h"

void maze_init(maze *m) {
    cell c;
    for(int i = 0; i < (MAZE_SIZE * MAZE_SIZE); i++) { 
        cell_init(&c);
        c.x = i % MAZE_SIZE;
        c.y = i / MAZE_SIZE;
        c.index = i;
        m->cells[i] = c;
    }
    for (int i = 0; i < 4; i ++) { 
        m->neighbor_list[i] = -1;
    };

    srand(time(NULL));
}

bool top_neighbor(cell *c, int *storage){
    if ((c->y) > 0){
        *storage = (((c->y) - 1) * MAZE_SIZE) + ((c->x));
        return true;
    }

    return false;
};

bool bottom_neighbor(cell *c, int *storage){
    if ((c->y) < (MAZE_SIZE -1)){
        *storage = (((c->y) + 1) * MAZE_SIZE) + ((c->x));
        return true;
    }
    return false;
};

bool left_neighbor(cell *c, int *storage){
    if ((c->x) > 0){
        *storage =  (((c->y)) * MAZE_SIZE) + ((c->x) -1);
        return true;
    }
    return false;
};

bool right_neighbor(cell *c, int *storage){
    if ((c->x) < (MAZE_SIZE -1)){
        *storage = (((c->y)) * MAZE_SIZE) + ((c->x)+1);
        return true;
    }
    return false;
};

bool has_neighbor(cell *c, maze *m){
    bool has_neighbor = false;
    int index;

    if (top_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            //puts("has neighbor top");
            m->neighbor_list[0] = index;
            has_neighbor = true;
        }
    };
    if (bottom_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            //puts("has neighbor bot");
            m->neighbor_list[1] = index;
            has_neighbor =  true;
        }
    };
    if (left_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            //puts("has neighbor left");
            m->neighbor_list[2] = index;
            has_neighbor  = true;
        }
    };
    if (right_neighbor(c, &index)) {
        if (!(m->cells[index].visited)) {
            //puts("has neighbor right");
            m->neighbor_list[3] = index;
            has_neighbor  = true;
        }
    };

    if (!has_neighbor) {
        //puts("no neighbor");
    };

    return has_neighbor;      
}

int random_neighbor(maze *m) {
    int i;
    while(true) {
        int r = rand() % 4;
        if (m->neighbor_list[r] != -1) {
            i = m->neighbor_list[r];
            break;
        };
    };
    clear_neighbor_list(m);
    return i;
}

void clear_neighbor_list(maze *m) {
    for (int i = 0; i < 4; i++) { 
        m->neighbor_list[i] = -1;
    }
}

void break_wall(maze *m, int *c_index, int *t_index) {

    //printf("the value of c-index is: %d", *c_index);
    //printf("the value of t-index is: %d", *t_index);

    if ((*c_index - MAZE_SIZE) == *t_index) {
        //puts("broke top and bottom wall");
        m->cells[*c_index].top_wall = false;
        m->cells[*t_index].bottom_wall = false;
    };

    if ((*c_index + MAZE_SIZE) == *t_index) {
        //puts("broke bottom and top wall");
        m->cells[*c_index].bottom_wall = false;
        m->cells[*t_index].top_wall = false;
    };

    if ((*c_index - 1) == *t_index) {
        //puts("broke left and right wall");
        m->cells[*c_index].left_wall = false;
        m->cells[*t_index].right_wall = false;
    };

    if ((*c_index + 1) == *t_index) { 
        //puts("broke right and left wall");
        m->cells[*c_index].right_wall = false;
        m->cells[*t_index].left_wall = false;
    };
}


void print_maze(maze *m) { 
    for(int i = 0; i < MAZE_SIZE * MAZE_SIZE; i++ ) {
        cell c = m->cells[i];
        print_cell(&c);
        puts("******************");
    }
}

