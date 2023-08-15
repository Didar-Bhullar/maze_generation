#include "stack.h"
#include "maze.h"
//#include "cell.h"

int main(void) { 
    stack s;
    maze m;
    int current_index;
    int neighbor_list[4];
    clear_neighbor_list(neighbor_list);

    stack_init(&s);
    maze_init(&m);

    m.cells[1].visited = true;
    m.cells[3].visited = true;

    if (has_neighbor(&(m.cells[4]), &m, neighbor_list)) {
        int random_n = random_neighbor(neighbor_list);
        clear_neighbor_list(neighbor_list);
        printf("random neighbor: %d\n", random_n);
    }


    stack_print(&s);
    return 0;
}