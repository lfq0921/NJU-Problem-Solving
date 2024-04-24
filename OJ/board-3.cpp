#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 500 + 5;  //
const int M = 2500 + 5; //
const ll inf = 0x3f3f3f3f3f3f3f3fll;
bool flag[N][N] = {0};

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

vector<int> e[N]; // edge connected with vertex-N
void addedge(int x, int y)
{
    e[x].push_back(y);
    e[y].push_back(x);
}

ll dis[N];
bool vis[N];
priority_queue<pair<ll, int>> pq;
int n, m;
void dij(int s)
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
        int x = now.second; // which vertex
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = 0; i < e[x].size(); i++)
        {
            int y = e[x][i];
            if (dis[y] > dis[x] + 1)
            {
                dis[y] = dis[x] + 1;
                pq.push(make_pair(dis[y] * -1, y));
            }
        }
    }
}
/*floyd*/
const int INF = 0x3f3f3f3f; // 定义正无穷
// 图的邻接矩阵表示法，dist[i][j]表示i到j的最短距离
// n为图的节点数，可以根据实际情况修改
int dist[N][N], n;

void floyd()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

/*Bellman-Ford 负权边*/
const int INF = 0x3f3f3f3f; // 定义正无穷
// 图的邻接矩阵表示法，dist[i][j]表示i到j的最短距离
// n为图的节点数，可以根据实际情况修改
int dist[N], n;
struct Edge
{
    int u, v, w;
} edges[M];

void bellman_ford(int s)
{
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }
    dist[s] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

