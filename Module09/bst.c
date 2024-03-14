#include "bst.h"

#include <stdio.h>
#include <string.h>

BST *create_bst() {
    BST *bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    bst->size = 0;
    return bst;
}

Node * __create_node(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void __add_node(Node* curr, int data) {

    if(curr->data > data) {
        if(curr->left == NULL) {
            curr->left = __create_node(data);
            return;
        }else {
            __add_node(curr->left, data);
        }
    }else {
        if(curr->right == NULL) {
            curr->right = __create_node(data);
            return;
        } else {
            __add_node(curr->right, data);
        }
    }
}

void add_node(BST* tree, int data) {
    if (tree->root == NULL) {
        tree->root = __create_node(data);
        tree->size++;
        return;
    }
    __add_node(tree->root, data);
}
// from homework
char *__bst__update_str(int data, char *str)
{
    str = realloc(str, sizeof(char) * (strlen(str) + 5));
    if (strlen(str) > 0)
    {
        strcat(str, ", ");
    }
    char * tmp = malloc(sizeof(char) * 5);
    sprintf(tmp, "%d", data);
    strcat(str, tmp);
    free(tmp);
    return str;
}

void __dfs_inOrder(Node* node, char* str) {
    if(node == NULL) return;

    __dfs_inOrder(node->left, str);
//    printf("%d, ", node->data);
    __bst__update_str(node->data, str);
    __dfs_inOrder(node->right, str);
}

void dfs_inOrder(BST* tree) {
    char* str = (char*)malloc(sizeof(char) * 100);
    str[0] = '\0';
    __dfs_inOrder(tree->root, str);
   // strcat(str, "\n");

    printf("%s\n", str);
}

/*
                10
              /   \
            7       13
              \     /
               8   12

7 8 10 12 13

*/

int main() {
    BST *tree = create_bst();
    add_node(tree, 10);
    add_node(tree, 7); // left
    add_node(tree, 8); // left then right
    add_node(tree, 13); // right
    add_node(tree, 12); // right then left

    dfs_inOrder(tree);


    return 0;
}