#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "doubleLinked.h"

void initList(DoubleLinkedList *list)
{
  list->head = NULL;
}

bool isListEmpty(const DoubleLinkedList *list)
{
  return list->head == NULL;
}

struct Node *createNode(int newValue, int key)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = newValue;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insert(DoubleLinkedList *list, int newValue, int key)
{
  if (list == NULL)
  {
    printf("Error: List is not initialized.\n");
    return;
  }

  Node *newNode = createNode(newValue, key);

  if (list->head == NULL || list->head->key >= key)
  {
    newNode->next = list->head;
    if (list->head != NULL)
    {
      list->head->prev = newNode;
    }
    list->head = newNode;
    return;
  }
  Node *current = list->head;

  while (current->next != NULL && current->next->key < key)
  {
    current = current->next;
  }
  newNode->next = current->next;
  newNode->prev = current;

  if (current->next != NULL)
  {

    current->next->prev = newNode;
  }
  current->next = newNode;
}

int retrieve(DoubleLinkedList *list, int key)
{
  if (list == NULL)
  {
    printf("Error: List is not initialized.\n");
    return -1;
  }

  Node *current = list->head;

  while (current != NULL)
  {
    if (current->key == key)
    {
      return current->value;
    }
    current = current->next;
  }
  return -1;
}

void displayList(const DoubleLinkedList *list)
{
  if (list == NULL)
  {
    printf("Error: List is not initialized.\n");
    return;
  }

  Node *current = list->head;

  if (current == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  while (current != NULL)
  {
    printf("Key: %d, Value: %d\n", current->key, current->value);
    current = current->next;
  }
}

void destroyList(DoubleLinkedList *list)
{
  if (list == NULL)
  {
    printf("Error: List is not initialized.\n");
    return;
  }

  Node *current = list->head;
  Node *nextNode;

  while (current != NULL)
  {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  list->head = NULL;
}