#include "stack.h"

void stack_init(stack *s, int size) {
  s->top = 0;
  s->nb_elements = 0;
  s->size = size;
  s->buffer = malloc(size * sizeof(int));
}

int stack_push(stack *s, int value) {
  if (s->nb_elements == s->size) {
    return false;
  }

  s->buffer[s->top] = value;
  s->nb_elements++;
  s->top++;
  return true;
}

int stack_pop(stack *s, int *storage) {
  if (s->nb_elements == 0) {
    return false;
  }

  s->top--;
  s->nb_elements--;
  *storage = s->buffer[s->top];
  return true;
}

bool is_empty(stack *s) {
  if (s->nb_elements == 0) {
    return true;
  }
  return false;
}

void stack_print(stack *s) {
  for (int i = 0; i < s->nb_elements; i++) {
    printf("stack at index: %d, value: %d\n", i, s->buffer[i]);
  }
  printf("number of elements: %d\n", s->nb_elements);
  printf("top of stack: %d\n", s->top);
}
