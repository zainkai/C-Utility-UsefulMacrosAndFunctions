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

#define DEBUG 0

typedef void* TYPE;

#define SAFE_FREE(x) do { if ((x) != NULL) {free(x); x=NULL;} } while(0)

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

//Only works with arrays
//EX:
// int values[] = { 1, 2, 3 };
// foreach(int *v, values) {
//     printf("value: %d\n", *v);
// }
#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)


//EX:
// int (*max) (int, int) = lambda(int, (int x, int y) { return x > y ? x : y; });
// int maximum = max(1, 2);
//
// int max = lambda(int, (int x, int y) { return x > y ? x : y; }) (100,200);
// lambda(void,(void){printf("printy print printy...\n"); })();
#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })

//EX:
// ERRPRINTLOG("error occured");
#define ERRPRINT(message)\
    fprintf(stderr,"%s:%d) %s",__FILE__,__LINE__,message);

//EX:
// ERRPRINTLOG("useful for debugging");
#define OUTPRINT(message)\
    fprintf(stdout,"%s:%d) %s",__FILE__,__LINE__,message);

//EX:
// forloop(0,3){
//     printf("heyooo");
// }
#define forloop(floor,ceiling)\
    int _FORLOOP_INT_;\
    for(_FORLOOP_INT_ = floor;_FORLOOP_INT_ < ceiling;_FORLOOP_INT_++)

#if DEBUG
int main(void){
    int x = 2;
    int y = 3;

    forloop(0,3){
        lambda(void,(void){printf("printy print printy...\n"); })();
    }

    int max = lambda(int, (int x, int y) { return x > y ? x : y; }) (100,200);

    printf("asdasdasd:%d\n",max);

    {
        ERRPRINT("20\% correct as usual morrrrrrty.\n");
    }

    int values[] = { 1, 2, 3 };
    foreach(int *v, values) {
        printf("value: %d\n", *v);
    }
    printf("arraysz::%lu\n",ARRAY_SIZE(values));


    int* newvalues = malloc(10 * sizeof(int));
    printf("heap size::%lu\n",ARRAY_SIZE(*newvalues));

    return 0;
}
#endif