#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "doubleLinked.h"

/**
 * The main function is the entry point of the program. It creates a DoubleLinkedList,
 * inserts elements into it, retrieves values from the list, and then destroys the list.
 * 
 * Parameters: None
 * 
 * Returns: An integer indicating the program's exit status.
 */
int main()
{
  DoubleLinkedList myList;
  initList(&myList);
  
  insert(&myList, 10, 1);
  insert(&myList, 20, 2);
  insert(&myList, 15, 3);
  insert(&myList, 5, 0);
  printf("List after insertions:\n");
  displayList(&myList);

  int value = retrieve(&myList, 2);
  if (value != -1)
  {
    printf("Retrieved value for key 2: %d\n", value);
  }

  value = retrieve(&myList, 10);

  destroyList(&myList);
  printf("\nList after destroying:\n");
  displayList(&myList);
}