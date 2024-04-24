#include<iostream>
#include<cctype>
#include<cstdio>
#include <bits/stdc++.h>
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
__uint128_t A;
int opt, x, N, l, r;

__uint128_t mask(int x)
{
	return (1 << x) - 1;
}

__uint128_t moveright(__uint128_t val, int n) 
{
	n = n % 128;
	return (val << (128 - n) | (val >> n));
}
__uint128_t moveleft(__uint128_t val, int n) 
{
	n = n % 128;
	return (val >> (128 - n) | (val << n));
}

int main()
{
	read(N);
	while(N--)
	{
		read(opt);
		if(opt == 1)
		{
			read(x);
			x = (x % 128 + 128) % 128; 
				for (int i = 1; i <= x; ++i) A = (A >> 1) | (A << 127);
		}
		if (opt == 2)
		{
			printf("%X\n", (unsigned short) A);
		}
		if (opt == 3)
		{
			read(l);
			read(r);
			__uint128_t a1 = mask(r - l + 1);
			printf("a10 = %X\n", (unsigned short)a1);
			x = (l % 128 + 128) % 128; 
				for (int i = 1; i <= x; ++i) a1 = (a1 << 1) | (a1 >> 127);
			printf("a11 = %X\n", (unsigned short)a1);
			A = A ^ a1;
		}
	}
	
}
