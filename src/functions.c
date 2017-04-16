/*************************************************************************************
** Copyright (c) 2017 Kevin Turkington                                              **
**                                                                                  **
** Permission is hereby granted, free of charge, to any person obtaining a copy     **
** of this software and associated documentation files (the "Software"), to deal    **
** in the Software without restriction, including without limitation the rights     **
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell        **
** copies of the Software, and to permit persons to whom the Software is            **
** furnished to do so, subject to the following conditions:                         **
**                                                                                  **
** The above copyright notice and this permission notice shall be included in all   **
** copies or substantial portions of the Software.                                  **
**                                                                                  **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR       **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,         **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE      **
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER           **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,    **
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE    **
** SOFTWARE.                                                                        **
**************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void* TYPE;

//EX:
// swap(&x, &y); in arrays: swap(&array[k - 1], &array[k]);
int swap(TYPE x, TYPE y)
{
    if(x == NULL || y == NULL){
        return EXIT_FAILURE;
    }

    TYPE z; //the same type as chosen in the brackets above
     
    z = x;
    x = y;
    y = z;

    return EXIT_SUCCESS;
}

char** strsplit(char* string, char* delims)
{
    if(string == NULL || delims == NULL){
        return NULL;
    }

    int n_tokens = 1;
    char* stringcpy = strdup(string);//copy for strtok to destroy.
    char** strArray = malloc(n_tokens * sizeof(char*));

    char* token = strtok(stringcpy,delims);
    while(token != NULL){
        strArray[n_tokens - 1] = strdup(token);
        strArray = realloc(strArray, ++n_tokens * sizeof(char*));

        token = strtok(NULL,delims);
    }

    free(stringcpy);
    return strArray;
}