#include <iostream>
#include <cstring>
using namespace std;
char k[1000000 + 5];
typedef long long ll;

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
    ll res = divMod(k, p - (ll)1);
    ll ans = qpow(a, res, p);
    cout << ans;
    return 0;
}