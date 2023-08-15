#include "stack.h"
#include "maze.h"
//#include "cell.h"

int main(void) { 
    stack s;
    maze m;
    int current_index;
    int neighbor_list[4] = {-1};

    stack_init(&s);
    maze_init(&m);

    m.cells[0].visited = true;
    stack_push(&s, 0);

    while(!is_empty(&s)) {
        clear_neighbor_list(neighbor_list);
        stack_pop(&s,&current_index);
        if (has_neighbor(&(m.cells[current_index]), &m, neighbor_list)) {
            stack_push(&s, current_index);
            int neighbor_index = random_neighbor(neighbor_list);
            break_wall(&m, &current_index, &neighbor_index);
            m.cells[neighbor_index].visited = true;
            stack_push(&s, neighbor_index);
        }
    }

    //stack_print(&s);
    print_maze(&m);
    return 0;
}