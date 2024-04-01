#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 100
typedef unsigned long ul;

void print_debug(char *msg)
{
    printf("\t%s\n", msg);
    fflush(stdout);
}

typedef struct node
{
    char *key;
    char *value;
    struct node *next_node;
} Node;

typedef Node **HashTable; // if we have an array of pointers to nodes call that a hash table

// note: remember that HashTable is actually an array of pointers
HashTable create_hash_table()
{
    Node **new_table = malloc(sizeof(Node) * SIZE);
    return new_table;
}

Node *create_node(char *key, char *value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next_node = NULL;
    return new_node;
}

void ll_add_back(Node *head, Node *new)
{
    // loop through the entire linked list
    Node *curr = head;
    while (curr->next_node != NULL)
    {
        curr = curr->next_node;
    }
    // now we're at the tail replace null with the new node
    curr->next_node = new;
}

void free_table(HashTable table)
{
    for (int i = 0; i < SIZE; i++)
    {
        free(table[i]); // free the nodes
    }
    free(table); // now we can free the table
}

void free_ll(Node *head)
{
    Node *temp;

    while (head->next_node != NULL)
    {
        temp = head;
        head = head->next_node;
        free(temp);
    }

    free(head);
}

// FIXME: returning negative numbers for everything except "Darth Vader"
int hash_function(char *str)
{
    ul hash = 5381;
    int char_address;

    while ((char_address = *str++))
    {
        hash = ((hash << 5) + hash) + char_address;
    }

    return hash;
}

void add(HashTable tbl, char *key, char *value)
{
    printf("key = %s\n", key);
    int hash = hash_function(key) % SIZE;
    if (hash < 0)
    {
        print_debug("FIXING NEGATIVE HASH!"); // debug
        hash = hash * -1;
    }

    printf("hash %s --> %d\n", key, hash);
    fflush(stdout);

    Node *new_node = create_node(key, value);
    print_debug("successfully create new node");

    if (tbl[hash] == NULL)
    {
        print_debug("detected no collision");
        tbl[hash] = new_node; // no collision just add the node here
    }
    else
    {
        print_debug("detected collision");
        ll_add_back(tbl[hash], new_node); // there was a collision so add to the existing node/linked list
    }
}

#endif