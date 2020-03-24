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

/// Show Linked List
void showLL(struct Head *start)
{
    struct Node *current = start->first;
    printf("\nstart -> [ ");
    while (current)
    {
        printf("'%c' ", current->data);
        current = current->next;
    }
    printf("] -> NULL\n");
}

/// Deallocate memory allocated for Linked List
void freeLL(struct Head *start)
{
    struct Node *current = start->first;
    while (current)
    {
        free(current);
        current = current->next;
    }
    printf("\nFree!!\n");
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
    }
}

/// Delete first node of Linked List
void deleteFirst(struct Head *start)
{
    struct Node *current = start->first;
    start->first = current->next;
    current->next = NULL;
    free(current);
}

/// Delete last node of Linked List
void deleteLast(struct Head *start)
{
    struct Node *current = start->first,
                *previous = NULL;
    while (current->next)
    {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
}

int main(int argc, char const *argv[])
{
    struct Head linkedList = {NULL};

    showLL(&linkedList);

    insertFirst(&linkedList, 'a');
    insertFirst(&linkedList, 'b');
    insertFirst(&linkedList, 'c');
    showLL(&linkedList);

    deleteFirst(&linkedList);
    showLL(&linkedList);

    deleteLast(&linkedList);
    showLL(&linkedList);

    freeLL(&linkedList);

    return 0;
}
