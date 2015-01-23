#include <stdio.h>

long long AxBmodM(long long a, long long b, long long m)
{
    long long r;
    for (r = 0; b; b >>= 3, a = (a << 3) % m) {
        if (b & 7) r = (r + a * (b & 7)) % m;
    }
    return r;
}

int main() 
{
    printf("%lld\n", AxBmodM(2147483647, 2147483647, 5));
    printf("%lld\n", AxBmodM(2147483648, 2147483648, 3));
    return 0;
}
