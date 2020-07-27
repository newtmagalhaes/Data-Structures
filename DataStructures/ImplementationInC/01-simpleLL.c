// Implementation of Single Linked List in C

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

#include "ds_simpleLinkedList.h"

int main(void)
{
    // Create empty Linked List pointing to NULL
    printf("\n\tCreated Linked List!\n");
    struct sLinkedList head = {NULL};
    showLL(&head);

    printf("\n\tInserts\n");
    insertFirst(&head, 'a');
    insertLast(&head, '0');
    insertAt(&head, 'e', 2);
    showLL(&head);

    printf("\n\tSearches\n");
    searchData(&head, 'b');
    searchData(&head, '0');
    searchPosition(&head, 42);
    searchPosition(&head, 2);

    printf("\n\tReverse\n");
    showLL(&head);
    reverseLL(&head);
    showLL(&head);

    printf("\n\tDeletes\n");
    deleteFirst(&head);
    deleteLast(&head);
    showLL(&head);

    printf("\n\tFree\n");
    freeLL(&head);
    showLL(&head);

    return 0;
}
