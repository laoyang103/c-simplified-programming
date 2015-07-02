#include <stdio.h>
#include <stdlib.h>

// ref http://www.cnblogs.com/clover-toeic/p/3754433.html

// BSS segment
int global;
static int static_global;
int global_zero = 0;
static int static_global_zero = 0;

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
    printf("local                   %018p\n", &local);
    printf("local1                  %018p\n", &local1);
    puts("==============stack segment==============");

    puts("==============heap segment==============");
    printf("pheap                   %018p\n", pheap);
    printf("pheap1                  %018p\n", pheap1);
    puts("==============heap segment==============");

    puts("==============BSS segment==============");
    printf("global                  %018p\n", &global);
    printf("static_global           %018p\n", &static_global);
    printf("global_zero             %018p\n", &global_zero);
    printf("static_global_zero      %018p\n", &static_global_zero);
    puts("==============BSS segment==============");

    puts("==============data segment==============");
    printf("global_init             %018p\n", &global_init);
    printf("static_global_init      %018p\n", &static_global_init);
    printf("static_local_init       %018p\n", &static_local_init);
    printf("static_local_init1      %018p\n", &static_local_init1);
    puts("==============data segment==============");

    puts("==============code segment==============");
    printf("pcode                   %018p\n", pcode);
    puts("==============code segment==============");
    return 0;
}
