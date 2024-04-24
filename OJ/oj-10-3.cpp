#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;

template <typename Type>
void read(Type &a) {
    char t, f = 1;
    while (!isdigit(t = getchar())) {
        if (t == '-') f = -1;
    }
    a = t - '0';
    while ( isdigit(t = getchar())) {
        a *= 10;
        a += t - '0';
    }
    a *= f;
}
__uint128_t mask(int x)
{
	return (1 << x) - 1;
}

__uint128_t x;
int t, opt, a, b;

int main() {
    read(t);
    while (t--) {
        read(opt);
        if (opt == 1) {
            read(a); 
            a = (a % 128 + 128) % 128;
            x = (x >> a) | (x << 128 - a);
        }
        if (opt == 2)
            printf("%X\n", (unsigned short) x);
        if (opt == 3) {
            read(a); read(b);
            __uint128_t a1 = mask(b - a + 1);
            b =  
            x ^= ((__uint128_t)1 << a + 1) - 1;
            x ^= ((__uint128_t)1 << b) - 1;
        }
    }

    return 0;
}

