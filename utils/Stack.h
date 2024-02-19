#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "LinkedList.h"

struct Stack {
    int size;
    LL* ll;
};
typedef struct Stack Stack;

void stack_init(Stack* stack);
void stack_free(Stack* stack);
void* stack_peek();
void* stack_pop();
void stack_push();
int  stack_size();

#endif //STACK_H