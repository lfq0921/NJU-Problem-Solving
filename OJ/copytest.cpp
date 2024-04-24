#include <iostream>
const int MOD = 998244353;
using namespace std;
int n, a[305], q;
int Pow(int x, int y)
{
    int re = 1;
    for (; y; y >>= 1, x = 1ll * x * x % MOD)
        if (y & 1)
            re = 1ll * re * x % MOD;
    return re;
}
int Mod(int x)
{
    return x < MOD ? x : x - MOD;
}
int main()
{
    scanf("%d", &n);
    q = Pow(n, MOD - 2);
    cout << "q = " << q << endl;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        int t = 0, p = a[i];
        for (int j = 1; j <= n; ++j)
            t = Mod(t + a[j]), printf("t = %d, i = %d, j = %d\n", t, i, j);
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                a[j] = 1ll * t * q % MOD, printf("a[%d] = %d, i = %d\n", j, a[j], i);
            else
                a[j] = 1ll * Mod(1ll * (n - 1) * a[j] % MOD + p) * q % MOD, printf("a[%d] = %d, i = %d\n", j, a[j], i);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    return 0;
}
