#include "../../LinkedList/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  linkedlist_t *linkedList = SLL_create();

  SLL_push(linkedList, 1);
  SLL_push(linkedList, 4);
  SLL_push(linkedList, 5);
  SLL_push(linkedList, 8);
  SLL_push(linkedList, 10);
  SLL_push(linkedList, 123);
  node_t *index3Node = SLL_getNodeAtIndex(linkedList, 3);
  printf("Value of node at index 3 is %d\n", index3Node->data);

  SLL_print(linkedList);
  SLL_addAfter(linkedList, index3Node, 23);
  SLL_print(linkedList);
  SLL_removeAtPosition(linkedList, 4);
  SLL_print(linkedList);
  SLL_unshift(linkedList);
  SLL_print(linkedList);
  node_t *found = SLL_search(linkedList, 8);

  printf("Founded node is at address %p, next value is : %d\n", found, found->next->data);
  SLL_free(linkedList);
}
