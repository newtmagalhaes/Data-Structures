// Implementation of Single Circular Linked List in C

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/circular_linked_list_program_in_c.htm

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

/// Return last node of Linked List
struct Node *lastNodeof(struct Head *start)
{
    struct Node *current = start->first;
    if (!start->first)
    {
        // case start->first equal NULL
        // printf("This linked list is empty");
        return NULL;
    }
    else
    {
        while (current->next != start->first)
        {
            current = current->next;
        }
        return current;
    }
}

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
        // break when current->next equal start->first
        do
        {
            current = current->next;
            size++;
        } while (current != start->first);
        return size;
    }
}

/// Show Linked List at the console
void showLL(struct Head *start)
{
    struct Node *current = start->first;
    printf("start -> [ ");
    if (start->first)
    {
        do
        {
            printf("'%c' ", current->data);
            current = current->next;
        } while (current != start->first);
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
            newNode->next = newNode;
        }
        else
        {
            struct Node *oldFirst = start->first,
                        *lastNode = lastNodeof(start);
            lastNode->next = newNode;
            newNode->next = oldFirst;
        }
        start->first = newNode;
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
            newNode->next = newNode;
            start->first = newNode;
        }
        else
        {
            struct Node *current = lastNodeof(start);
            newNode->next = start->first;
            current->next = newNode;
            printf("Insert char '%c' at Last position!\n", data);
        }
    }
}

/// Create a newNode and insert at any position of Linked List
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
        if (current->next == current)
        {
            // case there's only one node
            start->first = NULL;
            current->next = NULL;
        }
        else
        {
            struct Node *newFirst = current->next,
                        *lastNode = lastNodeof(start);
            lastNode->next = newFirst;
            start->first = newFirst;
            current->next = NULL;
        }
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
        if (current->next == current)
        {
            // case there's one node
            start->first = NULL;
            current->next = NULL;
        }
        else
        {
            struct Node *previous = NULL;
            // when current->next equal NULL, current is the last node
            while (current->next != start->first)
            {
                previous = current;
                current = current->next;
            }
            previous->next = start->first;
            current->next = NULL;
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

/// Return the 0-based position of the first occurrence of @param data, otherwise, return -1
int searchData(struct Head *start, char data)
{
    struct Node *current = start->first;
    int position = 0,
        size = sizeofLL(start);
    for (position = 0; position < size; position++)
    {
        if (current->data == data)
        {
            printf("Data '%c' at position %d;\n", data, position);
            return position;
        }
        current = current->next;
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

/// Reverse the Linked List
void reverseLL(struct Head *start)
{
    struct Node *previous = lastNodeof(start),
                *current = start->first,
                *next = NULL;
    do
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    } while (current != start->first);
    start->first = previous;
}

int main(int argc, char const *argv[])
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
    searchData(&linkedList, '0');
    searchPosition(&linkedList, 42);
    searchPosition(&linkedList, 2);

    printf("\n\tReverse\n");
    showLL(&linkedList);
    reverseLL(&linkedList);
    showLL(&linkedList);

    printf("\n\tDeletes\n");
    deleteFirst(&linkedList);
    deleteLast(&linkedList);
    showLL(&linkedList);

    printf("\n\tFree\n");
    freeLL(&linkedList);
    showLL(&linkedList);

    return 0;
}
