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
    int local1;

    // heap segment
    int *pheap = (int *)malloc(sizeof (int));
    int *pheap1 = (int *)malloc(sizeof (int));

    // BSS segment
    static int static_local;
    static int static_local1;

    // data segment
    static int static_local_init = 6;
    static int static_local_init1 = 6;

    // code segment
    char *pcode = "code segment str";

    puts("==============stack segment==============");
    printf("local %p\n", &local);
    printf("local1 %p\n", &local1);
    puts("==============stack segment==============");

    puts("==============heap segment==============");
    printf("pheap %p\n", pheap);
    printf("pheap1 %p\n", pheap1);
    puts("==============heap segment==============");

    puts("==============BSS segment==============");
    printf("global %p\n", &global);
    printf("static_global %p\n", &static_global);
    printf("static_local %p\n", &static_local);
    printf("static_local1 %p\n", &static_local1);
    puts("==============BSS segment==============");

    puts("==============data segment==============");
    printf("global_init %p\n", &global_init);
    printf("static_global_init %p\n", &static_global_init);
    printf("static_local_init %p\n", &static_local_init);
    printf("static_local_init1 %p\n", &static_local_init1);
    puts("==============data segment==============");

    puts("==============code segment==============");
    printf("pcode %p\n", pcode);
    puts("==============code segment==============");
    return 0;
}
