#ifndef C_DS_LINKED_LIST_H
#define C_DS_LINKED_LIST_H
#include <stdlib.h>
typedef struct Node {
  struct Node *next;
  int data;
} node_t;

typedef struct LinkedList {
  node_t *head;
  node_t *firstNode;
  node_t *lastNode;
} linkedlist_t;
// Initialize linked List
linkedlist_t *CreateLinkedList();
// Helper function to print linked List
void PrintLinkedList(linkedlist_t *linkedList);
// Free heap from linked list data
void FreeLinkedList(linkedlist_t *linkedList);
// Add data to the end to linked list
void AppendToLinkedList(linkedlist_t *linkedList, int data);
// Add node after specific node
void AddAfter(linkedlist_t *linkedList, node_t *node, int data);
// Void get node at specific index
node_t *GetNodeAtIndex(linkedlist_t *linkedList, size_t index);
#endif
