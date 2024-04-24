#include<bits/stdc++.h>
using namespace std;
int n, m, k;
double p[100005];
struct node
{
	vector<int> pre;
	int nxtnum;
}no[100005];
double walk(int pos)
{
	if (p[pos] != -1) return p[pos];
	p[pos] = 0;
	for (int i = 1; i <= no[pos].pre.size(); i++)
	{
		int prev = no[pos].pre[i - 1];
		p[pos] += walk(prev) / no[prev].nxtnum;
	}
	return p[pos];
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++)
	{
		no[i].nxtnum = 0;
		p[i] = -1;
	}
		
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		no[u].nxtnum++;
		no[v].pre.push_back(u);
		//e[u].next[++e[u].num] = v;
	}
	p[0] = 1;
	while(k--)
	{
		int idx;
		scanf("%d", &idx);
		printf("%.10f\n", walk(idx));
	}
	return 0;
}
