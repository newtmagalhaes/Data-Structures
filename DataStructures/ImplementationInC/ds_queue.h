#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next, *prev;
};

struct queue
{
  struct Node *first;
};

/// Return 0 if queue is empty, otherwise, return 1
int isEmpty(struct queue *start)
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

/// Return the number of nodes in a queue
unsigned sizeofQ(struct queue *start)
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

/// Show queue at the console
void showQ(struct queue *start)
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

/// Create a newNode and inserts at first position of queue
void _insertFirst(struct queue *start, char data)
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
    printf("Enqueue '%c' at first position!\n", data);
  }
}

/// Create a newNode and insert at last position of queue
void enqueue(struct queue *start, char data)
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
      _insertFirst(start, data);
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
      printf("Enqueue '%c' at last position!\n", data);
    }
  }
}

/// Delete first node of queue
void dequeue(struct queue *start)
{
  if (!start->first)
  {
    // case start->first equal NULL
    printf("Double queue is empty!\n");
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
    printf("First node dequeued!\n");
  }
}

/// Return the 0-based position of the first occurrence of @param data, otherwise, return -1
int searchData(struct queue *start, char data)
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
char searchPosition(struct queue *start, unsigned position)
{
  if (position >= sizeofQ(start))
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

/// Deallocate memory allocated for queue
void freeQ(struct queue *start)
{
  while (sizeofQ(start))
  {
    dequeue(start);
  }
  printf("Free!!\n");
}
