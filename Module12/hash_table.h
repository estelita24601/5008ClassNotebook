#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef unsigned long long ul;

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

ul hash_function(char *str, int size)
{
    ul hash = 5381;
    int char_address;

    while ((char_address = *str++))
    {
        hash = ((hash << 5) + hash) + char_address;
    }

    return hash % size;
}


// note: remember that HashTable is actually an array of pointers
HashTable create_hash_table(int size)
{
    return malloc(sizeof(Node) * size);
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

void print_node(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("(\"%s\": \"%s\") ", curr->key, curr->value);
        curr = curr->next_node;
    }
}

void print_hash_table(HashTable tbl, int size)
{
    printf("{\n");
    for (int i = 0; i < size; i++)
    {
        if (tbl[i] != NULL)
        {
            printf("%d - ", i);
            print_node(tbl[i]);
            printf("\n");
        }
    }

    printf("}\n");
}

char *table_get(HashTable tbl, int tbl_size, char *key)
{
    ul hash = hash_function(key, tbl_size);
    Node *slot = tbl[hash];

    if (slot == NULL)
    {
        return NULL; // doesn't exist
    }
    else
    {
        while (slot != NULL)
        {
            if (slot->key == key)
            {
                return slot->value; // we found it
            }
            else
            {
                slot = slot->next_node; // otherwise keep on looking
            }
        }
    }
    return NULL; // searched entire linked list and couldn't find it
}

void free_table(HashTable table, int size)
{
    for (int i = 0; i < size; i++)
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

void add(HashTable tbl, int tbl_size, char *key, char *value)
{
    ul hash = hash_function(key, tbl_size);
    Node *new_node = create_node(key, value);

    if (tbl[hash] == NULL)
    {
        // print_debug("detected no collision");
        tbl[hash] = new_node; // no collision just add the node here
    }
    else
    {
        print_debug("\tdetected collision");
        ll_add_back(tbl[hash], new_node); // there was a collision so add to the existing node/linked list
    }
}

#endif