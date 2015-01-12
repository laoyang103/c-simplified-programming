#include <stdio.h>

typedef union _byte_order
{
    unsigned short a;
    unsigned char b[2];
} byte_order;

byte_order bo;

int main() 
{
    bo.a = 0x0102;
    if (bo.b[0] == 1 && bo.b[1] == 2) {
        printf("Big\n");
    } else if (bo.b[0] == 2 && bo.b[1] == 1) {
        printf("Little\n");
    }
    return 0;
}
