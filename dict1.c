#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "linknode.h"
#include "bstnode.h"
#include "compare.h"
#include "search.h"
#include "getvalue.h"

/*created by Hoang Anh Huy Luu Sid 1025379 9 September 2019*/
/*define all the constant*/
#define MAXLEN 256
#define NUMDATA 18
#define NUMKEY 16

/*a program to create a BST from the input datafile, accepct the duplicated key
using the linked list, then using the input from stdin for searching in this BST
and create the output file contains all the corresponding data to the matching keys*/
int main(int argc, char **argv){

	char buffer[MAXLEN];
	char input[MAXLEN];

	/*initialise the null value to the first root of BST*/
	struct node *root = NULL;

	/*read the file from the command line*/
	FILE *fp = fopen(argv[1],"r");

	/*header of all data*/
	char header[] = "VendorID,passenger_count,trip_distance,RatecodeID,store_and_fwd_flag,PULocationID,DOLocationID,payment_type,fare_amount,extra,mta_tax,tip_amount,tolls_amount,improvement_surcharge,total_amount,PUdatetime,DOdatetime,trip_duration";

	/*read each line from the datafile*/
	while(fgets(buffer, MAXLEN,fp)){
		/*get the string contain all the data for one key*/
		char* data;
		data = (char*)calloc(MAXLEN,sizeof(char));
		strcpy(data, "-->");
		for (int i = 1; i <= NUMDATA;i++ ){
			if (i!=NUMKEY){
				char* attribute =  strdup(header);
				char* tmp =  strdup(buffer);
				strcat(data," ");
				strcat(data,getvalue(attribute,i));
				strcat(data,": ");
				strcat(data,getvalue(tmp,i));
				strcat(data, " ||");
				free(tmp);
			}
		}
		strcat(data,"\n");

		/*insert the key and the corresponding data to BST*/
		char* tmp = strdup(buffer);
		char* key;
		key = (char*)malloc(MAXLEN*sizeof(char));
		strcpy(key,getvalue(tmp, NUMKEY));
		insert(key,data, &root, (Compare)CmpStr);
		free(tmp);
		free(key);
	}

	/*read the output name file from command line and creata an output file*/
	FILE *nf = fopen(argv[2],"w");

	/*read the input from stdin*/
	while (fgets(input,MAXLEN,stdin)){
		/*skip the newline character while using fgets function*/
		if (!strcmp(input,"\n")){
			continue;
		}

		/*delete the newline character at the end of each string while
		using fgets function*/
		input[strcspn(input, "\r\n")] = 0;
		int count = 0;

		/*search for the searching key*/
		search(input,nf, root, (Compare)CmpStr,&count);
	}

	/*free the BST*/
	freeTree(root);

	/*close the input file and output file*/
	fclose(nf);
	fclose(fp);

    return 0;
}
