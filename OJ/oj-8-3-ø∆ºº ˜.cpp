#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N_MAX = 1e6 + 5;
const int M_MAX = 2e6 + 5;
const int T_MAX = 1e9 + 5;
int n, m;
int cnt = 0;
queue<int> q;
vector<int> G[N_MAX]; 
long long Time = 0;
struct node
{
	long long t;
	int pre;
	long long get_t;
}teq[N_MAX];

bool topo_sort(int n)
{
	for (int i = 1; i <= n; i++)
	if (teq[i].pre == 0 && teq[i].t != -1) q.push(i), teq[i].get_t = teq[i].t;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < G[u].size(); i++)
		{
			teq[G[u][i]].pre--;
			if (teq[G[u][i]].pre == 0) q.push(G[u][i]);
			teq[G[u][i]].get_t = max(teq[G[u][i]].get_t, teq[u].get_t + teq[G[u][i]].t);
			Time = max(Time, teq[G[u][i]].get_t);	
		}
	}
	if (cnt == n) return 1;
		else return 0;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> teq[i].t;
		teq[i].pre = 0;
		if (teq[i].t == -1) cnt++;
		Time = max(teq[i].t, Time);
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (teq[u].t != -1 && teq[v].t != -1)
		{
			teq[u].pre++;
			G[v].push_back(u);
		}
	}
	if (!topo_sort(n)) cout << "bad idea" << endl;
	else cout << Time << endl; 
	return 0;
}
