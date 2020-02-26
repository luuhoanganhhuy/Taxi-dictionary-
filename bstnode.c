#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "linknode.h"
#include "bstnode.h"
#include "compare.h"



/*inserts keys and data into the BST*/
void insert(char* key,char* data, struct node** leaf, Compare cmp)
{
    int cmpRes;
	
	/*insert the key to the node if the node is null*/
    if( *leaf == NULL ) {
		
		/*allocate the momory for the node and assign the value for the node*/
        *leaf = (struct node*) malloc( sizeof( struct node ) ); 
        (*leaf)->value = malloc( strlen (key) +1 ); 
        strcpy ((*leaf)->value, key);
		
		/*allocate the memory for linked list and assign the first value to the list*/
		(*leaf)->str = calloc (1, sizeof (struct linkedlist));
		insert_at_foot((*leaf)->str,data);
		
		/*initialise the left and right child as null*/
        (*leaf)->left = NULL;
        (*leaf)->right = NULL;
    } else {
		
		/*compute the compare result of the searching key and node*/
        cmpRes = cmp(key, (*leaf)->value);
		
		/*recur to the left if the result smaller than 0*/
        if( cmpRes < 0)
            insert( key,data, &(*leaf)->left, cmp);
		
		/*recur to the right if the result greater than 0*/
        else if( cmpRes > 0)
            insert( key,data, &(*leaf)->right, cmp);
		
		/*if the key already exists in the BST, add data to the linked list*/
        else { 
			insert_at_foot((*leaf)->str,data);
		}
    }
}

/*function to free the BST after using*/
/*contibuted to workshop 4 freeTree function from COMP20003*/
void freeTree(struct node *parent){
    if(! parent){
        return;
    }
	
	freeTree(parent->left);
	freeTree(parent->right);
	free(parent);
}