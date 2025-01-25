#include "../../BinaryTree/binary_tree.h"
#include <stdio.h>
int main()
{
    BT_Node* root = NULL;

    // Inserting nodes
    BT_insert(&root, 20);
    BT_insert(&root, 30);
    BT_insert(&root, 40);
    BT_insert(&root, 50);
    BT_insert(&root, 60);
    BT_insert(&root, 70);
    BT_insert(&root, 80);

    // Inorder traversal
    printf("Inorder traversal of the given Binary Search "
           "Tree is: ");
    BT_traversal(root);
    printf("\n");

    // Deleting a node
    int deleteValue = 20;
    BT_delete (&root, deleteValue);
    printf("After deletion of %d: ", deleteValue);
    BT_traversal(root);
    printf("\n");

    // Inserting a new node
    int insertValue = 25;
    BT_insert(&root, insertValue);
    printf("After insertion of %d: ", insertValue);
    BT_traversal(root);
    printf("\n");

    // Searching for a node
    int target = 25;
    BT_Node* searchResult = BT_search(&root, target);
    if (searchResult != NULL) {
        printf("Node %d found in the BST.\n", target);
    }
    else {
        printf("Node %d not found in the BST.\n", target);
    }

    return 0;
}