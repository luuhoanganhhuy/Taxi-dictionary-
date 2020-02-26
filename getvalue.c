#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "getvalue.h"

/*function to get the value in each comma */
/*contributed to the answer in this website
"https://stackoverflow.com/questions/12911299/read-csv-file-in-c"*/
const char* getvalue(char* line, int num)
{
    const char* node;
    for (node = strtok(line, ",");
            node && *node;
            node = strtok(NULL, ",\n"))
    {
        if (!--num)
            return node;
    }
    return NULL;
}