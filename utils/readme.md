# C Programming Utilities!

These are some c utilities I have make to make some of my future assignements a bit easier
These are still a work in progress and I still need to create a Makefile to handle all of the depedndencies.

## Example ussage

```c
#include "utils.h"

char* word1 = "first";
char* word2 = "second";
char* word3 = "third";

stack_push(&stack, &word1);
printf("peek %s\n", *(char**)stack_peek(&stack));
stack_push(&stack, &word2);
printf("peek %s\n", *(char**)stack_peek(&stack));
stack_push(&stack, &word3);
printf("peek %s\n", *(char**)stack_peek(&stack));

for (int i = 0; i < 3; i++) {
    printf("pop: %s\n", *(char**)stack_pop(&stack));
}
```
