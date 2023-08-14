#include "stack.h"

int main(void) { 
    int x;
    stack my_stack;

    stack_init(&my_stack);
    stack_push(&my_stack, 1);
    stack_push(&my_stack, 2);
    stack_push(&my_stack, 3);
    stack_pop(&my_stack, &x);
    stack_print(&my_stack);
    printf("x value is: %d\n",  x);

    stack_push(&my_stack,100);
    stack_print(&my_stack);

    return 0;
}