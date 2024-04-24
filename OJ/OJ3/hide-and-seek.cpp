#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, t[N], h[N];
bool Get[N] = {0};
int ti = 0;
long long sum = 0;

const int mod = 998244353;
long long quick_pow(long long a, long long b)
{
   long long ans = 1;
   while (b)
  {
       if (b & 1)
           ans = ans * a % mod;
       a = a * a % mod;
       b = b >> 1;
  }
   return ans;
}

struct node{
	int next;
	int from;
	int to;
}e[N * 2];

int cnt = 0;
void addedge(int x, int y)
{
	cnt++;
	e[cnt].next = h[x];
	e[cnt].from = x;
	e[cnt].to = y;
	h[x] = cnt;
}

void dfs(int x, int prt)
{
	for (int  i = h[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if (y == prt) continue;
		ti++;
		if (Get[y]) t[y] = min(t[y], ti);
		else t[y] = ti, Get[y] = 1;
		dfs(y, x);
		ti++;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) sum += t[i];
	//printf("sum = %lld\n", sum);
	sum = sum * quick_pow(n - 1, mod - 2) % mod;
	printf("%lld", sum);
	return 0;
}
