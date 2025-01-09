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
  size_t size;
} linkedlist_t;
// Initialize linked List
linkedlist_t *SLL_create();
// Helper function to print linked List
void SLL_print(linkedlist_t *linkedList);
// Free heap from linked list data
void SLL_free(linkedlist_t *linkedList);

// Add node after specific node
void SLL_addAfter(linkedlist_t *linkedList, node_t *node, int data);
// Void get node at specific index
node_t *SLL_getNodeAtIndex(linkedlist_t *linkedList, size_t index);
// Add data to the end to linked list
void SLL_push(linkedlist_t *linkedList, int data);
// remove node from the end of linked list
// TODO
void SLL_unshift(linkedlist_t *linkedList);

// Remove node at specific position
// TODO
void SLL_removeAtPosition(linkedlist_t *linkedList, size_t index);
#endif
