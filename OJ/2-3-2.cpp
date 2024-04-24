#include <iostream>
#include <cstring>
#include <cmath>
#define rep(i, a, b) for (register int i = a; i < b; ++i)
using namespace std;
bool vis[1000100];
int len[1000100], a[1000100], cnt[2000000], maxc[2000000]; 
int p[200000];

int pgen(int n)
{
    p[0] = 2;
    int num = 1;
    rep(i, 3, n + 1)
    {
        int j = 0;
        bool flag = 0;
        while(p[j] <= sqrt(i))
        {
            if ((i % p[j]) == 0)
            {
                flag = 1;
                break;
            }
            ++j;
        }
        if (!flag)
        {
            p[num] = i;
            ++num;
        }
    }
    return num;
}

int main()
{
    int T;
    scanf("%d", &T);
    int maxp = 0;
    int nump = pgen(1000000);//the number of p < 1000000
    rep(t, 0, T)
    {
        int N, ind, ind0, res = 1, num = 0;
        memset(vis, 0, sizeof(vis));
        memset(len, 0, sizeof(len));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &N);
        rep(i, 1, N + 1) scanf("%d", &a[i]);
        rep(i, 1, N + 1)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                ind = i;
                ind0 = i;
                do
                {
                    ind = a[ind];
                    vis[ind] = 1;
                    ++len[num];
                } while (ind != ind0);
                ++num;//the number of circles
            }
        }
        rep(i, 0, num)//fact every length
        {
            int j = 0;
            memset(maxc, 0, sizeof(maxc));
            while (p[j] <= len[i])//p <= sqrt(len)
            {
                if ((len[i] % p[j]) == 0)
                {
                    ++maxc[j];//the number of p[i]
                    len[i] /= p[j];
                    if (maxp <= j) maxp = j + 1;
                    if (maxc[j] > cnt[j]) cnt[j] = maxc[j];//cnt[i] is the max number of p[i]
                }
                else ++j;
            }
        }
        rep(i, 0, maxp)//to the number of the largest p
        {
            res = (res * (int)pow(p[i], cnt[i])) % 998244353;
        }
        printf("%d\n", res);
    }
    return 0;
}

