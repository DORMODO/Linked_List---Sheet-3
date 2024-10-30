#include <stdbool.h>
#ifndef LIST
#define LIST

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
} LinkedList;
void initializeList(LinkedList *list);
bool isListEmpty(const LinkedList *list);
struct Node *createNode(int newValue);
void insert(LinkedList *list, int newValue, int pos);
int retrieve(LinkedList *list, int pos);
void displayList(const LinkedList *list);

int count(LinkedList *list, int searchFor);
int getNth(LinkedList *list, int index);
int pop(LinkedList *list);
int isPresent(LinkedList *list, int searchValue);
void removeDuplicates(LinkedList *list);
void reverse(LinkedList *list);

#endif // LIST
