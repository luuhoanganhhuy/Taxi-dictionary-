#include "compare.h"

/* create a struct node to as a node in BST */
/* each node contain a pointer to its left and right child
as also the key as string and data as a linked list*/
struct node {
	struct linkedlist *str;
    char *value;            
    struct node *left;
    struct node *right;
};

/* a function to insert to the key to BST and the data to the linked list */
void insert(char* key,char* data, struct node** leaf, Compare cmp);

/* a function to free the BST after using*/
void freeTree(struct node *parent);
