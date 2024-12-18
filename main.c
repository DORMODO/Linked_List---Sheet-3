#include <stdio.h>
#include "list.h"

int main()
{
  LinkedList list;
  initializeList(&list);

  printf("\n=== Linked List Operations ===\n\n");

  printf("1. Inserting elements:\n");
  insert(&list, 10, 0);
  insert(&list, 20, 1);
  insert(&list, 20, 2);
  insert(&list, 30, 3);
  insert(&list, 40, 4);
  printf("List after insertions: ");
  displayList(&list);
  printf("\n\n");

  // Test count
  printf("2. Counting occurrences:\n");
  printf("Number of 20s in the list: %d\n\n", count(&list, 20));

  // Test getNth
  printf("3. Getting element at index:\n");
  printf("Element at index 2: %d\n\n", getNth(&list, 2));

  // Test pop
  printf("4. Pop operation:\n");
  printf("Popped value: %d\n", pop(&list));
  printf("List after pop: ");
  displayList(&list);
  printf("\n\n");

  // Test isPresent with move-to-front
  printf("5. Testing isPresent (with move-to-front):\n");
  printf("Is 30 present? %s\n", isPresent(&list, 30) ? "Yes" : "No");
  printf("List after checking 30: ");
  displayList(&list);
  printf("\n\n");

  // Test retrieve
  printf("6. Retrieve operation:\n");
  printf("Retrieved value from position 1: %d\n", retrieve(&list, 1));
  printf("List after retrieve: ");
  displayList(&list);
  printf("\n\n");

  // Test duplicate removal
  printf("7. Testing duplicate removal:\n");
  insert(&list, 20, 0);
  insert(&list, 20, 0);
  printf("List before removing duplicates: ");
  displayList(&list);
  printf("\n");

  removeDuplicates(&list);
  printf("List after removing duplicates: ");
  displayList(&list);
  printf("\n\n");

  // Test empty check
  printf("8. Testing empty check:\n");
  printf("Is list empty? %s\n\n", isListEmpty(&list) ? "Yes" : "No");

  // Clean up by retrieving all remaining elements
  printf("9. Cleaning up the list:\n");
  while (!isListEmpty(&list))
  {
    retrieve(&list, 0);
  }
  printf("Final list state: ");
  displayList(&list);
  printf("\n");
}