#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
};

struct sLinkedList
{
  struct Node *first;
};

/// Return the number of nodes in a Linked List
unsigned sizeofLL(struct sLinkedList *start)
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
void showLL(struct sLinkedList *start)
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
void insertFirst(struct sLinkedList *start, char data)
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
void insertLast(struct sLinkedList *start, char data)
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
void insertAt(struct sLinkedList *start, char data, unsigned position)
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
void deleteFirst(struct sLinkedList *start)
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
void deleteLast(struct sLinkedList *start)
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
void deleteAt(struct sLinkedList *start, unsigned position)
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
int searchData(struct sLinkedList *start, char data)
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
char searchPosition(struct sLinkedList *start, unsigned position)
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
void freeLL(struct sLinkedList *start)
{
  unsigned size = sizeofLL(start);
  while (size)
  {
    deleteLast(start);
    size = sizeofLL(start);
  }
  printf("Free!!\n");
}

/// Reverse the Linked List
void reverseLL(struct sLinkedList *start)
{
  struct Node *previous = NULL,
              *current = start->first,
              *next = NULL;
  while (current)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  start->first = previous;
}
