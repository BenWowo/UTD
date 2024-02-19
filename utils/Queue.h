#ifndef QUEUE_H
#define QUEUE_H
// I think I can create a binding to the length call 
// on the linked list that it is bound to
// I also could just manage the size here...
#include "LinkedList.h"

struct Queue {
    LL* ll;
};
typedef struct Queue Queue;
// push, pop, peek, length

// it would be interesting to specify a linked list for the new function
Queue* queue_new();
void   queue_init(Queue* queue);
void   queue_free(Queue* queue);
void queue_push(Queue* queue, void *item);
void* queue_pop(Queue* queue);
void* queue_peek(Queue* queue);
int   queue_length(Queue* queue);

#endif // QUEUE_H