#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "linknode.h"
#include "bstnode.h"
#include "compare.h"
#include "traverse.h"
#include "getvalue.h"

/*created by Hoang Anh Huy Luu Sid 1025379, 9 September 2019*/
/*define all the constant*/
#define MAXLEN 256
#define NUMLOCATION 6
#define NUMKEY 16


/*a program to create a BST from the input datafile, accepct the duplicated key
using the linked list, then using the input from stdin for searching the corresponding data
of each key in this BST using in-order traversal tree and create the output file contains
all the corresponding keys to the matching data*/
int main(int argc, char **argv){
	//read the file from the command line

	char buffer[MAXLEN];
	char value[MAXLEN];

	/*initialise the null value to the first root of BST*/
	struct node *root = NULL;

	/*read the file from the command line*/
	FILE *fp = fopen(argv[1],"r");

	/*header of all data*/
	char header[] = "VendorID,passenger_count,trip_distance,RatecodeID,store_and_fwd_flag,PULocationID,DOLocationID,payment_type,fare_amount,extra,mta_tax,tip_amount,tolls_amount,improvement_surcharge,total_amount,PUdatetime,DOdatetime,trip_duration";

	/*read each line from the datafile*/
	while(fgets(buffer, MAXLEN,fp)){

		/*get the data as the location id for each key*/
		char* data;
		data = (char*)calloc(MAXLEN,sizeof(char));
		char* tmp = strdup(buffer);
		strcpy(data,getvalue(tmp,NUMLOCATION));
		free (tmp);

		/*insert key and the corresponding data to BST*/
		char* tmp1 = strdup(buffer);
		char* key;
		key = (char*)malloc(MAXLEN*sizeof(char));
		strcpy(key,getvalue(tmp1, NUMKEY));
		insert(key,data, &root, (Compare)CmpStr);
		free(tmp1);
		free(key);
	}

	/*read the output name file from command line and creata an output file*/
	FILE *nf = fopen(argv[2],"w");

	/*read the input from stdin*/
	while (fgets(value,MAXLEN,stdin)){
		/*skip the newline character while using fgets function*/
		if (!strcmp(value,"\n")){
			continue;
		}

		/*delete the newline character at the end of each string while
		using fgets function*/
		value[strcspn(value, "\r\n")] = 0;

		int count = 0;
		int countTime =0;
		/*search for the data in each key*/
		inOrderTravesal(value,nf, root, (Compare)CmpStr,&count,&countTime);

		/*if there is no comparison, put the unmatching data to the outputfile*/
		if (countTime == 0){
			fputs(value,nf);
			fputs(" --> NOT FOUND",nf);
			fputs("\n",nf);
		}
		/*print the number of comparisons for each data*/
		printf("%s --> %d\n",value,count);

	}

	/*free the BST*/
	freeTree(root);

	/*close the input file and output file*/
	fclose(nf);
	fclose(fp);

    return 0;
}
