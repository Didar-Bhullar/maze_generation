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
Cell *current_cell;
int valid_neighbor_matrix[4]; //top, bottom, left, right
int cells_left_to_visit = size * size;

void setup();
void print_cells();
int *get_valid_neighbor_matrix(int valid_neighbor_matrix[]);
Cell get_valid_neighbor(int valid_neighbor_matrix[]);

int main(void) { 
    setup();
    print_cells();

    int *matrix = get_valid_neighbor_matrix(valid_neighbor_matrix);

    for(int i = 0; i < 4; i++){
        printf("neigbor at index: %d, with value: %d\n", i, *matrix);
        matrix++;
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

    current_cell = &cells[3]; // start from 0,0: Top left corner; First cell
    current_cell->visited = true;

    for(int i = 0; i < 4; i++) {
        valid_neighbor_matrix[i] = 0;
    }

    cells[4].visited = true;

}

Cell get_valid_neighbor(int valid_neighbor_matrix[]){

}


int * get_valid_neighbor_matrix (int valid_neighbor_matrix[]){
    int cur_x = current_cell->x;
    int cur_y = current_cell->y;

    int top_index = current_cell->x + ((current_cell->y-1) * size);
    int bottom_index = current_cell->x + ((current_cell->y+1) * size);
    int left_index = current_cell->x-1 + ((current_cell->y) * size);
    int right_index = current_cell->x+1 + ((current_cell->y) * size);



    //check top neighbor
    if (current_cell->y - 1 >= 0 ) {
        valid_neighbor_matrix[0] =  cells[top_index].visited ? 0: 1;
    }
    
    //check bottom neighbor
    if (current_cell->y + 1 <= (size -1)) { 
        valid_neighbor_matrix[1] =  cells[bottom_index].visited ? 0: 1;
    }

    //check left neighbor
    if (current_cell->x -1 >= 0) {
        valid_neighbor_matrix[2] =  cells[left_index].visited ? 0: 1;
    }

    //check right neighbor
    if (current_cell->x + 1 <= (size-1)) {
        valid_neighbor_matrix[3] =  cells[right_index].visited ? 0: 1;
    }

    return valid_neighbor_matrix;
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