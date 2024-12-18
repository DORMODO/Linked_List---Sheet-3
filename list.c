#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

void initializeList(LinkedList *list)
{
  list->head = NULL;
}

bool isListEmpty(const LinkedList *list)
{
  return list->head == NULL;
}

struct Node *createNode(int newValue)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->value = newValue;
  newNode->next = NULL;
  return newNode;
}

void insert(LinkedList *list, int newValue, int pos)
{
  Node *newNode = createNode(newValue);

  if (pos == 0)
  {
    newNode->next = list->head;
    list->head = newNode;
  }
  else
  {
    Node *current = list->head;
    int currentPos = 0;

    while (current != NULL && currentPos < pos - 1)
    {
      current = current->next;
      currentPos++;
    }
    if (current == NULL)
    {
      current = list->head;
      while (current->next != NULL)
      {
        current = current->next;
      }
      current->next = newNode;
      newNode->next = NULL;
    }
    else
    {
      newNode->next = current->next;
      current->next = newNode;
    }
  }
}

int retrieve(LinkedList *list, int pos)
{
  if (isListEmpty(list))
  {
    return -1;
  }

  Node *current = list->head;
  Node *prev = NULL;
  int currentPos = 0;
  int retrievedValue;

  if (pos == 0)
  {
    list->head = current->next;
    retrievedValue = current->value;
    free(current);
    return retrievedValue;
  }
  while (current != NULL && currentPos < pos)
  {
    prev = current;
    current = current->next;
    currentPos++;
  }
  if (current == NULL)
  {
    return -1;
  }
  else
  {
    prev->next = current->next;
    retrievedValue = current->value;
    free(current);
    return retrievedValue;
  }
}

void displayList(const LinkedList *list)
{
  if (isListEmpty(list))
  {
    printf("List is Empty!");
  }

  Node *current = list->head;
  while (current != NULL)
  {
    printf("[%d] -> ", current->value);
    current = current->next;
  }
  if (!isListEmpty(list))
  {
    printf("NULL");
  }
}

int count(LinkedList *list, int searchFor)
{
  Node *current = list->head;
  int count = 0;

  while (current != NULL)
  {
    if (current->value == searchFor)
    {
      count++;
    }
    current = current->next;
  }
  return count;
}

int getNth(LinkedList *list, int index)
{
  Node *current = list->head;
  int count = 0;

  while (current != NULL)
  {
    if (count == index)
    {
      return current->value;
    }
    current = current->next;
    count++;
  }
  return -1;
}

int pop(LinkedList *list)
{
  if (isListEmpty(list))
  {
    return -1;
  }

  Node *temp = list->head;
  int poppedValue = temp->value;

  list->head = temp->next; // Update head to the next node
  free(temp);              // Free the removed head node
  return poppedValue;
}

int isPresent(LinkedList *list, int searchValue)
{
  if (isListEmpty(list))
    return -1;

  Node *current = list->head;
  Node *prev = NULL;

  while (current != NULL)
  {
    if (current->value == searchValue)
    {
      // Check if the node is already at the head
      if (prev == NULL)
        return 1; // No need to move if already at head

      prev->next = current->next;
      current->next = list->head;
      list->head = current;

      return 1;
    }
    prev = current;
    current = current->next;
  }
  return 0;
}

void removeDuplicates(LinkedList *list)
{
  Node *current = list->head;

  while (current != NULL && current->next != NULL)
  {
    if (current->value == current->next->value)
    {
      // Duplicate found; remove the next node
      Node *duplicate = current->next;
      current->next = duplicate->next;
      free(duplicate); // Free memory of duplicate node
    }
    else
      current = current->next;
  }
}

void reverse(LinkedList *list)
{
  Node *prev = NULL;
  Node *current = list->head;
  Node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  list->head = prev;
}