#include "stack.h"
#include "maze.h"
#include "drawer.h"

int main(void) { 
    int current_index;
    int maze_size = 25;
    int stack_size = maze_size * maze_size;

    stack s;
    maze m;

    stack_init(&s, stack_size);
    maze_init(&m, maze_size);
    drawer_init(&m);

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