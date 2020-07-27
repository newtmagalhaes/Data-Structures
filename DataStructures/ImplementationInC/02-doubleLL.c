// Implementation of Double Linked List in C

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

#include "ds_doubleLinkedList.h"

int main(int argc, char const *argv[])
{
    // Create empty Linked List pointing to NULL
    printf("\n\tCreated Linked List!\n");
    struct dLinkedList head = {NULL};
    showLL(&head);

    printf("\n\tInserts\n");
    insertFirst(&head, 'a');
    insertLast(&head, 'd');
    insertAt(&head, 'b', 1);
    insertAt(&head, 'c', 1);
    showLL(&head);

    printf("\n\tSearches\n");
    searchData(&head, 'b');
    searchData(&head, '0');
    searchPosition(&head, 42);
    searchPosition(&head, 2);

    printf("\n\tReverse\n");
    showLL(&head);
    showReverseLL(&head);

    printf("\n\tDeletes\n");
    deleteFirst(&head);
    showLL(&head);
    deleteLast(&head);
    showLL(&head);

    printf("\n\tFree\n");
    freeLL(&head);
    showLL(&head);

    return 0;
}
