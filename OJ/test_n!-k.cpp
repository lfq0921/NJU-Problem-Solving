#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long LL;

unordered_map<LL, LL> mp;

LL k0;

LL getnum(LL a, LL b) // 求该质因子a在b中做出的贡献
{
    LL ans = 0;
    while (b)
    {
        ans += b / a;
        b /= a;
    }
    return ans;
}
void foundk(LL khere)
{
    int i = 2;
    while (khere > 1)
    {
        if (khere % i == 0)
        {
            // factors.push_back(i);
            khere /= i;
            mp[i]++;
        }
        else
            i++;
    }
    k0 = khere;
}
LL solve(LL nhere, LL khere)
{
    LL ans = 1e18;
    if (khere != 1) // 如果最后k还不为1，说明k为一个很大的质数，特判一下
        ans = min(ans, getnum(khere, nhere));
    for (auto it : mp) // it.first代表质因子，it.second代表质因子出现的次数
    {
        ans = min(ans, getnum(it.first, nhere) / it.second);
    }
    // cout << ans << endl;

    return ans;
}

int main()
{
    LL n, k, c;
    scanf("%lld%lld%lld", &n, &k, &c);
    foundk(k);
    LL ansM = solve(n, k0);
    LL res = 0;
    for (int i = 1; i <= c; i++)
    {
        LL m;
        scanf("%lld", &m);
        LL ans1 = solve(m, k0);
        LL ans2 = solve(n - m, k0);
        if (res < ansM - (ans1 + ans2))
            res = ansM - (ans1 + ans2);
    }
    cout << res;
    return 0;
}