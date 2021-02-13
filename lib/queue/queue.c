#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node {
  int val;
  struct Node* next;
  struct Node* prev;
} Node;

struct Queue {
  Node* head;
  Node* tail;
  int size;
};

Queue* queue_create()
{
  Queue* q = malloc(sizeof(Queue));

  if (q == NULL) {
    fprintf(stderr, "could not initialize stack");
    exit(1);
  }

  q->size = 0;

  return q;
}

Node* node_create_queue(int val)
{
  Node* n = malloc(sizeof(Node));

  if (n == NULL) {
    fprintf(stderr, "could not initialize stack");
    exit(1);
  }

  n->val = val;
  n->next = NULL;
  n->prev = NULL;

  return n;
}

int queue_empty(Queue* q)
{
  return q->size == 0;
}

int queue_size(Queue* q)
{
  return q->size;
}

int queue_front(Queue* q)
{
  if (queue_empty(q)) {
    fprintf(stderr, "queue is empty");
    return INT_MIN;
  }

  return q->tail->val;
}

int queue_back(Queue* q)
{
  if (queue_empty(q)) {
    fprintf(stderr, "queue is empty");
    return INT_MIN;
  }

  return q->head->val;
}

void queue_shift(Queue* q)
{
  if (queue_empty(q)) {
    fprintf(stderr, "cannot shift from an empty queue");
    exit(1);
  }

  Node* temp = q->tail;
  q->tail = temp->prev;
  q->size--;
  free(temp);
}

void queue_push(Queue* q, int val)
{
  Node* new_node = node_create_queue(val);

  if (queue_empty(q)) {
    q->head = new_node;
    q->tail = new_node;
  } else {
    q->head->prev = new_node;
    new_node->next = q->head;
    q->head = new_node;
  }
  q->size++;
}
