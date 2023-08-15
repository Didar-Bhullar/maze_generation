#include "stack.h"
#include "maze.h"
//#include "cell.h"

int main(void) { 
    maze m;

    maze_init(&m);
    //print_maze(&m);

    int index_test = 0;


    int top_n_i;
    int bot_n_i;
    int left_n_i;
    int right_n_i;

    bool top = top_neighbor(&(m.cells[index_test]), &top_n_i);
    bool bottom = bottom_neighbor(&(m.cells[index_test]), &bot_n_i);
    bool left = left_neighbor(&(m.cells[index_test]), &left_n_i);
    bool right = right_neighbor(&(m.cells[index_test]), &right_n_i);

    printf("top neighbor exists: %d, top is: %d\n",top, top_n_i);
    printf("bottom neighbor exists: %d, bottom is: %d\n",bottom, bot_n_i);
    printf("left neighbor exists: %d, left is: %d\n",left, left_n_i);
    printf("right neighbor exists: %d, right is: %d\n",right, right_n_i);

    return 0;
}