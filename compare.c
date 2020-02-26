#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "compare.h"

/*a function to compare two strings */
int CmpStr(const char *a, const char *b){
	/* string comparison instead of pointer comparison*/
    return (strcmp (a, b));     
}
