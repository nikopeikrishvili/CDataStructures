#include "binary_tree.h"

#include <stdio.h>
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
void delete (Node** root, int data)
{
    if (*root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if ((*root)->left == NULL && (*root)->right == NULL) {
        if ((*root)->data == data) {
            free(*root);
            *root = NULL;
            return;
        }
        else {
            printf("Node not found.\n");
            return;
        }
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    Node* keyNode = NULL;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == data) {
            keyNode = temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }

    if (keyNode != NULL) {
        Node* deepestNode = getDeepestRightMostNode(*root);
        keyNode->data = deepestNode->data;
        deleteDeepestRightmostNode(*root, deepestNode);
    }
    else {
        printf("Node not found.\n");
    }
}
Node* search(Node* root, const int data)
{
    if (root == NULL) {
        return NULL;
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == data) {
            return temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }
    return NULL;
}