#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

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
int valid_neighbor_matrix[4];   // returns array with valid neighbor indexes, else -1
int cells_left_to_visit = size * size;

void setup();
void print_cells();
void generate_valid_neightbor_list();
int get_random_neighbor();
void break_walls();

int main(void) { 
    setup();
    //print_cells();

    generate_valid_neightbor_list();

    for(int i = 0; i < 4; i++){
        printf("neigbor at index value: %d\n", valid_neighbor_matrix[i]);
    }

    if (get_random_neighbor()) {
        printf("random neighbor at index: %d\n", random_neighbor_index);
        break_walls();
        current_cell_index = random_neighbor_index;
    } else {
        puts ("random neighbor does not exist\n");
    }
    puts("**********************");
    print_cells();

    return 0;
}

void setup() {
    srand(time(NULL));
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

    current_cell_index = 0;
    cells[current_cell_index].visited = true;

    for(int i = 0; i < 4; i++) {
        valid_neighbor_matrix[i] = -1;
    }

    //cells[3].visited = true;

}

void break_walls() {
    // if from current index, index + 1, then break right wall for current, left wall for soon to be new current
    if ((current_cell_index + 1) == random_neighbor_index) { 
        cells[current_cell_index].right_wall = false;
        cells[random_neighbor_index].left_wall = false;
    }
    // if from current index, index + -1, then break left wall for current, right wall for soon to be new current
    if ((current_cell_index -1) == random_neighbor_index) {
        cells[current_cell_index].left_wall = false;
        cells[random_neighbor_index].right_wall = false;
    }
    // if from current index, index + size, then break bottom wall for current, top wall for soon to be new current
    if ((current_cell_index + size) == random_neighbor_index) {
        cells[current_cell_index].bottom_wall = false;
        cells[random_neighbor_index].top_wall = false;
    }
    // if from current index, index - size , then break top wall for current, bottom wall for soon to be new current
    if ((current_cell_index - size) == random_neighbor_index) {
        cells[current_cell_index].top_wall = false;
        cells[random_neighbor_index].bottom_wall = false;
    }
}

int get_random_neighbor() {
    // return true if random neighbor exists
    // return false if no random neighbor eixsts
    bool neighbor_exists = false;

    for(int i = 0; i < 4; i++) {
        if (valid_neighbor_matrix[i] != -1) {
            neighbor_exists = true;
            break;
        }
    }

    if (neighbor_exists) {
        while(1) { 
            int r = rand() % 4;
            if (valid_neighbor_matrix[r] != -1) {
                random_neighbor_index = valid_neighbor_matrix[r];
                return true;
            }
        }

    } else {
        return false;
    }
}


void generate_valid_neightbor_list () {
    int cur_x = cells[current_cell_index].x;
    int cur_y = cells[current_cell_index].y;

    int top_index = cur_x + ((cur_y-1) * size);
    int bottom_index = cur_x + ((cur_y+1) * size);
    int left_index = cur_x-1 + ((cur_y) * size);
    int right_index = cur_x+1 + ((cur_y) * size);

    //check top neighbor
    if (cur_y - 1 >= 0 ) {
        if (!(cells[top_index].visited)) { valid_neighbor_matrix[0] = top_index; };
    }
    
    //check bottom neighbor
    if (cur_y + 1 <= (size -1)) {
        if (!(cells[bottom_index].visited) ) { valid_neighbor_matrix[1] = bottom_index; };
    }

    //check left neighbor
    if (cur_x -1 >= 0) {
        if (!(cells[left_index].visited)) { valid_neighbor_matrix[2] = left_index; };
    }

    //check right neighbor
    if (cur_x + 1 <= (size-1)) {
        if (!(cells[right_index].visited)) { valid_neighbor_matrix[3] = right_index; };
    }
}

void clear_valid_neighbor_matrix() {
    for(int i = 0; i < 4; i++) {
        valid_neighbor_matrix[i] = -1;
    }
}

void print_cells() {
    for(int i = 0; i < size*size; i++) {
        printf("index: %d\n", i);
        printf("x pos: %d\n", cells[i].x);
        printf("y pos: %d\n", cells[i].y);
        printf("visited: %d\n", cells[i].visited);
        printf("top_wall: %d\n", cells[i].top_wall);
        printf("bottom_wall: %d\n", cells[i].bottom_wall);
        printf("left_wall: %d\n", cells[i].left_wall);
        printf("right_wall: %d\n", cells[i].right_wall);
        printf("------------\n");
    }
}