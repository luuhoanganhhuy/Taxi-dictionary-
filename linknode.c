#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "linknode.h"

/*insert at foot for the linked list*/
/*contributed to my assignment 2 COMP10003 semester 1 2019*/
struct linkedlist *insert_at_foot(struct linkedlist *list, char* value) {
	struct datafiled *new;
	new = (struct datafiled*)malloc(sizeof(*new));
	assert(list!=NULL && new!=NULL);
	
	/*allocate the memory for data and initialise the value for data*/
	new->data = malloc( strlen (value) +1 ); 
	strcpy(new->data, value);
	
	/*make pointer point to the next data*/
	new->next = NULL;
	if (list->foot==NULL) {
		list->head = list->foot = new;
	} else {
		list->foot->next = new;
		list->foot = new;
	}
	return list;
}

/*free the linked list after using*/
void free_list(struct linkedlist *list) {
	struct datafiled *curr, *prev;
	assert(list!=NULL);
	curr = list->head;
	while (curr) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(list);
}