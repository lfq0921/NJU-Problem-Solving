#include<bits/stdc++.h>
using namespace std;
const int N = 250005;
int n, m;
vector <pair<int, int>> e[N], e1[N];
int dis[N], dis1[N];
long long sum_dis[N] = { 0 };
bool vis[N] = { 0 }, get1[N] = { 0 }, get2[N] = { 0 };
void dij(int s)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	dis[s] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, s));
	while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = 0; i < e[x].size(); i++)
        {
            int y = e[x][i].first;
            int w = e[x][i].second;
            if(!vis[y] && dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(make_pair(-dis[y], y));
                sum_dis[y] = dis[y];
                get1[y] = 1;
            }
        }
    }
	return;
}
void dij1(int s)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) dis1[i] = INT_MAX;
	dis1[s] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, s));
	while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = 0; i < e1[x].size(); i++)
        {
            int y = e1[x][i].first;
            int w = e1[x][i].second;
            if(!vis[y] && dis1[y] > dis1[x] + w)
            {
                dis1[y] = dis1[x] + w;
                q.push(make_pair(-dis1[y], y));
                sum_dis[y] += dis1[y];
                get2[y] = 1;
            }
        }
    }
	return;
}
int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		e[x].push_back(make_pair(y, z));
		e1[y].push_back(make_pair(x, z));
	}
	for (int i = 1; i <= n; i++) sum_dis[i] = INT_MAX;//初始化总路程
	dij(1);
	dij1(1);
	sum_dis[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if(get1[i] && get2[i]) printf("%lld\n", sum_dis[i]);
		else printf("-1\n");
	}
	
	return 0;
}
