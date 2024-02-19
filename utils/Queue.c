#include <stdlib.h>
#include "Queue.h"

// Wow this is super short
// init, new, free


Queue* queue_new() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->ll = (LL*)malloc(sizeof(LL));
    return queue;
}

void queue_init(Queue* queue) {
    queue->ll = (LL*)malloc(sizeof(LL)); 
}

void queue_free(Queue* queue) {
    // TODO - actually make this good
    free(queue);
    queue = NULL;
}

void queue_push(Queue* queue, void *item) {
    LL_insert_back(queue->ll, item);
}

void* queue_pop(Queue* queue) {
    return LL_remove_front(queue->ll);
}

void* queue_peek(Queue* queue) {
    return LL_get_front(queue->ll);
}

int queue_length(Queue* queue) {
    return LL_length(queue->ll);
}