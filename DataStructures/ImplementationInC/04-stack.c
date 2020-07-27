// Implementation of fixed size Stack in C with Linked List

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

#include "ds_stack.h"

int main(int argc, char const *argv[])
{
    // Create empty Stack pointing to NULL
    printf("\n\tCreated Stack!\n");
    struct stack pilha = {limit, NULL};
    showS(&pilha);

    printf("\n\tPush\n");
    pushS(&pilha, 'a');
    pushS(&pilha, 'b');
    pushS(&pilha, 'c');
    pushS(&pilha, 'd');
    pushS(&pilha, 'e');
    pushS(&pilha, 'f');
    showS(&pilha);

    printf("\n\tPeek\n");
    peekS(&pilha);

    printf("\n\tPop\n");
    popS(&pilha);
    popS(&pilha);
    showS(&pilha);

    printf("\n\tFree\n");
    freeS(&pilha);
    showS(&pilha);

    return 0;
}