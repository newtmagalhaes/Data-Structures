// Implementation of Single Linked List in C

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Head
{
    struct Node *first;
};

/// Return the number of nodes in a Linked List
unsigned sizeofLL(struct Head *start)
{
    unsigned size = 0;
    if (!start->first)
    {
        // case start->first equal NULL
        return size;
    }
    else
    {
        struct Node *current = start->first;
        // break when current equal NULL
        while (current->next != NULL)
        {
            current = current->next;
            size++;
        }
        return size + 1;
    }
}

/// Show Linked List
void showLL(struct Head *start)
{
    struct Node *current = start->first;
    printf("start -> [ ");
    while (current)
    {
        printf("'%c' ", current->data);
        current = current->next;
    }
    printf("] -> NULL\n");
}

/// Create a newNode and inserts at first position of Linked List
void insertFirst(struct Head *start, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        // case newNode equal NULL
        printf("Failled malloc!!\n");
    }
    else
    {
        newNode->data = data;
        if (!start->first)
        {
            // case start->first equal NULL
            newNode->next = NULL;
            start->first = newNode;
        }
        else
        {
            newNode->next = start->first;
            start->first = newNode;
        }
        printf("Insert char '%c' at First position!\n", data);
    }
}

/// Create a newNode and insert at last position of Linked List
void insertLast(struct Head *start, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        // case newNode equal NULL
        printf("Failled malloc!!\n");
    }
    else
    {
        newNode->data = data;
        if (!start->first)
        {
            // case start->first equal NULL
            newNode->next = NULL;
            start->first = newNode;
        }
        else
        {
            struct Node *current = start->first;
            while (current->next)
            {
                // travel the Linked List to the Last node
                current = current->next;
            }
            newNode->next = NULL;
            current->next = newNode;
            printf("Insert char '%c' at Last position!\n", data);
        }
    }
}

/**
 * Create a newNode and insert at any position of Linked List
 * @param position is unsigned-type, so, cannot be less than 0
*/
void insertAt(struct Head *start, char data, unsigned position)
{
    // the index of last position is equal sizeofLL(start) - 1
    if (position == 0)
    {
        // case position is the first position
        insertFirst(start, data);
    }
    else if (position >= sizeofLL(start) - 1)
    {
        // case position is greater than or equal last position
        insertLast(start, data);
    }
    else
    {
        // case position is between the first and the last
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode)
        {
            // case newNode equal NULL
            printf("Failed Malloc!\n");
        }
        else
        {
            newNode->data = data;
            struct Node *current = start->first,
                        *previous = NULL;
            for (int i = 0; i < position; i++)
            {
                previous = current;
                current = current->next;
            }
            newNode->next = current;
            previous->next = newNode;
            printf("Insert char '%c' at %d position!\n", data, position);
        }
    }
}

/// Delete first node of Linked List
void deleteFirst(struct Head *start)
{
    if (!start->first)
    {
        // case start-first equal NULL
        printf("There's no node to delete");
    }
    else
    {
        struct Node *current = start->first;
        start->first = current->next;
        current->next = NULL;
        free(current);
        printf("First node deleted!\n");
    }
}

/// Delete last node of Linked List
void deleteLast(struct Head *start)
{
    if (!start->first)
    {
        // case start-first equal NULL
        printf("There's no node to delete");
    }
    else
    {
        struct Node *current = start->first;
        if (!current->next)
        {
            // case current->next equal NULL
            start->first = NULL;
        }
        else
        {
            struct Node *previous = NULL;
            // when current->next equal NULL, current is the last node
            while (current->next)
            {
                previous = current;
                current = current->next;
            }
            previous->next = NULL;
        }
        free(current);
        printf("Last node deleted!\n");
    }
}

/// Delete node at any position of Linked List
void deleteAt(struct Head *start, unsigned position)
{
    if (!start->first)
    {
        // case start->first equal NULL
        printf("There's no node to delete");
    }
    else if (position == 0)
    {
        // case position is the first position
        deleteFirst(start);
    }
    else if (position >= sizeofLL(start) - 1)
    {
        // case position is greater than or equal last position
        deleteLast(start);
    }
    else
    {
        // case position is between first and last
        struct Node *current = start->first,
                    *previous = NULL;
        for (int i = 0; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current->next = NULL;
        free(current);
        printf("Delete node at %d position!\n", position);
    }
}

/// TODO: If @param data exists at Linked List, @return the 0 based position, else @return -1
int searchData(struct Head *start, char data)
{
    int position = 0;
    struct Node *current = start->first;
    while (current->data != data)
    {
        if (current->next == NULL)
        {
            printf("Data '%c' doesn't exists\n", data);
            return -1;
        }
        current = current->next;
        position++;
    }
    printf("Data '%C' at position %d;\n", data, position);
    return position;
}

/// TODO: @return the data of this node
char searchPosition(struct Head *start, unsigned position)
{
    return 'c';
}

/// Deallocate memory allocated for Linked List
void freeLL(struct Head *start)
{
    unsigned size = sizeofLL(start);
    while (size)
    {
        deleteLast(start);
        size = sizeofLL(start);
    }
    printf("Free!!\n");
}

int main(void)
{
    // Create empty Linked List pointing to NULL
    printf("\n\tCreated Linked List!\n");
    struct Head linkedList = {NULL};
    showLL(&linkedList);

    printf("\n\tInserts\n");
    insertFirst(&linkedList, 'a');
    insertLast(&linkedList, '0');
    insertAt(&linkedList, 'e', 2);
    showLL(&linkedList);

    printf("\n\tSearches\n");
    searchData(&linkedList, 'b');

    printf("\n\tDeletes\n");
    deleteFirst(&linkedList);
    deleteLast(&linkedList);
    showLL(&linkedList);

    printf("\n\tFree\n");
    freeLL(&linkedList);
    showLL(&linkedList);

    return 0;
}
