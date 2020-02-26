#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "linknode.h"
#include "bstnode.h"
#include "compare.h"
#include "traverse.h"

void inOrderTravesal(char* key, FILE *nf, struct node* leaf, Compare cmp, int* count,int* countTime){
	int cmpRes;
	if (leaf != NULL){	
		/*recur to the left child */
		inOrderTravesal( key,nf, leaf->left, cmp,count,countTime); 
		
		/* compare the data of the key with the searching data */
		/*go over all the data in each key to search for matching*/
		struct datafiled *new;
		new = leaf->str->head;
		while (new != NULL){
			/*compute the comparison result between data and searching data*/
			cmpRes = cmp(key, new->data);
			
			/*count the number of comparisons*/
			(*count)++;
			if (cmpRes == 0){
				/*count the number of matching data*/
				(*countTime)++;
				
				/*put the data into outputfile*/
				fputs(key,nf);
				fputs(" --> ",nf);
				fputs(leaf->value,nf);
				fputs("\n",nf);
			}
			new = new->next;
		}
    /* now recur on right child */
		inOrderTravesal( key,nf, leaf->right, cmp,count,countTime);
	}
	return;
}
