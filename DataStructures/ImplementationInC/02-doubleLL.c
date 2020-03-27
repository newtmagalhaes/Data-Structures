// Implementation of Double Linked List in C

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next,
        *prev;
};

struct Head
{
    struct Node *first;
};

/// Return 0 if Linked List is empty, otherwise, return 1
int isEmpty(struct Head *start)
{
    if (!start->first)
    {
        // case start->first equal NULL
        return 0;
    }
    else
    {
        return 1;
    }
}

/// Return the number of nodes in a Linked List
unsigned sizeofLL(struct Head *start)
{
    unsigned size = 0;
    struct Node *current = start->first;
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

/// Show Linked List at the console
void showLL(struct Head *start)
{
    struct Node *current = start->first;
    printf("start: NULL <-[ ");
    while (current)
    {
        printf("'%c' ", current->data);
        current = current->next;
        // break when current equal NULL
    }
    printf("]-> NULL;\n");
}

/// Show Reverse Linked List at the console
void showReverseLL(struct Head *start)
{
    struct Node *current = start->first;
    // go to the last node
    while (current->next)
    {
        current = current->next;
        // break when current->next equal NULL
    }
    printf("start: NULL <-[ ");
    while (current)
    {
        printf("'%c' ", current->data);
        current = current->prev;
        // break when current equal NULL
    }
    printf("]-> NULL;\n");
}

/// Create a newNode and inserts at first position of Linked List
void insertFirst(struct Head *start, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        // case newNode equal NULL
        printf("Failed Malloc!!\n");
    }
    else
    {
        newNode->prev = NULL;
        newNode->data = data;
        if (!start->first)
        {
            newNode->next = NULL;
        }
        else
        {
            struct Node *oldFirst = start->first;
            newNode->next = oldFirst;
            oldFirst->prev = newNode;
        }
        start->first = newNode;
        printf("Insert '%c' at first position!\n", data);
    }
}

/// Create a newNode and insert at last position of Linked List
void insertLast(struct Head *start, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        // case newNode equal NULL
        printf("Failed Malloc!!\n");
    }
    else
    {
        if (!start->first)
        {
            // case start->first equal NULL
            insertFirst(start, data);
        }
        else
        {
            struct Node *current = start->first;
            while (current->next)
            {
                current = current->next;
                // break when current->next equal NULL
            }
            current->next = newNode;
            newNode->prev = current;
            newNode->next = NULL;
            newNode->data = data;
            printf("Insert '%c' at last position!\n", data);
        }
    }
}

/// Create a newNode and insert at any position of Linked List
void insertAt(struct Head *start, char data, unsigned position)
{
    if (position >= sizeofLL(start) - 1)
    {
        // case position is greater than last position
        insertLast(start, data);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode)
        {
            // case newNodde equal NULL
            printf("Failed Malloc!!\n");
        }
        else
        {
            struct Node *current = start->first,
                        *oldNext = current->next;
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
            oldNext = current->next;
            newNode->next = oldNext;
            newNode->prev = current;
            newNode->data = data;
            current->next = newNode;
            oldNext->prev = newNode;
            printf("Insert '%c' at position %d!\n", data, position);
        }
    }
}

/// Delete first node of Linked List
void deleteFirst(struct Head *start)
{
    if (!start->first)
    {
        // case start->first equal NULL
        printf("Double Linked List is empty!\n");
    }
    else
    {
        struct Node *current = start->first;
        start->first = current->next;
        if (current->next)
        {
            // case current->next != NULL
            struct Node *newFirst = current->next;
            newFirst->prev = NULL;
            current->next = NULL;
        }
        free(current);
        printf("First node Deleted!\n");
    }
}

/// Delete last node of Linked List
void deleteLast(struct Head *start)
{
    if (!start->first)
    {
        // case start->first equal NULL
        printf("Double Linked List is empty!\n");
    }
    else
    {
        struct Node *current = start->first;
        while (current->next)
        {
            current = current->next;
        }
        if (!current->prev)
        {
            // case current->prev equal NULL
            start->first = NULL;
        }
        else
        {
            struct Node *newLast = current->prev;
            newLast->next = NULL;
            current->prev = NULL;
        }
        free(current);
        printf("Last node Deleted!\n");
    }
}

/// Delete node at any position of Linked List
void deleteAt(struct Head *start, unsigned position)
{
    if (position >= sizeofLL(start) - 1)
    {
        deleteLast(start);
    }
    else if (position == 0)
    {
        deleteFirst(start);
    }
    else
    {
        struct Node *current = start->first,
                    *newNext = current->next,
                    *previous = current->prev;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        newNext = current->next;
        previous = current->prev;
        newNext->prev = previous;
        previous->next = newNext;
        current->next = NULL;
        current->prev = NULL;
        free(current);
        printf("Node deleted at position %d!\n", position);
    }
}

/// Return the 0-based position of the first occurrence of @param data, otherwise, return -1
int searchData(struct Head *start, char data)
{
    struct Node *current = start->first;
    int position = 0;
    while (current)
    {
        if (current->data == data)
        {
            printf("Data '%c' at position %d;\n", data, position);
            return position;
        }
        current = current->next;
        position++;
    }
    printf("Data '%c' doesn't exists\n", data);
    return -1;
}

/// Return the data (char) of the node at @param position
char searchPosition(struct Head *start, unsigned position)
{
    if (position >= sizeofLL(start))
    {
        // case position greater than valid
        printf("Invalid position!\n");
        return '\0';
    }
    else
    {
        struct Node *current = start->first;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        printf("Char '%c' at position %d!\n", current->data, position);
        return current->data;
    }
}

/// Deallocate memory allocated for Linked List
void freeLL(struct Head *start)
{
    while (sizeofLL(start))
    {
        deleteLast(start);
    }
    printf("Free!!\n");
}

int main(int argc, char const *argv[])
{
    // Create empty Linked List pointing to NULL
    printf("\n\tCreated Linked List!\n");
    struct Head linkedList = {NULL};
    showLL(&linkedList);

    printf("\n\tInserts\n");
    insertFirst(&linkedList, 'a');
    insertLast(&linkedList, 'd');
    insertAt(&linkedList, 'b', 1);
    insertAt(&linkedList, 'c', 1);
    showLL(&linkedList);

    printf("\n\tSearches\n");
    searchData(&linkedList, 'b');
    searchData(&linkedList, '0');
    searchPosition(&linkedList, 42);
    searchPosition(&linkedList, 2);

    printf("\n\tReverse\n");
    showLL(&linkedList);
    showReverseLL(&linkedList);

    printf("\n\tDeletes\n");
    deleteFirst(&linkedList);
    showLL(&linkedList);
    deleteLast(&linkedList);
    showLL(&linkedList);

    printf("\n\tFree\n");
    freeLL(&linkedList);
    showLL(&linkedList);

    return 0;
}
