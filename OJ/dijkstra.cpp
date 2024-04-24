#include<bits/stdc++.h>
using namespace std;

const long long INF = 10000000000000000ll;
const int N = 1e3;
long long dist[N];
vector <pair<int,long long>> e[N];
int n, m, s;
bool flag[N] = {0};
struct node
{
	int num, dis;
	node() {};
	node(int a, int b)
	{
		num = a, dis = b;
	}
	bool operator<(const node& a)const
	{
		return dis > a.dis;
	}
};

void Dijkstra(int st)
{
	priority_queue<node> q;
	q.push(node(st, 0));
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
	dist[st] = 0;
	while(!q.empty())
	{
		node x = q.top();
		q.pop();
		int y = x.num;
		if (flag[y]) continue;
		flag[y] = 1;
		for(int i = 0; i < e[y].size(); i++)
		{
			int z = e[y][i].first;
			long long w = e[y][i].second;
			if(!flag[z])
				if(dist[z] > dist[y] + w) 
				{
					dist[z] = dist[y] + w;
					q.push(node(z, dist[z]));
				}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; i++)
			dist[i] = INF;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		long long distan;
		scanf("%d%d%lld", &u, &v, &distan);
		e[u].push_back(make_pair(v, distan));
		
	}
	Dijkstra(s);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", dist[i]);
	}
	return 0;
}
