#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N = 250000 + 5;
const int M = 500000 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
int h[N], h1[N], cnt;

struct node
{
	int next;
	int to;
	ll val;
}e[M], e1[M];

void addedge(int x, int y, ll z) 
{
	cnt++; 
	e[cnt].next = h[x]; 
	e[cnt].to = y; 
	e[cnt].val = z; 
	h[x] = cnt;
}
void addedge1(int x, int y, ll z) 
{
	cnt++; 
	e1[cnt].next = h1[x]; 
	e1[cnt].to = y; 
	e1[cnt].val = z; 
	h1[x] = cnt;
}
ll dis[N], dis1[N];
bool vis[N];
priority_queue<pair<ll, int> >pq;
int n, m, s;
void dij() 
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	for (int i = 0; i <= n; i++) vis[i] = false;
	pq.push(make_pair(0, s));
	while(!pq.empty()) 
	{
		pair<ll, int> now = pq.top(); pq.pop();
		int x = now.second;
		if (vis[x]) continue;
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
priority_queue<pair<ll, int> >pq1;
void dij1() 
{
	memset(dis1, 0x3f, sizeof(dis1));
	dis1[s] = 0;
	for (int i = 0; i <= n; i++) vis[i] = false;
	pq1.push(make_pair(0, s));
	while(!pq1.empty()) 
	{
		pair<ll, int> now = pq1.top(); pq1.pop();
		int x = now.second;
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = h1[x]; i; i = e1[i].next) 
		{
			int y = e1[i].to;
			if (dis1[y] > dis1[x] + e1[i].val) 
			{
				dis1[y] = dis1[x] + e1[i].val;
				pq1.push(make_pair(dis1[y] * -1, y));
			}
		}
	}
}
int main() 
{
	s = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) 
	{
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		addedge(x, y, z);
		addedge1(y, x, z);
	}
	dij();
	dij1();
	for (int i = 1; i <= n; i++) 
	if (dis[i] < inf && dis1[i] < inf)
		printf("%lld\n", dis[i] + dis1[i]);
	else printf("-1\n");
	return 0;
}
