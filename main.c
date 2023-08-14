#include "stack.h"
#include "maze.h"
//#include "cell.h"

int main(void) { 
    maze m;

    maze_init(&m);
    //print_maze(&m);


    int top = top_index(&(m.cells[3]));
    int bottom = bottom_index(&(m.cells[3]));
    int left = left_index(&(m.cells[3]));
    int right = right_index(&(m.cells[3]));

    printf("top is: %d\n", top);
    printf("bottom is: %d\n", bottom);
    printf("left is: %d\n", left);
    printf("right is: %d\n", right);

    return 0;
}