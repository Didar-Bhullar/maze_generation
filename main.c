#include "stack.h"
#include "maze.h"
#include "drawer.h"

int main(void) { 
    stack s;
    maze m;
    int current_index;

    stack_init(&s);
    maze_init(&m);
    drawer_init();

    m.cells[0].visited = true;
    stack_push(&s, 0);
        
    while(!is_empty(&s)) {
        drawer_input();
        drawer_render(&m);

        stack_pop(&s,&current_index);
    
        if (has_neighbor(&(m.cells[current_index]), &m)) {
            stack_push(&s, current_index);
            int neighbor_index = random_neighbor(&m);

            break_wall(&m, &current_index, &neighbor_index);
            m.cells[neighbor_index].visited = true;
            stack_push(&s, neighbor_index); 
        }
    }

    print_maze(&m);

    while (true) {
        drawer_input();
        drawer_render(&m);
    }
    return 0;
}