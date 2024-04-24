#include <iostream>
using namespace std;
typedef long long ll;
char k[1000000 + 5];

ll Euler(ll n) // 1.直接求欧拉函数的值
{
    ll rea = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) // 第一次找到的必为素因子
        {
            rea = rea - rea / i;
            while (n % i == 0)
            {
                n = n / i; // 把该素因子全部约掉
            }
        }
    if (n > 1)
        rea = rea - rea / n;
    return rea;
}

ll divMod(char *ch, ll num)
{
    ll s = 0;
    for (int i = 0; ch[i] != '\0'; i++)
        s = (s * 10 + ch[i] - '0') % num;
    return s;
}

ll qpow(ll a, ll n, ll MOD)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1, MOD) * a % MOD;
    else
    {
        ll temp = qpow(a, n / 2, MOD) % MOD;
        return temp * temp % MOD;
    }
}

int main()
{
    long long a, p;
    cin >> a >> k >> p;
    if (p == 1)
    {
        cout << 0;
        return 0;
    }
    ll newp = Euler(p);
    ll res = divMod(k, newp);
    ll ans = qpow(a, res, p);
    cout << ans;
    return 0;
}