/*全源最短路 johnson*/
#include <cstring>
#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
struct edge
{
    int v, w, next;
} e[10005];
struct node
{
    int dis, id;
    bool operator<(const node &a) const { return dis > a.dis; }
    node(int d, int x) { dis = d, id = x; }
};
int head[5005], vis[5005], t[5005];
int cnt, n, m;
long long h[5005], dis[5005];
void addedge(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
bool spfa(int s)
{
    queue<int> q;
    memset(h, 63, sizeof(h));
    h[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (h[v] > h[u] + e[i].w)
            {
                h[v] = h[u] + e[i].w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    t[v]++;
                    if (t[v] == n + 1)
                        return false;
                }
            }
        }
    }
    return true;
}
void dijkstra(int s)
{
    priority_queue<node> q;
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    q.push(node(0, s));
    while (!q.empty())
    {
        int u = q.top().id;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v])
                    q.push(node(dis[v], v));
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    for (int i = 1; i <= n; i++)
        addedge(0, i, 0);
    if (!spfa(0))
    {
        cout << -1 << endl;
        return 0;
    }
    for (int u = 1; u <= n; u++)
        for (int i = head[u]; i; i = e[i].next)
            e[i].w += h[u] - h[e[i].v];
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        long long ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] == INF)
                ans += j * INF;
            else
                ans += j * (dis[j] + h[j] - h[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

/*最大流EK*/
#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, u, v;
long long w, ans, dis[520010];
int tot = 1, vis[520010], pre[520010], head[520010], flag[2510][2510];

struct node
{
    int to, net;
    long long val;
} e[520010];

inline void add(int u, int v, long long w)
{
    e[++tot].to = v;
    e[tot].val = w;
    e[tot].net = head[u];
    head[u] = tot;
    e[++tot].to = u;
    e[tot].val = 0;
    e[tot].net = head[v];
    head[v] = tot;
}

inline int bfs()
{ // bfs寻找增广路
    for (register int i = 1; i <= n; i++)
        vis[i] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 2005020600;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (register int i = head[x]; i; i = e[i].net)
        {
            if (e[i].val == 0)
                continue; // 我们只关心剩余流量>0的边
            int v = e[i].to;
            if (vis[v] == 1)
                continue; // 这一条增广路没有访问过
            dis[v] = min(dis[x], e[i].val);
            pre[v] = i; // 记录前驱，方便修改边权
            q.push(v);
            vis[v] = 1;
            if (v == t)
                return 1; // 找到了一条增广路
        }
    }
    return 0;
}

inline void update()
{ // 更新所经过边的正向边权以及反向边权
    int x = t;
    while (x != s)
    {
        int v = pre[x];
        e[v].val -= dis[t];
        e[v ^ 1].val += dis[t];
        x = e[v ^ 1].to;
    }
    ans += dis[t]; // 累加每一条增广路经的最小流量值
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (register int i = 1; i <= m; i++)
    {
        scanf("%d%d%lld", &u, &v, &w);
        if (flag[u][v] == 0)
        { // 处理重边的操作（加上这个模板题就可以用Ek算法过了）
            add(u, v, w);
            flag[u][v] = tot;
        }
        else
        {
            e[flag[u][v] - 1].val += w;
        }
    }
    while (bfs() != 0)
    { // 直到网络中不存在增广路
        update();
    }
    printf("%lld", ans);
    return 0;
}

/*Dicnic*/
#include <bits/stdc++.h>
using namespace std;
const long long inf = 2005020600;
int n, m, s, t, u, v;
long long w, ans, dis[520010];
int tot = 1, now[520010], head[520010];

struct node
{
    int to, net;
    long long val;
} e[520010];

inline void add(int u, int v, long long w)
{
    e[++tot].to = v;
    e[tot].val = w;
    e[tot].net = head[u];
    head[u] = tot;

    e[++tot].to = u;
    e[tot].val = 0;
    e[tot].net = head[v];
    head[v] = tot;
}

inline int bfs()
{ // 在惨量网络中构造分层图
    for (register int i = 1; i <= n; i++)
        dis[i] = inf;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = head[s];
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (register int i = head[x]; i; i = e[i].net)
        {
            int v = e[i].to;
            if (e[i].val > 0 && dis[v] == inf)
            {
                q.push(v);
                now[v] = head[v];
                dis[v] = dis[x] + 1;
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}

inline int dfs(int x, long long sum)
{ // sum是整条增广路对最大流的贡献
    if (x == t)
        return sum;
    long long k, res = 0; // k是当前最小的剩余容量
    for (register int i = now[x]; i && sum; i = e[i].net)
    {
        now[x] = i; // 当前弧优化
        int v = e[i].to;
        if (e[i].val > 0 && (dis[v] == dis[x] + 1))
        {
            k = dfs(v, min(sum, e[i].val));
            if (k == 0)
                dis[v] = inf; // 剪枝，去掉增广完毕的点
            e[i].val -= k;
            e[i ^ 1].val += k;
            res += k; // res表示经过该点的所有流量和（相当于流出的总量）
            sum -= k; // sum表示经过该点的剩余流量
        }
    }
    return res;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (register int i = 1; i <= m; i++)
    {
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
    }
    while (bfs())
    {
        ans += dfs(s, inf); // 流量守恒（流入=流出）
    }
    printf("%lld", ans);
    return 0;
}

/*vector实现dicnic*/
/*那么 vector 怎么找反向边呢？

我们知道，一条反向边的起点是 st，终点是 ed 的话，按照常规储存方法，我们是这样存图的：

struct edge
{
    int ed, len;
}
vector <edge> e[N];
此时我们发现，如果想要找到反向边的话，必须要遍历一遍 e[ed] 数组，这样做的最坏复杂度是

那么我们如何快速找到反向边呢？

我们不难想到，如果我们记录下反向边的存储位置为 id，那么我们寻找反向边的时候只需要访问 e[ed][id] 就可以了，大大节约了我们的时间。

那么这个 id 的值应该是多少呢？

显然，当我们新加入一条边之前，e[ed] 数组里存的数的个数为 e[ed].size()，它们的下标从 0 到 e[ed].size() - 1，那么新存进来的数的下标一定就是 e[ed].size()，所以 id 直接设为 e[ed].size() 即可。

代码实现：

struct edge	{int ed, len, id;};
vector <edge> e[N];
加边：

    while (m -- )
    {
        int st, ed, len;
        scanf("%lld%lld%lld", &st, &ed, &len);
        int sti = e[st].size();
        int edi = e[ed].size();
        e[st].push_back((edge){ed, len, edi});
        e[ed].push_back((edge){st, 0, sti});
    }
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10010, M = 200010, INF = 1e15;

struct edge
{
    int ed;
    int len;
    int id;
};

vector<edge> e[N];

int n, m, S, T;
int dep[N], cur[N];

bool bfs()
{
    memset(dep, -1, sizeof dep);
    queue<int> q;
    q.push(S);
    dep[S] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < e[t].size(); i = i + 1)
        {
            int ed = e[t][i].ed;
            if (dep[ed] == -1 && e[t][i].len)
            {
                dep[ed] = dep[t] + 1;
                q.push(ed);
            }
        }
    }
    memset(cur, 0, sizeof(cur));
    return (dep[T] != -1);
}

int dfs(int st, int limit)
{
    if (st == T)
        return limit;
    for (int i = cur[st]; i < e[st].size(); i = i + 1)
    {
        cur[st] = i; // 当前弧优化
        int ed = e[st][i].ed;
        if (dep[ed] == dep[st] + 1 && e[st][i].len)
        {
            int t = dfs(ed, min(e[st][i].len, limit));
            if (t)
            {
                e[st][i].len -= t;
                e[ed][e[st][i].id].len += t;
                return t;
            }
            else
                dep[ed] = -1;
        }
    }
    return 0;
}

int dinic()
{
    int r = 0, flow;
    while (bfs())
        while (flow = dfs(S, INF))
            r += flow;
    return r;
}

signed main()
{
    cin >> n >> m >> S >> T;
    while (m--)
    {
        int st, ed, len;
        cin >> st >> ed >> len;
        int sti = e[st].size();
        int edi = e[ed].size();
        e[st].push_back((edge){ed, len, edi});
        e[ed].push_back((edge){st, 0, sti});
    }
    cout << dinic();

    return 0;
}

/*最小费用最大流 SPFA*/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 5001;
const int MAXM = 50001;
int n, m, s, t, edge_sum = 1;
int maxflow, mincost;
int dis[MAXN], head[MAXN], incf[MAXN], pre[MAXN]; // dis表示最短路，incf表示当前增广路上最小流量，pre表示前驱
bool vis[MAXN];
struct Edge
{
    int next, to, dis, flow;
} edge[MAXM << 1];
inline void addedge(int from, int to, int flow, int dis)
{
    edge[++edge_sum].next = head[from];
    edge[edge_sum].to = to;
    edge[edge_sum].dis = dis;
    edge[edge_sum].flow = flow;
    head[from] = edge_sum;
}
inline bool spfa()
{ // 关于SPFA，他诈尸了
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    incf[s] = 1 << 30;
    while (!q.empty())
    {
        int u = q.front();
        vis[u] = 0;
        q.pop();
        for (register int i = head[u]; i; i = edge[i].next)
        {
            if (!edge[i].flow)
                continue; // 没有剩余流量
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                incf[v] = min(incf[u], edge[i].flow); // 更新incf
                pre[v] = i;
                if (!vis[v])
                    vis[v] = 1, q.push(v);
            }
        }
    }
    if (dis[t] == 1061109567)
        return 0;
    return 1;
}
inline void MCMF()
{
    while (spfa())
    { // 如果有增广路
        int x = t;
        maxflow += incf[t];
        mincost += dis[t] * incf[t];
        int i;
        while (x != s)
        { // 遍历这条增广路，正向边减流反向边加流
            i = pre[x];
            edge[i].flow -= incf[t];
            edge[i ^ 1].flow += incf[t];
            x = edge[i ^ 1].to;
        }
    }
}
signed main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (register int u, v, w, x, i = 1; i <= m; ++i)
    {
        scanf("%d%d%d%d", &u, &v, &w, &x);
        addedge(u, v, w, x);
        addedge(v, u, 0, -x); // 反向边费用为-f[i]
    }
    MCMF(); // 最小费用最大流
    printf("%d %d\n", maxflow, mincost);
    return 0;
}

/*最小费用最大流EK*/
/*每一条边增加一个参数：每个单位流量的费用；求解在最大流的情况下最小的费用。
【主要思路】
EK算法，即SPFA+增广路
在图上 以费用为边权 跑SPFA：在更新的过程中，如果更新成功，那么顺便进行往下一个结点尽可能多地流水，并且把流水的路径记录下来（pre[v]=u->v的边）。
跑完SPFA后，顺着之前记录的路径从汇点溯回到源点，并且进行增广路。
最小的总费用就是累计 (当前路径所流总量) x (s到t的最短路径)
【参考程序】*/
#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
int cur = 1, n, m, s, t, mcost, mflow;
int head[5005], dis[5005], flow[5005], pre[5005];
struct EDGE
{
    int t, next, w, f;
} e[100005];
void add(int a, int b, int w, int f)
{
    cur++;
    e[cur].t = b;
    e[cur].next = head[a];
    e[cur].w = w;
    e[cur].f = f;
    head[a] = cur;
    cur++;
    e[cur].t = a;
    e[cur].next = head[b];
    e[cur].w = 0;
    e[cur].f = -f;
    head[b] = cur;
}

queue<int> q;
bool vis[5005];
bool SPFA(int s, int t)
{
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    vis[s] = 1;
    flow[s] = INF;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int h = head[u]; h != -1; h = e[h].next)
        {
            int v = e[h].t, f = e[h].f;
            if (e[h].w && dis[u] + f < dis[v]) // 如果边还有流量就尝试更新
            {
                dis[v] = dis[u] + f;            // 更新最短路径
                flow[v] = min(flow[u], e[h].w); // 尽可能地流水
                pre[v] = h;                     // 记录路径
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dis[t] != INF;
}

void Update(int s, int t)
{
    int x = t;
    while (x != s)
    {
        int i = pre[x];
        e[i].w -= flow[t];
        e[i ^ 1].w += flow[t];
        x = e[i ^ 1].t;
    } // 沿着记录下的路径并进行增广路
    mflow += flow[t];
    mcost += flow[t] * dis[t]; // 累计费用
}
void E_K(int s, int t)
{
    while (SPFA(s, t)) // 当还有多余流量时
        Update(s, t);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(head, -1, sizeof head);
    for (int i = 1; i <= m; i++)
    {
        int a, b, w, f;
        scanf("%d%d%d%d", &a, &b, &w, &f);
        add(a, b, w, f);
    }
    E_K(s, t);
    printf("%d %d\n", mflow, mcost);
    return 0;
}

/*Kruskal*/
const int MAXN = 1e6 + 6;
int n, m, cnt, ans;
int fa[MAXN];

struct Edge
{
    int u, v, w;
} edge[MAXN];

inline int find(int x) // 并查集
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline int cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

inline void kruskal()
{
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if (find(u) == find(v))
            continue;
        ans += w;
        fa[find(v)] = find(u);
        if (++cnt == n - 1)
            break;
    }
}

/*匹配 随机*/
int ans;
int n, m;
int vis[N];
int match[N];

clock_t st;

mt19937 g_f;

il db now_time()
{
    return (double)(clock() - st) / CLOCKS_PER_SEC;
}
int do_match(int x, mt19937 g_f)
{
    cout << x << ' ';
    shuffle(E[x].begin(), E[x].end(), g_f);
    vis[x] = 1;
    for (auto y : E[x])
        if (!match[y])
            return vis[y] = 1, match[y] = x, match[x] = y, 1;
    for (auto y : E[x])
    {
        int z = match[y];
        if (vis[z])
            continue;
        match[x] = y, match[y] = x, match[z] = 0;
        if (do_match(z, g_f))
            return 1;
        match[y] = z, match[z] = y, match[x] = 0;
    }
    return 0;
}

/*匹配 带花树算法*/
void aug(int v) // 从v点开始修改増广路
{
    int t;
    while (v)
    {
        t = match[pre[v]]; // 临时记录下一次的v
        match[v] = pre[v];
        match[pre[v]] = v;
        v = t;
    }
}
int cnt, vis[MAXN];
int lca(int u, int v) // 寻找两个节点的总花根
{
    ++cnt;         // 每次lca选用不同的cnt作为判断条件
    u = get_fa(u); // 保证操作对象时刻为分花根
    v = get_fa(v);
    while (vis[u] != cnt) // 某一点同时两次被染色，即为总花根
    {
        vis[u] = cnt;
        u = get_fa(pre[match[u]]); // 保证操作对象时刻为分花根
        if (v)
            swap(u, v); // 切换操作对象
    }
    return u;
}
void shrink(int u, int v, int r) // 以r为总花根，将花缩成花根一点，并建立内部的反向pre
{
    while (get_fa(u) != r) // 当已达到总花根，说明缩花任务完成
    {
        // 每次循环起初的v为上个匹配的v
        pre[u] = v; // 建立反向pre，保证増广路
        v = match[u];
        if (col[v] == 2)
        {
            col[v] = 1;
            q.push(v);
        } // 花内所有v，都应以u身份向外増广
        if (get_fa(u) == u)
            fa[u] = r; // 如果某一点为分花根，将其合并到总花根上
        if (get_fa(v) == v)
            fa[v] = r;
        u = pre[v]; // 切换操作对象
    }
}

/*二分图最大匹配 匈牙利算法*/
#include <cstdio>
#include <vector>

const int maxn = 1005;

int n, m, t;
int mch[maxn], vistime[maxn];

std::vector<int> e[maxn];

bool dfs(const int u, const int tag);

int main()
{
    scanf("%d %d %d", &n, &m, &t);
    for (int u, v; t; --t)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dfs(i, i))
        {
            ++ans;
        }
    printf("%d\n", ans);
}

