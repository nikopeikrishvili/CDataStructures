#include "binary_tree.h"

#include <stdlib.h>


Node *createNode(const int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
