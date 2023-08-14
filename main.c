#include "stack.h"
#include "maze.h"
//#include "cell.h"

int main(void) { 
    maze m;

    maze_init(&m);
    //print_maze(&m);


    int top = top_index(&(m.cells[1]));
    printf("top is: %d\n", top);

    return 0;
}