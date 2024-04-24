#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 998244353;
int n, h[N], x1, x2, snum[N] = {0}, tnum[N] = {0};
bool s[N] = {0}, t[N] = {0};
long long realans = 0;
long long ans = 0;
struct node
{
	int next;
	int from;
	int val;
	int to;
}e[N * 2];
int cnt = 0;
void addedge(int x, int y, int z)
{
	cnt++;
	e[cnt].from = x;
	e[cnt].to = y;
	e[cnt].val = z;
	e[cnt].next = h[x];
	h[x] = cnt;
}

void dfs(int x, int prt)
{
	for (int i = h[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if (y == prt) continue;
		dfs(y, x);
		snum[x] += snum[y];//计算下子树里的s点 
		tnum[x] += tnum[y];//计算下子树里的t点 
		ans = (ans + e[i].val * (snum[y] * (x2 - tnum[y]) + tnum[y] * (x1 - snum[y]))) % MOD;
	}
	if (s[x]) snum[x]++;
	if (t[x]) tnum[x]++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);
		addedge(b, a, c);
	}
//	int x1;
	scanf("%d", &x1);
	for (int i = 1; i <= x1; i++) 
	{
		int x;
		scanf("%d", &x);
		s[x] = 1;
	}
//	int x2;
	scanf("%d", &x2);
	for (int i = 1; i <= x2; i++) 
	{
		int x;
		scanf("%d", &x);
		t[x] = 1;
	}
	dfs(1, 0);
	printf("%lld", &ans);
}
