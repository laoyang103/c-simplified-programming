

#ifdef UN_USE_INCLUDE_DEMO
/**
 * use printf without #include<stdio.h> , copy
 * from /usr/include/stdio.h
 */
extern int printf (const char *__restrict __format, ...);
extern int add(int a, int b);
extern int sub(int a, int b);

int main()
{
    printf("use printf without #include<stdio.h>\n");
    printf("%d\n", add(8, 9));
    printf("%d\n", sub(8, 9));
}

#endif

#ifdef USE_INCLUDE_DEMO

#include "moda.h"
#include "moda.h"
#include <stdio.h>
#include <stdio.h>
int main()
{
    printf("use printf with #include<stdio.h>\n");
    printf("%d\n", add(8, 9));
    printf("%d\n", sub(8, 9));
}

#endif
