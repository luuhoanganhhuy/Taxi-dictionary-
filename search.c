#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "linknode.h"
#include "bstnode.h"
#include "compare.h"
#include "search.h"


/*function to search for the searching keys and print the 
number of comparisons*/
void search(char* key,FILE* nf, struct node* leaf, Compare cmp,int* count)
{
    int cmpRes;
    if( leaf != NULL ) {
		/*compute the comparision result between they searching key and node*/
        cmpRes = cmp(key, leaf->value);
		
		/*count the number of comparisons*/
		(*count)++;
		
		/*if the result less than 0, recur to the left*/
        if( cmpRes < 0){
            search( key,nf, leaf->left, cmp,count);
		}
		
		/*if the result greater than 0, recur to the right*/
        else if(cmpRes > 0){
            search( key,nf, leaf->right, cmp,count);
		}
        else{	
			/*print the number of comparisons to stdout*/
			printf("%s --> %d\n",key,*count);
			
			/*get all the data from each key*/
			struct datafiled *new;
			new = leaf->str->head;
			while(new != NULL) {
				/*put data into the outputfile*/
				fputs(key,nf);
				fputs(" ",nf);
				fputs(new->data,nf);
				new = new->next;
			}
			
			/*free the linked list after using*/
			free_list(leaf->str);
		}
    }
    else{
		/*print the number of comparisons to stdout*/
		printf("%s --> %d\n",key,*count);
		
		/*put the unmatching key into outputfile*/ 
		fputs(key,nf);
		fputs(" --> NOT FOUND",nf);
		fputs("\n",nf);  
	}
    return;
}
