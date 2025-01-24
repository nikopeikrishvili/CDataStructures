#pragma once

typedef struct BT_BT_Node {
    int data;
    struct BT_Node *left;
    struct BT_Node *right;
} BT_Node;


BT_Node *BT_create(int data);

void BT_insert(BT_Node **root, int data);
BT_Node* BT_getDeepestRightMost(BT_Node* root);
void BT_deleteDeepestRightMost(BT_Node* root, BT_Node* dBT_Node);
void BT_delete(BT_Node** root, int data);
BT_Node* BT_search(BT_Node** root, int data);
void BT_traversal(const BT_Node* root);
