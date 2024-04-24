#include <iostream>
using namespace std;
const int MOD = 998244353;
long long n, m;
long long ans = 0;
long long quick_pow(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}
inline long long gcd(long long a, long long b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        ans = (ans + quick_pow(m, gcd(n, i)) % MOD) % MOD;
    ans = (ans + ((n / 2) * quick_pow(m, n / 2)) % MOD + (n / 2) * quick_pow(m, (n / 2 + 1)) % MOD) % MOD;
    ans = ans * quick_pow(2 * n, (long long)MOD - 2) % MOD;
    printf("%lld", ans);
}