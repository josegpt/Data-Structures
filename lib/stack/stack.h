#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* stack_create();
int stack_top(Stack* s);
void stack_pop(Stack* s);
int stack_size(Stack* s);
int stack_empty(Stack* s);
void stack_push(Stack* s, int val);
#endif // STACK_H
