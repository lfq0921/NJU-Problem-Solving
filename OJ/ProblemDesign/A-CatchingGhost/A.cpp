#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 3000 + 5;
const ll M = 1e10;
struct Edge
{
    int from;
    int to;
    ll value;
};
Edge edge[maxn] = {};
int n, u, v;
vector<pair<int, ll>> e[maxn] = {};
//记录每个点为根出发最大路径 次大路径 最大路径的来源，每个点的从父节点得到的最长路径
ll max1[maxn] = {0}, max2[maxn] = {0}, fr[maxn]{0}, d[maxn] = {0}, p, c, dis = 0, dis2 = M, old_dis = 0, ans = M;
void dp1(int x, int fa)
{
    max1[x] = 0, max2[x] = 0, fr[x] = x, d[x] = 0;
    for (auto it = e[x].begin(); it != e[x].end(); it++)
    {
        if (it->first == fa)
            continue;
        int tmp = it->first;
        ll tmp_v = it->second;
        dp1(tmp, x);
        if (max1[tmp] + tmp_v > max1[x])
        { //更新最长子路和子路来源
            max2[x] = max1[x];
            max1[x] = max1[tmp] + tmp_v;
            fr[x] = tmp;
        }
        else if (max1[tmp] + tmp_v > max2[x])
        { //更新次长子路
            max2[x] = max1[tmp] + tmp_v;
        }
    }
    //更新最长距离
    dis = max(dis, max2[x] + max1[x]);
}
void findway(int x, int fa)
{ //找半径
    for (auto it = e[x].begin(); it != e[x].end(); it++)
    {
        if (it->first == fa)
            continue;
        int tmp = it->first;
        ll tmp_v = it->second, fa_to;
        if (tmp == fr[x])
        {
            fa_to = max2[x];
        }
        else
        {
            fa_to = max1[x];
        }
        d[tmp] = max(d[x] + tmp_v, fa_to + tmp_v);
        findway(tmp, x);
    }
    ll maxway = max(max1[x], d[x]);
    dis2 = min(dis2, maxway);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%lld", &u, &v, &p);
        e[u].push_back(make_pair(v, p));
        e[v].push_back(make_pair(u, p));
        edge[i].from = u, edge[i].to = v, edge[i].value = p;
    }
    scanf("%lld", &c);
    dp1(1, 0); //原先直径
    old_dis = dis;
    for (int i = 1; i < n; i++)
    {
        dis = 0;
        dp1(edge[i].from, edge[i].to);
        ll f1 = dis;
        dis = 0;
        dp1(edge[i].to, edge[i].from);
        ll f2 = dis;
        dis2 = M;
        findway(edge[i].from, edge[i].to);
        ll f3 = dis2;
        dis2 = M;
        findway(edge[i].to, edge[i].from);
        ll f4 = dis2;
        ans = min(max(f3 + f4 + c, max(f1, f2)), ans);
    }
    if (old_dis > ans)
    {
        printf("yes\n");
        printf("%lld", ans);
    }
    else
    {
        printf("no\n");
    }
    return 0;
}