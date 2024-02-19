#include "LinkedList.h"
#include "Stack.h"

void stack_init(Stack* stack) {
    stack->ll = (LL*)malloc(sizeof(LL));
}

void stack_free(Stack* stack) {
    free(stack);
}

void* stack_peek(Stack* stack) {
   return LL_get_back(stack->ll);
}

void* stack_pop(Stack* stack) {
    return LL_remove_back(stack->ll);
}

void stack_push(Stack* stack, void *item) {
    LL_insert_back(stack->ll, item);
}

int stack_size(Stack* stack) {
    return LL_length(stack->ll);
}