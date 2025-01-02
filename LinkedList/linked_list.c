#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
// Creates empty linked list
linkedlist_t *CreateLinkedList() {
  linkedlist_t *list = (linkedlist_t *)malloc(sizeof(linkedlist_t));
  list->head = NULL;
  list->firstNode = NULL;
  list->lastNode = NULL;
  return list;
};
// Private get tha last node from linked list
static node_t *getLastNodeAddress(linkedlist_t *linkedList) {
  if (NULL == linkedList->lastNode) {
    return NULL;
  }
  node_t *node = linkedList->lastNode;
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
    linkedList->firstNode = node;
    linkedList->lastNode = node;
    return;
  }
  node_t *lastNode = getLastNodeAddress(linkedList);
  lastNode->next = createNode(data);
  linkedList->lastNode = lastNode->next;
};

void AddAfter(linkedlist_t *linkedList, node_t *node, int data) {
  if (NULL == linkedList->head) {
    return;
  }
  node_t *tempNode = linkedList->head;

  while (NULL != tempNode) {
    if (tempNode == node) {
      node_t *newNode = createNode(data);
      newNode->next = tempNode->next;
      tempNode->next = newNode;
      // if node is last node update linkedlist
      if (NULL == newNode->next) {
        linkedList->lastNode = newNode;
      }
      return;
    }
    tempNode = tempNode->next;
  }
}
node_t *GetNodeAtIndex(linkedlist_t *linkedList, size_t index) {
  if (NULL == linkedList || NULL == linkedList->head) {
    return NULL;
  }
  size_t currentIndex = 0;
  node_t *tmpNode = linkedList->head;
  for (; currentIndex < index; currentIndex++) {
    tmpNode = tmpNode->next;
  }
  if (currentIndex != index)
    return NULL;
  return tmpNode;
}
