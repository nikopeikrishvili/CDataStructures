#include "binary_tree.h"

#include <stdlib.h>


Node *createNode(const int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node **root, const int data) {
    Node *newNode = createNode(data);

    if (NULL == *root) {
        *root = newNode;
        return;
    }
    int front = -1, rear = -1;
    Node *queue[100];
    queue[++rear] = *root;
    while (front != rear) {
        Node *temp = queue[++front];

        if (NULL == temp->left) {
            temp->left = newNode;
            return;
        } else {
            queue[++rear] = temp->left;
        }
        if (NULL == temp->right) {
            temp->right = newNode;
            return;
        } else {
            queue[++rear] = temp->right;
        }
    }
}

Node *getDeepestRightMostNode(Node *root) {
    Node *temp;
    Node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
    while (front != rear) {
        temp = queue[++front];
        if (NULL != temp->left) {
            queue[++rear] = temp->left;
        }

        if (NULL != temp->right) {
            queue[++rear] = temp->right;
        }
    }
    return temp;
}

void deleteDeepestRightmostNode(Node *root, Node *dNode) {
    Node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        Node *temp = queue[++front];

        if (temp == dNode) {
            temp = NULL;
            free(dNode);
            return;
        }

        if (temp->right != NULL) {
            if (temp->right == dNode) {
                temp->right = NULL;
                free(dNode);
                return;
            } else {
                queue[++rear] = temp->right;
            }
        }

        if (temp->left != NULL) {
            if (temp->left == dNode) {
                temp->left = NULL;
                free(dNode);
                return;
            } else {
                queue[++rear] = temp->left;
            }
        }
    }
}
