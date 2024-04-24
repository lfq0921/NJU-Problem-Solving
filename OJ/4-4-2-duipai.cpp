#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long n, k, m;
int primflag;
int p[N], e[N], cnt;
long long qmi(long long a, long long b, long long P)
{
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
long long dengbi(int prim, long long exp, long long MOD) // 1+...+p^k 等比数列求和
{
    if (exp == 1)
        return (1 % MOD + prim % MOD) % MOD;
    if (exp == 0)
        return (1 % MOD);
    long long tmp = (1 % MOD + qmi(prim, ceil(exp / 2), MOD)) % MOD;
    return (tmp % MOD * dengbi(prim, floor(exp / 2), MOD)) % MOD;
}
int main()
{
    int p;
    long long x, m;
    cin >> p >> x >> m;
    /*cin >> n >> k >> m;
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
    for (int i = 1; i <= cnt; i++)
    {
        printf("p[%d] = %lld, e[%d] = %lld\n", i, p[i], i, e[i]);
    }
    int ans = 1;
    for (int i = 1; i <= cnt; i++) // 对每个质因子进行操作
    {
        int t = qmi(p[i], k * e[i] + 1, m); // t=p[i]^{k * e[i] + 1}%m
        t--;
        if (t < 0)
            t += m;
        ans = (long long)ans * t % m * qmi(p[i] - 1, m - 2, m) % m; // 求解s(n)%m 将ans乘上t，再乘上p[i]-1的逆元，最后对m取模，得到s(n)%m的值。
    }
    cout << ans << endl;*/
    return 0;
}