#include <stdio.h>
#include <stdlib.h>

// ref http://www.cnblogs.com/clover-toeic/p/3754433.html

// BSS segment
int global;
static int static_global;

// data segment
int global_init = 5;
static int static_global_init = 5;

int main()
{
    // stack segment
    int local;

    // heap segment
    int *pheap = (int *)malloc(sizeof (int));

    // BSS segment
    static int static_local;

    // data segment
    static int static_local_init = 6;

    // code segment
    char *pcode = "code segment str";

    puts("==============stack segment==============");
    printf("local %p\n", &local);
    puts("==============stack segment==============");

    puts("==============heap segment==============");
    printf("pheap %p\n", pheap);
    puts("==============heap segment==============");

    puts("==============BSS segment==============");
    printf("global %p\n", &global);
    printf("static_global %p\n", &static_global);
    printf("static_local %p\n", &static_local);
    puts("==============BSS segment==============");

    puts("==============data segment==============");
    printf("global_init %p\n", &global_init);
    printf("static_global_init %p\n", &static_global_init);
    printf("static_local_init %p\n", &static_local_init);
    puts("==============data segment==============");

    puts("==============code segment==============");
    printf("pcode %p\n", pcode);
    puts("==============code segment==============");
    return 0;
}
