#ifndef DOUBLE_SORTED_LINKED_LIST
#define DOUBLE_SORTED_LINKED_LIST

#include <stdbool.h>

typedef struct Node
{
  struct Node *prev;
  int key;
  int value;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
} DoubleLinkedList;

void initList(DoubleLinkedList *list);
bool isListEmpty(const DoubleLinkedList *list);
struct Node *createNode(int newValue, int key);
void insert(DoubleLinkedList *list, int newValue, int key);
int retrieve(DoubleLinkedList *list, int key);
void displayList(const DoubleLinkedList *list);
void destroyList(DoubleLinkedList *list);

#endif // DOUBLE_SORTED_LINKED_LIST