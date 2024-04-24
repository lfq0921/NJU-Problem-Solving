#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int N = 10000000 + 5;
int f[N];
int main()
{
    srand(time(0));
    int n = 100000;
    printf("%d\n", n);
    for (int i = 2; i <= n; i++)
    {
        int x = rand() % i + 1, c = rand() % 1 + 1;
        while (x == i) x = rand() % i + 1;
        if (rand() % 2) printf("%d %d %d\n", x, i, c);
        else printf("%d %d %d\n", i, x, c);
    }

    for (int i = 1; i <= n; i++) f[i] = i;
    random_shuffle(f + 1, f + n + 1);

    int S = rand() % (n - 1) + 1, T = S + rand() % (n - S) + 1;
    assert(S <= T && T <= n);
    printf("%d ", S);
    for (int i = 1; i <= S; i++) printf("%d ", f[i]);
    printf("\n");
    printf("%d ", n - T + 1);
    for (int i = T; i <= n; i++) printf("%d ", f[i]);
    return 0;
}

