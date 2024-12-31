#ifndef C_DS_LINKED_LIST_H
#define C_DS_LINKED_LIST_H

typedef struct Node {
  struct Node *next;
  int data;
} node_t;

typedef struct LinkedList {
  node_t *head;
} linkedlist_t;

linkedlist_t *CreateLinkedList();

void PrintLinkedList(linkedlist_t *linkedList);
void FreeLinkedList(linkedlist_t *linkedList);

// Add data to the end to linked list
void AppendToLinkedList(linkedlist_t *linkedList, int data);

#endif
