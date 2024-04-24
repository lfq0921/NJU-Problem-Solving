#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1000000 + 5;
const int M = 1000000 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
int h[N], cnt;
int T;
bool choose[N] = {0};
struct node
{
    int next;
    int to;
    ll val;
} e[M];
void addedge(int x, int y, ll z)
{
    cnt++;
    e[cnt].next = h[x];
    e[cnt].to = y;
    e[cnt].val = z;
    h[x] = cnt;
}
ll dis[N];
bool vis[N];
priority_queue<pair<ll, int>> pq;
int n, m, k, s;
ll ans = inf;
void dij()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        pair<ll, int> now = pq.top();
        pq.pop();
        int x = now.second;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = h[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].val)
            {
                dis[y] = dis[x] + e[i].val;
                pq.push(make_pair(dis[y] * -1, y));
            }
        }
    }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            ll z;
            scanf("%d%d%lld", &x, &y, &z);
            addedge(x, y, z);
        }
        for (int i = 1; i <= k; i++) // 选择k个要去的城市
        {
            int x;
            scanf("%d", &x);
            choose[x] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (choose[i])
            {
                s = i;
                dij();
                for (int j = 1; j <= n; j++)
                {
                    // printf("dis[%d][%d] = %lld\n", i, j, dis[j]);
                    if (choose[j] && dis[j] < ans && j != i)
                        ans = dis[j];
                }
            }
        }
        printf("%lld\n", ans);
        for (int i = 0; i <= n; i++)
        {
            choose[i] = 0;
            ans = inf;
        }
        cnt = 0;
        for (int i = 0; i <= m; i++)
        {
            h[i] = 0;
            e[i].next = 0;
            e[i].to = 0;
            e[i].val = 0;
        }
    }
    return 0;
}