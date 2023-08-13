#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 3

typedef struct Cell{
    int x;
    int y;
    bool visited;
    bool top_wall;
    bool bottom_wall;
    bool left_wall;
    bool right_wall;
} Cell;

Cell cells[size * size];
int current_cell_index;
int random_neighbor_index;
int valid_neighbor_matrix[4]; //top, bottom, left, right
int cells_left_to_visit = size * size;

void setup();
void print_cells();
void generate_valid_neighbor_matrix();
int get_random_neighbor();
void break_walls();

int main(void) { 
    setup();
    print_cells();

    generate_valid_neighbor_matrix();

    for(int i = 0; i < 4; i++){
        printf("neigbor at index: %d, with value: %d\n", i, valid_neighbor_matrix[i]);
    }

    return 0;
}

void setup() { 
    Cell cell;

    for(int i = 0; i < (size * size); i++) { 
        int x_pos = i % size;
        int y_pos = i / size; 

        cell.x = x_pos;
        cell.y = y_pos;
        cell.visited = false;
        cell.top_wall = true;
        cell.bottom_wall = true;
        cell.left_wall = true;
        cell.right_wall = true; 

        cells[i] = cell;
    }

    //current_cell = &cells[0]; // start from 0,0: Top left corner; First cell
    current_cell_index = 4;
    //current_cell->visited = true;
    cells[current_cell_index].visited = true;

    for(int i = 0; i < 4; i++) {
        valid_neighbor_matrix[i] = 0;
    }

    cells[3].visited = true;
}

void break_walls() {
    // if from current index, index + 1, then break right wall for current, left wall for soon to be new current
    // if from current index, index + -1, then break left wall for current, right wall for soon to be new current
    // if from current index, index + size, then break bottom wall for current, top wall for soon to be new current
    // if from current index, index - size , then break top wall for current, bottom wall for soon to be new current
}

int get_random_neighbor(){
    // return 0 if random neighbor found
    // return 1 if random neighbor found

}


void generate_valid_neighbor_matrix () {
    int cur_x = cells[current_cell_index].x;
    int cur_y = cells[current_cell_index].y;

    int top_index = cur_x + ((cur_y-1) * size);
    int bottom_index = cur_x + ((cur_y+1) * size);
    int left_index = cur_x-1 + ((cur_y) * size);
    int right_index = cur_x+1 + ((cur_y) * size);



    //check top neighbor
    if (cur_y - 1 >= 0 ) {
        valid_neighbor_matrix[0] =  cells[top_index].visited ? 0: 1;
    }
    
    //check bottom neighbor
    if (cur_y + 1 <= (size -1)) { 
        valid_neighbor_matrix[1] =  cells[bottom_index].visited ? 0: 1;
    }

    //check left neighbor
    if (cur_x -1 >= 0) {
        valid_neighbor_matrix[2] =  cells[left_index].visited ? 0: 1;
    }

    //check right neighbor
    if (cur_x + 1 <= (size-1)) {
        valid_neighbor_matrix[3] =  cells[right_index].visited ? 0: 1;
    }
}

void clear_valid_neighbor_matrix() {
    for(int i = 0; i < 4; i++) {
        valid_neighbor_matrix[i] = 0;
    }
}

void print_cells() {
    for(int i = 0; i < size*size; i++) {
        printf("index: %d\n", i);
        printf("x pos: %d\n", cells[i].x);
        printf("y pos: %d\n", cells[i].y);
        printf("visited: %d\n", cells[i].visited);
        //printf("top_wall: %d\n", cells[i].top_wall);
        //printf("bottom_wall: %d\n", cells[i].bottom_wall);
        //printf("left_wall: %d\n", cells[i].left_wall);
        //printf("right_wall: %d\n", cells[i].right_wall);
        printf("------------\n");
    }
}