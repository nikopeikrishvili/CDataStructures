#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>


BT_Node *BT_create(const int data) {
    BT_Node *newBT_Node = (BT_Node *) malloc(sizeof(BT_Node));
    newBT_Node->data = data;
    newBT_Node->left = NULL;
    newBT_Node->right = NULL;
    return newBT_Node;
}

void BT_insert(BT_Node **root, const int data) {
    BT_Node *newBT_Node = BT_create(data);

    if (NULL == *root) {
        *root = newBT_Node;
        return;
    }
    int front = -1, rear = -1;
    BT_Node *queue[100];
    queue[++rear] = *root;
    while (front != rear) {
        BT_Node *temp = queue[++front];

        if (NULL == temp->left) {
            temp->left = newBT_Node;
            return;
        } else {
            queue[++rear] = temp->left;
        }
        if (NULL == temp->right) {
            temp->right = newBT_Node;
            return;
        } else {
            queue[++rear] = temp->right;
        }
    }
}

BT_Node *BT_getDeepestRightMost(BT_Node *root) {
    BT_Node *temp;
    BT_Node *queue[100];
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

void deleteDeepestRightmost(BT_Node *root, BT_Node *dBT_Node) {
    BT_Node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        BT_Node *temp = queue[++front];

        if (temp == dBT_Node) {
            temp = NULL;
            free(dBT_Node);
            return;
        }

        if (temp->right != NULL) {
            if (temp->right == dBT_Node) {
                temp->right = NULL;
                free(dBT_Node);
                return;
            } else {
                queue[++rear] = temp->right;
            }
        }

        if (temp->left != NULL) {
            if (temp->left == dBT_Node) {
                temp->left = NULL;
                free(dBT_Node);
                return;
            } else {
                queue[++rear] = temp->left;
            }
        }
    }
}
void delete(BT_Node** root, int data)
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
            printf("BT_Node not found.\n");
            return;
        }
    }

    BT_Node* temp;
    BT_Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    BT_Node* keyBT_Node = NULL;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == data) {
            keyBT_Node = temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }

    if (keyBT_Node != NULL) {
        BT_Node* deepestBT_Node = BT_getDeepestRightMost(*root);
        keyBT_Node->data = deepestBT_Node->data;
        deleteDeepestRightmost(*root, deepestBT_Node);
    }
    else {
        printf("BT_Node not found.\n");
    }
}
BT_Node* BT_search(BT_Node* root, const int data)
{
    if (root == NULL) {
        return NULL;
    }

    BT_Node* temp;
    BT_Node* queue[100];
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
void BT_traversal(const BT_Node* root)
{
    if (root == NULL) {
        return;
    }

    BT_traversal(root->left);
    printf("%d ", root->data);
    BT_traversal(root->right);
}