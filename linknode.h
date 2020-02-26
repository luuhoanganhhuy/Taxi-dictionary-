/*create a struct contain the data and the pointer point to
the next data*/
struct datafiled {
	char* data;
	struct datafiled *next;
};

/*create a linked list*/
struct linkedlist {
	struct datafiled *head;
	struct datafiled *foot;
};

/*insert at foot for the linked list*/
/*contributed to my assignment 2 COMP10003 semester 1 2019*/
struct linkedlist
*insert_at_foot(struct linkedlist *list, char* value);

/*free the linked list after use*/
void free_list(struct linkedlist *list);