// Implementation of fixed size Stack in C with Linked List

/// FONT: https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

#define limit 5

struct element
{
    char data;
    struct element *below;
};

struct stack
{
    int maxSize;
    struct element *top;
};

/// Return the number of elements in a stack
unsigned sizeofS(struct stack *head)
{
    unsigned size = 0;
    struct element *current = head->top;
    while (current)
    {
        current = current->below;
        size++;
    }
    return size;
}

/// Checks if stack is full
int isFullS(struct stack *head)
{
    if (head->maxSize <= sizeofS(head))
    {
        printf("* Stack is full *\n");
        return 1;
    }
    else
    {
        printf("* Stack isn't full *\n");
        return 0;
    }
}

/// Checks if stack is empty
int isEmptyS(struct stack *head)
{
    if (head->top == NULL)
    {
        printf("* Stack is empty! *\n");
        return 1;
    }
    else
    {
        printf("* Stack isn't empty*\n");
        return 0;
    }
}

/// Show stack at the console
void showS(struct stack *head)
{
    printf("Head");
    struct element *current = head->top;
    while (current)
    {
        printf(" ->['%c']", current->data);
        current = current->below;
    }
    printf(" ->NULL;\n");
}

/// Return data value of top element, otherwise return '\0'
char peekS(struct stack *head)
{
    if (isEmptyS(head))
    {
        return '\0';
    }
    else
    {
        printf("* Data at top element is '%c'*\n", head->top->data);
        return head->top->data;
    }
}

/// Push @param data at the stack
void pushS(struct stack *head, char data)
{
    if (isFullS(head))
    {
        printf("* Stack Overflow! *\n");
    }
    else
    {
        struct element *newElement = (struct element *)malloc(sizeof(struct element));
        if (!newElement)
        {
            // case newElement equal NULL
            printf("* Failed Malloc! *\n");
        }
        else
        {
            newElement->data = data;
            newElement->below = head->top;
            head->top = newElement;
            printf("* Push '%c' at the Stack! *\n", data);
        }
    }
}

/// Pop top element of the stack
char popS(struct stack *head)
{
    if (isEmptyS(head))
    {
        printf("* Stack Underflow! *\n");
        return '\0';
    }
    else
    {
        struct element *current = head->top;
        char data = current->data;
        head->top = current->below;
        current->below = NULL;
        free(current);
        printf("* Element ['%c'] poped! *\n", data);
        return data;
    }
}

/// dealocates all elements of the stack
void freeS(struct stack *head)
{
    // while head->top isn't NULL
    while (head->top)
    {
        popS(head);
    }
    printf("* Stack is free! *\n");
}

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