#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long n, k, m;
int primflag;
long long p[N], e[N], cnt;
long long qmi(long long a, long long b, long long P)
{
    a = a % P;
    long long res = 1 % P;
    while (b)
    {
        if (b & 1)
            res = (long long)res * a % P; // 快速幂
        a = (long long)a * a % P;
        b >>= 1;
    }
    return res;
}
long long dengbi(long long prim, long long exp, long long MOD) // 1+...+p^k 等比数列求和
{
    if (exp == 1)
        return (1 % MOD + prim % MOD) % MOD;
    if (exp == 0)
        return (1 % MOD);
    if (exp % 2 == 0)
    {
        return (qmi(prim, exp, MOD) + dengbi(prim, exp - 1, MOD)) % MOD;
    }
    long long ceilexp = exp / 2 + 1;
    long long tmp = (1 % MOD + qmi(prim, ceilexp, MOD)) % MOD;
    return (tmp * dengbi(prim, exp / 2, MOD)) % MOD;
}
int main()
{
    cin >> n >> k >> m;
    cin >> primflag;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p[++cnt] = i; // 存储质因数
            while (n % i == 0)
            {
                e[cnt]++; // 存储质因数的指数
                n /= i;
            }
        }
    }
    if (n > 1)
        p[++cnt] = n, e[cnt] = 1;
    // 到目前为止求到了n的所有质因子以及其对应的次数
    long long ans = 1;
    for (int i = 1; i <= cnt; i++) // 对每个质因子进行操作
    {
        long long pexp = dengbi(p[i], k * e[i], m) % m;
        ans = ((long long)ans * (dengbi(p[i], k * e[i], m) % m)) % m;
    }
    cout << ans << endl;
    return 0;
}