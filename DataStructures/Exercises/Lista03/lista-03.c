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
        while (current)
        {
            current = current->next;
            size++;
        }
        return size;
    }
}

/// Show Linked List at the console
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
    struct Head linkedList = {NULL};
    showLL(&linkedList);

    // Q 01 - Insira um elemento contendo a letra 'A' no final da lista
    printf("\n\tQ 01\n");
    insertLast(&linkedList, 'A');
    showLL(&linkedList);

    // Q 02 - Insira um elemento contendo a letra 'B' no inicio da lista
    printf("\n\tQ 02\n");
    insertFirst(&linkedList, 'B');
    showLL(&linkedList);

    // Q 03 - Insira um elemento contendo a letra 'C' no final da lista
    printf("\n\tQ 03\n");
    insertLast(&linkedList, 'C');
    showLL(&linkedList);

    // Q 04 - Insira um elemento contendo a letra 'D' no final da lista
    printf("\n\tQ 04\n");
    insertLast(&linkedList, 'D');
    showLL(&linkedList);

    // Q 05 - Insira um elemento contendo a letra 'E' entre os elementos de conteúdo 'A' e 'C'
    printf("\n\tQ 05\n");
    int position = searchData(&linkedList, 'C');
    insertAt(&linkedList, 'E', position);
    showLL(&linkedList);

    // Q 06 - Insira um elemento contendo a letra 'F' no final da lista
    printf("\n\tQ 06\n");
    insertLast(&linkedList, 'F');
    showLL(&linkedList);

    // Q 07 - Insira um elemento contendo a letra 'G' no inicio da lista
    printf("\n\tQ 07\n");
    insertFirst(&linkedList, 'G');
    showLL(&linkedList);

    // Q 08 - Exclua o último elemento
    printf("\n\tQ 08\n");
    deleteLast(&linkedList);
    showLL(&linkedList);

    // Q 09 - Exclua o primeiro elemento
    printf("\n\tQ 09\n");
    deleteFirst(&linkedList);
    showLL(&linkedList);

    // Q 10 - Insira um elemento contendo a letra 'H' entre os elementos de conteúdo 'A' e 'E'
    printf("\n\tQ 10\n");
    position = searchData(&linkedList, 'E');
    insertAt(&linkedList, 'H', position);
    showLL(&linkedList);

    // Q 11 - Exclua o elemento de conteúdo 'A'
    printf("\n\tQ 11\n");
    position = searchData(&linkedList, 'A');
    deleteAt(&linkedList, position);
    showLL(&linkedList);

    // Q 12 - Insira um elemento contendo a letra 'I' entre os elementos de conteúdo 'E' e 'D'
    printf("\n\tQ 12\n");
    position = searchData(&linkedList, 'D');
    insertAt(&linkedList, 'I', position);
    showLL(&linkedList);

    // Q 13 - Insira um elemento contendo a letra 'J' no final da lista
    printf("\n\tQ 13\n");
    insertLast(&linkedList, 'J');
    showLL(&linkedList);

    // Q 14 - Insira um elemento contendo a letra 'K' entre os elementos de conteúdo 'B' e 'H'
    printf("\n\tQ 14\n");
    position = searchData(&linkedList, 'H');
    insertAt(&linkedList, 'K', position);
    showLL(&linkedList);

    // Q 15 - Exclua o elemento de conteúdo 'D', 'K' e 'I'
    printf("\n\tQ 15\n");
    position = searchData(&linkedList, 'D');
    deleteAt(&linkedList, position);
    position = searchData(&linkedList, 'K');
    deleteAt(&linkedList, position);
    position = searchData(&linkedList, 'I');
    deleteAt(&linkedList, position);
    showLL(&linkedList);

    // Q 16 - Exclua o elemento de conteúdo 'B'
    printf("\n\tQ 16\n");
    position = searchData(&linkedList, 'B');
    deleteAt(&linkedList, position);
    showLL(&linkedList);

    // Q 17 - Insira um elemento contendo a letra 'L' no final da lista
    printf("\n\tQ 17\n");
    insertLast(&linkedList, 'L');
    showLL(&linkedList);

    printf("\n");
    freeLL(&linkedList);

    return 0;
}