#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int nb_elements;
  int *buffer;
  int size;

} stack;

void stack_init(stack *s, int size);
int stack_push(stack *s, int value);
int stack_pop(stack *s, int *storage);
bool is_empty(stack *s);

void stack_print(stack *s);

#endif