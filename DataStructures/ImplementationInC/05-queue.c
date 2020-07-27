// Implementation of fixed size Queue in C with Double Linked List

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/queue_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

#include "ds_queue.h"

int main(int argc, char const *argv[])
{
    // Create empty Linked List pointing to NULL
    printf("\n\tCreated Linked List!\n");
    struct queue fila = {NULL};
    showQ(&fila);

    printf("\n\tInserts\n");
    enqueue(&fila, 'd');
    enqueue(&fila, 'e');
    enqueue(&fila, 'f');
    showQ(&fila);

    printf("\n\tSearches\n");
    searchData(&fila, 'd');
    searchData(&fila, '0');
    searchPosition(&fila, 42);
    searchPosition(&fila, 2);

    printf("\n\tDequeue\n");
    showQ(&fila);
    dequeue(&fila);
    showQ(&fila);

    printf("\n\tFree\n");
    freeQ(&fila);
    showQ(&fila);

    return 0;
}
