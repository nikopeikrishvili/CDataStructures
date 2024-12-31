#include "../../LinkedList/linked_list.h"
#include <stdlib.h>

int main() {

  linkedlist_t *linkedList = CreateLinkedList();

  AppendToLinkedList(linkedList, 1);
  AppendToLinkedList(linkedList, 4);
  AppendToLinkedList(linkedList, 5);
  AppendToLinkedList(linkedList, 8);
  AppendToLinkedList(linkedList, 10);
  AppendToLinkedList(linkedList, 123);

  PrintLinkedList(linkedList);
  FreeLinkedList(linkedList);
}
