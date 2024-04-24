#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int dist[N];
bool vis[N];
struct node
{
	int id;
	int x;
	int y;
}no[N];
vector<pair<int, int>> e[N];
bool cmpx(node a, node b)
{
	return a.x < b.x;
}
bool cmpy(node a, node b)
{
	return a.y < b.y;
}
/*bool cmpid(node a, node b)
{
	return a.id < b.id;
}*/
int dis (node a, node b)
{
	int dx = abs(a.x - b.x);
	int dy = abs(a.y - b.y);
	return min(dx, dy);
}
void dij(int s)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
	dist[s] = 0;
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
            if(dist[y] > dist[x] + w)
            {
                dist[y] = dist[x] + w;
                q.push(make_pair(-dist[y], y));
            }
        }
    }
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		no[i].id = i;
		scanf("%d%d", &no[i].x, &no[i].y);
	}
	sort(no + 1, no + n + 1, cmpx);
	for (int i = 1; i < n; i++)
	{
		int u = no[i].id;
		int v = no[i + 1].id;
		int w = dis(no[i], no[i + 1]);
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	sort(no + 1, no + n + 1, cmpy);
	for (int i = 1; i <= n; i++)
	{
		int u = no[i].id;
		int v = no[i + 1].id;
		int w = dis(no[i], no[i + 1]);
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	//sort(no + 1, no + n + 1, cmpid);
	dij(1);
	for (int i = 1; i <= n; i++)
	printf("%d\n", dist[i]);
	return 0;
}
