#pragma once

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


Node *createNode(int data);

void insertNode(Node **root, int data);
Node* getDeepestRightMostNode(Node* root);
void deleteDeepestRightMostNode(Node* root, Node* dNode);
void delete(Node** root, int data);
Node* search(Node** root, int data);
void traversal(const Node* root);