bool dfs(const int u, const int tag)
{
    if (vistime[u] == tag)
        return false;
    vistime[u] = tag;
    for (auto v : e[u])
        if ((mch[v] == 0) || dfs(mch[v], tag))
        {
            mch[v] = u;
            return true;
        }
    return false;
}

/*二分图最大匹配 dicnic算法*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int cnt = 2;
int alist[6000001];
struct data
{
    int v;
    int next;
    int value;
} edge[6000001];
void add(int u, int v, int value)
{
    edge[cnt].v = v;
    edge[cnt].value = value;
    edge[cnt].next = alist[u];
    alist[u] = cnt++;
    return;
}
int h[1000001];
int q[1000001];
// dicnic暴力参见上面提到的博客。
bool bfs()
{
    int x, next;
    memset(h, -1, sizeof(h));
    int head = 0, tail = 1;
    q[head] = 1;
    h[1] = 0;
    while (head < tail)
    {
        x = q[head++];
        next = alist[x];
        while (next)
        {
            int v = edge[next].v;
            int value = edge[next].value;
            if (value && h[v] < 0)
            {
                q[tail++] = v;
                h[v] = h[x] + 1;
            }
            next = edge[next].next;
        }
    }
    //    for(int i=1;i<=n*m;i++) printf("h[%d]=%d\n",i,h[i]);
    if (h[n] == -1)
        return false;
    return true;
}
int ans;
int dfs(int x, int y)
{
    if (x == n)
        return y;
    int next = alist[x];
    int w, used = 0;
    while (next)
    {
        int v = edge[next].v;
        int value = edge[next].value;
        if (value && h[v] == h[x] + 1)
        {
            w = y - used;
            w = dfs(v, min(w, value));
            edge[next].value -= w;
            edge[next ^ 1].value += w;
            used += w;
            if (used == y)
                return y;
        }
        next = edge[next].next;
    }
    if (!used)
        h[x] = -1;
    return used;
}
void dinic()
{
    while (bfs())
        ans += dfs(1, 0x7fffffff);
}
int n1, m1, e1;
int main()
{
    //   freopen("testdata.in","r",stdin);
    // 第一遍没A就是因为忘了删上面这句话。。。
    scanf("%d%d%d", &n1, &m1, &e1);
    n = n1 + m1 + 2;
    for (int i = 1; i <= n1; i++)
    {
        add(1, i + 1, 1);
        add(i + 1, 1, 1);
    }
    for (int i = 1; i <= e1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u <= n1 && v <= m1)
            add(u + 1, v + n1 + 1, 1),
                add(v + n1 + 1, u + 1, 1);
    }
    for (int i = 1; i <= m1; i++)
    {
        add(i + n1 + 1, n, 1);
        add(n, i + n1 + 1, 1);
    }
    dinic(); // 暴力跑最大流
    printf("%d", ans);
    return 0; // 程序拜拜
}

int main()
{
    random_device seed;
    mt19937 g_f(seed());
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= m; ++i)
        x = qr(), y = qr(), add_e(x, y);
    st = clock();
    while (now_time() < 0.85)
    {
        for (int i = 1; i <= n; ++i)
            if (!match[i])
                fill(vis + 1, vis + n + 1, 0), ans += do_match(i, g_f), puts("");
    }
    cout << ans << '\n';
    return debug(match, 1, n), 0;
}

/*二分图的最大权完美匹配*/
const int MAXN = 510;

