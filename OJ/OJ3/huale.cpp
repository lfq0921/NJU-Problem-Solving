#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 998246353;
int n, m, hi[N], rd[N];
long long ans[N], sum;
bool vis[N];
stack <int> q;

int h[N], cnt;
struct node{
	int next;
	int from;
	int to;
}e[N];

void addedge(int x, int y)
{
	cnt++;
	e[cnt].next = h[x];
	e[cnt].from = x;
	e[cnt].to = y;
	h[x] = cnt;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1 ; i <= n ; i++) scanf("%d", &hi[i]);
	for (int i = 1 ; i <= m ; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(hi[y] < hi[x])
			{
				addedge(x, y);
				rd[y]++;
			}
			if(hi[x] < hi[y])
			{
				addedge(y, x);
				rd[x]++;
			}
		}
	
	for (int i = 1 ; i <= n ; i++)
		{
			ans[i] = 1;
			if(rd[i] == 0) q.push(i);
		}
	while(!q.empty())
	{
		int x = q.top();
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		sum = (ans[x] + sum) % MOD;
		for (int i = h[x] ; i; i = e[i].next)
		{
			int y = e[i].to;
			if(vis[y]) continue;
			rd[y]--;
			ans[y] = (ans[x] + ans[y]) % MOD;
			if(rd[y] == 0) q.push(y);
		}
	}
	printf("%lld", sum);
	return 0;
 } 
