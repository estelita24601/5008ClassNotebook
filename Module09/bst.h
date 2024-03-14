
#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


typedef struct BST {
    Node* root;
    int size;
} BST;


BST * create_bst();
void add_node(BST* tree, int data);
void dfs_inOrder(BST *tree);

#endif // BST_H