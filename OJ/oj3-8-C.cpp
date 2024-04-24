#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> e[100005];
int rd[100005] = { 0 };
int h[100005];
vector<int> rec;
long long res[100005] = { 0 };

long long dfs(int x)
{
	if (res[x] != 0) return res[x];
	long long ans = e[x].size() % 998246353998246353;
	for (int i = 0; i < e[x].size(); i++)
	{
		ans = (ans + dfs(e[x][i])) % 998246353998246353;
	}
	res[x] = ans;
	return ans;
}

/*void topo()
{
	int ans = 0;
	memset(rd, 0, sizeof(rd));
	for (int i = 1; i <= n; i++)
	{
		int sz = e[i].size();
		for (int j = 0; j < sz; j++) rd[e[i][j]]++; 
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) if (rd[i] == 0) q.push(i);
	while (!q.empty())
	{
		int x = q.front();
		rec.push_back(x);
		q.pop();
		int sz = e[x].size();
		for (int i = 0; i < sz; i++)
		{ 
				rd[e[x][i]]--;
				if (rd[e[x][i]] == 0) q.push(e[x][i]);
		}	
	}
}*/

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &h[i]);
	}
	for (int i = 1; i <= m; i++) 
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (h[u] > h[v]) e[u].push_back(v);
		else if (h[v] > h[u]) e[v].push_back(u); 
	}
	//topo();
	long long ans = n;
	for (int i = 1; i <= n; i++) ans = (ans + dfs(i)) % 998246353998246353;
	printf("%lld", ans);
	return 0;
}
