#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;

Queue* queue_create(void);
int queue_back(Queue* s);
int queue_size(Queue* s);
int queue_front(Queue* s);
int queue_empty(Queue* s);
void queue_shift(Queue* s);
void queue_push(Queue* s, int val);
#endif // QUEUE_H