int n, m;
int e[MAXN][MAXN];

int lx[MAXN], ly[MAXN], slack[MAXN];
int px[MAXN], py[MAXN], pre[MAXN];
bool vx[MAXN], vy[MAXN];

queue<int> q;
void aug(int v)
{
    int t;
    while (v)
    {
        t = px[pre[v]];
        px[pre[v]] = v;
        py[v] = pre[v];
        v = t;
    }
}
void bfs(int s)
{
    memset(vx, 0, sizeof(vx));
    memset(vy, 0, sizeof(vy));
    fill(slack + 1, slack + n + 1, inf);

    while (!q.empty())
        q.pop();
    q.push(s);

    while (1)
    {
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vx[u] = 1;
            for (int i = 1; i <= n; ++i)
                if (!vy[i])
                {
                    if (lx[u] + ly[i] - e[u][i] < slack[i])
                    {
                        slack[i] = lx[u] + ly[i] - e[u][i];
                        pre[i] = u;
                        if (slack[i] == 0)
                        {
                            vy[i] = 1;
                            if (!py[i])
                            {
                                aug(i);
                                return;
                            }
                            else
                                q.push(py[i]);
                        }
                    }
                }
        }
        int d = inf;
        for (int i = 1; i <= n; ++i)
            if (!vy[i])
                d = min(d, slack[i]);
        for (int i = 1; i <= n; ++i)
        {
            if (vx[i])
                lx[i] -= d;
            if (vy[i])
                ly[i] += d;
            else
                slack[i] -= d;
        }
        for (int i = 1; i <= n; ++i)
            if (!vy[i])
            {
                if (slack[i] == 0)
                {
                    vy[i] = 1;
                    if (!py[i])
                    {
                        aug(i);
                        return;
                    }
                    else
                        q.push(py[i]);
                }
            }
    }
}

int main()
{
    for (int i = 1; i <= n; ++i)
        bfs(i);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    kruskal();
    printf("%d", ans);
    return 0;
}
