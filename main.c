#include "stack.h"
#include "maze.h"
#include "drawer.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "%s", "Error: needs an integer arguement for maze_size\n" 
                              "Error: needs an integer arguement for delay\n"
                              "Example: ./main.o 25 10\n");
        exit(1);
    } 

    long maze_size = strtol(argv[1], NULL, 10);
    long delay_ms = strtol(argv[2], NULL, 10);

    int stack_size = maze_size * maze_size;
    int current_index;

    stack s;
    maze m;

    stack_init(&s, stack_size);
    maze_init(&m, maze_size);
    drawer_init();

    m.cells[0].visited = true;
    stack_push(&s, 0);
        
    while(!is_empty(&s)) {
        drawer_input();
        drawer_render(&m, delay_ms);

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
        drawer_render(&m, delay_ms);
    }
    return 0;
}