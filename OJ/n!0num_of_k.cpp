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

// const LL N = 1e12 + 100;

// bool book[N];

// LL pri[N];

// LL cnt = 0;

unordered_map<LL, LL> mp;

/*void P() // 欧拉筛 求出N以内的所有素数
{
    for (LL i = 2; i < N; i++)
    {
        if (!book[i]) // book=0,代表是素数
            pri[cnt++] = i;
        for (LL j = 0; j < cnt && pri[j] * i < N; j++)
        {
            book[pri[j] * i] = true;
            if (i % pri[j] == 0)
                break;
        }
    }
}*/

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

LL solve(LL nhere, LL khere)
{
    /*for (LL i = 0; i < cnt && pri[i] <= sqrt(double(khere)); i++) // 对k唯一分解
    {
        while (khere % pri[i] == 0)
        {
            khere /= pri[i];
            mp[pri[i]]++; // mp维护每个质因子出现的次数
        }
        if (khere == 1)
            break;
    }*/
    int i = 2;
    while (khere > 1)
    {
        cout << "khere = " << khere << endl;
        if (khere % i == 0)
        {
            // factors.push_back(i);
            khere /= i;
            mp[i]++;
        }
        else
            i++;
    }
    LL ans = 1e18;
    if (khere != 1) // 如果最后k还不为1，说明k为一个很大的质数，特判一下
        ans = min(ans, getnum(khere, nhere));
    for (auto it : mp) // it.first代表质因子，it.second代表质因子出现的次数
    {
        ans = min(ans, getnum(it.first, nhere) / it.second);
    }
    cout << ans << endl;

    return ans;
}

int main()
{
    // P();
    LL n, k, c;
    scanf("%lld%lld%lld", &n, &k, &c);
    LL ansM = solve(n, k);
    LL res = 0;
    for (LL i = 1; i <= c; i++)
    {
        LL m;
        scanf("%lld", &m);
        LL ans1 = solve(m, k);
        printf("ans1 = %lld\n", ans1);
        LL ans2 = solve(n - m, k);
        printf("ans2=%lld\n", ans2);
        if (res < ansM - (ans1 + ans2))
            res = ansM - (ans1 + ans2);
    }
    printf("%lld", res);
    return 0;
}