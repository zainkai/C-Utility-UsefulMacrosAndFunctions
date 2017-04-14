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

typedef void* TYPE;

#define SAFE_FREE(x) do { if ((x) != NULL) {free(x); x=NULL;} } while(0)

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

//Only works with arrays
#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)
//EX:
// int values[] = { 1, 2, 3 };
// foreach(int *v, values) {
//     printf("value: %d\n", *v);
// }

#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })
//EX:
// int main (int argc, char **argv)
// {
//   int (*max) (int, int) = 
//     lambda(int, (int x, int y) { return x > y ? x : y; });
//   int maximum = max(1, 2);
// }

int swap(TYPE *x, TYPE *y)
{
    if(x == NULL || y == NULL){
        return EXIT_FAILURE;
    }

    TYPE z; //the same type as chosen in the brackets above
     
    z = *x;
    *x = *y;
    *y = z;

    return EXIT_SUCCESS;
}
//EX:
// swap(&x, &y); in arrays: swap(&array[k - 1], &array[k]);

#define ERRPRINTLOG(message)\
    fprintf(stderr,"%s:%d) %s",__FILE__,__LINE__,message);

#define OUTPRINTLOG(message)\
    fprintf(stdout,"%s:%d) %s",__FILE__,__LINE__,message);


int main(void){
    int (*max) (int, int) = lambda (int, (int x, int y) { x+=1; return x > y ? x : y; });
    printf("::::%d\n", max (45, 2));

    {
        ERRPRINTLOG("20\% correct as usual morrrrrrty.\n");
    }

    return 0;
}
