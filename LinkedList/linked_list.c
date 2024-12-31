#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
// Creates empty linked list
linkedlist_t *CreateLinkedList() {
  linkedlist_t *list = (linkedlist_t *)malloc(sizeof(linkedlist_t));
  list->head = NULL;
  return list;
};
// Private get tha last node from linked list
static node_t *getLastNodeAddress(linkedlist_t *linkedList) {
  if (NULL == linkedList->head) {
    return NULL;
  }
  node_t *node = linkedList->head;

  while (NULL != node->next) {
    node = node->next;
  }
  return node;
}
// Private create node with data and return pointer
static node_t *createNode(int data) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->data = data;
  return node;
}
// Prind linked list
void PrintLinkedList(linkedlist_t *linkedList) {
  node_t *currentNode = linkedList->head;
  while (NULL != currentNode) {
    printf("Node value %d\n", currentNode->data);
    currentNode = currentNode->next;
  }
};
// Free all memory allocations in linked list
void FreeLinkedList(linkedlist_t *linkedList) {
  node_t *currentNode = linkedList->head;
  if (NULL == currentNode) {
    free(linkedList);
    return;
  }
  node_t *nextNode = linkedList->head->next;
  while (NULL != currentNode) {
    free(currentNode);
    currentNode = nextNode;
    if (NULL != currentNode) {
      nextNode = currentNode->next;
    }
  }
  free(linkedList);
};

// Add data to the end to linked list
void AppendToLinkedList(linkedlist_t *linkedList, int data) {
  if (NULL == linkedList->head) {
    node_t *node = createNode(data);
    linkedList->head = node;
    return;
  }
  node_t *lastNode = getLastNodeAddress(linkedList);
  lastNode->next = createNode(data);
};
