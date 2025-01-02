#include "../../LinkedList/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  linkedlist_t *linkedList = CreateLinkedList();

  AppendToLinkedList(linkedList, 1);
  AppendToLinkedList(linkedList, 4);
  AppendToLinkedList(linkedList, 5);
  AppendToLinkedList(linkedList, 8);
  AppendToLinkedList(linkedList, 10);
  AppendToLinkedList(linkedList, 123);
  node_t *index3Node = GetNodeAtIndex(linkedList, 3);
  printf("Value of node at index 3 is %d\n", index3Node->data);

  PrintLinkedList(linkedList);
  AddAfter(linkedList, index3Node, 23);
  PrintLinkedList(linkedList);
  FreeLinkedList(linkedList);
}
