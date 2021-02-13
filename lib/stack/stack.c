#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Node {
  int val;
  struct Node* next;
} Node;

struct Stack {
  Node* head;
  int size;
};

Stack* stack_create()
{
  Stack* s = malloc(sizeof(Stack));

  if (s == NULL) {
    fprintf(stderr, "could not initialize stack");
    exit(1);
  }

  s->size = 0;

  return s;
}

Node* node_create(int val)
{
  Node* n = malloc(sizeof(Node));

  if (n == NULL) {
    fprintf(stderr, "could not initialize stack");
    exit(1);
  }

  n->val = val;
  n->next = NULL;

  return n;
}

int stack_empty(Stack* s)
{
  return s->size == 0;
}

int stack_size(Stack* s)
{
  return s->size;
}

int stack_top(Stack* s)
{
  if (stack_empty(s)) {
    fprintf(stderr, "stack is empty");
    return INT_MIN;
  }

  return s->head->val;
}

void stack_pop(Stack* s)
{
  if (stack_empty(s)) {
    fprintf(stderr, "cannot pop from an empty stack");
    exit(1);
  }

  Node* temp = s->head;
  s->head = temp->next;
  free(temp);
  s->size--;
}

void stack_push(Stack* s, int val)
{
  Node* new_node = node_create(val);

  if (stack_empty(s)) {
    s->head = node_create(val);
  } else {
    new_node->next = s->head;
    s->head = new_node;
  }
  s->size++;
}
