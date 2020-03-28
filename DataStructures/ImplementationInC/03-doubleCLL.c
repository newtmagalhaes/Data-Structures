// Implementation of Double Circular Linked List in C

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/circular_linked_list_program_in_c.htm

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

/// Return the number of nodes in a Linked List
unsigned sizeofLL(struct Head *start)
{
    unsigned size = 0;
    struct Node *current = start->first;
    do
    {
        size++;
        current = current->next;
    } while (current != start->first);
    return size;
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

/// Show Reverse Linked List at the console
void showReverseLL(struct Head *start)
{
    struct Node *current = start->first->prev;
    printf("start -> [ ");
    if (start->first)
    {
        do
        {
            printf("'%c' ", current->data);
            current = current->prev;
        } while (current->next != start->first);
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
        printf("Failed malloc!\n");
    }
    else
    {
        newNode->data = data;
        if (!start->first)
        {
            // case start->first equal NULL
            newNode->next = newNode->prev = newNode;
        }
        else
        {
            struct Node *oldFirst = start->first,
                        *lastNode = oldFirst->prev;
            newNode->next = oldFirst;
            newNode->prev = lastNode;
            oldFirst->prev = lastNode->next = newNode;
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
        printf("Failed Malloc!\n");
    }
    else
    {
        newNode->data = data;
        if (!start->first)
        {
            // case start->first equal NULL
            newNode->prev = newNode->next = newNode;
            start->first = newNode;
        }
        else
        {
            struct Node *FirstNode = start->first,
                        *oldLast = FirstNode->prev;
            FirstNode->prev = oldLast->next = newNode;
            newNode->next = FirstNode;
            newNode->prev = oldLast;
        }
        printf("Insert '%c' at last position!\n", data);
    }
}

/// Create a newNode and insert at any position of Linked List
void insertAt(struct Head *start, char data, unsigned position)
{
    if (position == 0)
    {
        insertFirst(start, data);
    }
    else if (position >= sizeofLL(start) - 1)
    {
        insertLast(start, data);
    }
    else
    {
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
                        *previous = current->prev;
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
            previous = current->prev;
            newNode->prev = previous;
            newNode->next = current;
            previous->next = newNode;
            current->prev = newNode;
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
        printf("Empty linked list!\n");
    }
    else
    {
        struct Node *current = start->first;
        if (current->next == current)
        {
            // case there's only one node
            start->first = NULL;
        }
        else
        {
            struct Node *newFirst = current->next,
                        *oldLast = current->prev;
            start->first = newFirst;
            oldLast->next = newFirst;
            newFirst->prev = oldLast;
        }
        current->next = NULL;
        current->prev = NULL;
        free(current);
        printf("First node deleted!\n");
    }
}

/// Delete last node of Linked List
void deleteLast(struct Head *start)
{
    if (!start->first)
    {
        // case start->first equal NULL
        printf("Empty linked list!\n");
    }
    else
    {
        struct Node *current = start->first;
        if (current->next == current)
        {
            // case there's only one node
            start->first = NULL;
        }
        else
        {
            current = current->prev; // current becomes last node
            struct Node *oldFirst = current->next,
                        *newLast = current->prev;
            newLast->next = oldFirst;
            oldFirst->prev = newLast;
        }
        current->next = NULL;
        current->prev = NULL;
        free(current);
        printf("First node deleted!\n");
    }
}

/// Delete node at any position of Linked List
void deleteAt(struct Head *start, unsigned position)
{
    if (!start->first)
    {
        // case start->first equal NULL
        printf("Empty linked list!\n");
    }
    else
    {
        if (position == 0)
        {
            deleteFirst(start);
        }
        else if (position >= sizeofLL(start) - 1)
        {
            deleteLast(start);
        }
        else
        {
            struct Node *current = start->first;
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
            struct Node *previous = current->prev,
                        *nextNode = current->next;
            previous->next = nextNode;
            nextNode->prev = previous;
            current->prev = current->next = NULL;
            free(current);
            printf("deleted node at position %d", position);
        }
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
    while (start->first)
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
    showReverseLL(&linkedList);

    printf("\n\tDeletes\n");
    deleteFirst(&linkedList);
    deleteLast(&linkedList);
    showLL(&linkedList);

    printf("\n\tFree\n");
    freeLL(&linkedList);
    showLL(&linkedList);

    return 0;
}
