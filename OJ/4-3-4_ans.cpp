#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e7;
const int MAXT = 1e4;
bool vis[N + 5];
ll phi[N + 5], idx[N + 5], d[N + 5], mu[N + 5];
// phi表示欧拉函数，idx表示最小质因数的指数，d表示约数和，mu表示莫比乌斯函数

int T, p, t[MAXT + 1];
ll res[N + 5];
vector<ll> primes;

void seive()
{
    memset(vis, 0, sizeof(vis));
    phi[1] = 1;
    idx[1] = 0;
    d[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            primes.push_back(i);
            phi[i] = i - 1;
            idx[i] = 1;
            d[i] = 2;
            mu[i] = -1;
        }
        for (int j = 0; j < primes.size(); j++)
        {
            ll num = 1ll * i * primes[j];
            if (num > N)
                break;
            vis[num] = 1;
            if (i % primes[j] == 0)
            {
                phi[num] = phi[i] * primes[j];
                idx[num] = idx[i] + 1;
                d[num] = d[i] / idx[num] * (idx[num] + 1);
                mu[num] = 0;
                break;
            }
            else
            {
                phi[num] = phi[i] * phi[primes[j]];
                idx[num] = 1;
                d[num] = d[i] * 2; // d[primes[j]] = 2
                mu[num] = -mu[i];
            }
        }
    }
}

ll checkminus(ll &x, ll mod)
{
    while (x < 0)
        x += mod;
    return x;
}

int main()
{
    int maxn = 0;
    ll ans;
    seive();
    scanf("%d%d", &T, &p);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &t[i]);
        maxn = max(t[i], maxn);
    }
    memset(res, 0, sizeof(res));
    res[1] = 6;
    for (int i = 2; i <= maxn; i++)
        res[i] = (res[i - 1] + 2 * phi[i] * (d[i] + mu[i])) % p;
    for (int i = 1; i <= T; i++)
    {
        ll l = 1, r = 0;
        ans = 0;
        while (l <= t[i])
        {
            r = t[i] / (t[i] / l);
            ll tmp = res[r] - res[l - 1];
            ans = (ans + checkminus(tmp, p) * (t[i] / r)) % p;
            l = r + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}