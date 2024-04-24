#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int M = 2e6;
int n, m;
int dp[N + 5];
int cnt = 0, ans = 0;
struct connection
{
	int a;
	int b;
	int v;
}c[M + 5];

bool cmp(connection p, connection q)
	{
		return p.v < q.v;
	}
	
int find(int x)
{
	while (x != dp[x]) x = dp[x];
	return x;
}
	
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		dp[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &c[i].a, &c[i].b, &c[i].v);
	sort (c + 1, c + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int px = find(c[i].a);
		int py = find(c[i].b);
		bool add = false;
		if (px != py)
		{
			dp[px] = py;
			ans += c[i].v;
			add = true;
		}
		if (!add && c[i].v < 0) ans += c[i].v;
	}
	bool ok = true;
	int stone = find(1);
	for (int i = 2; i <= n; i++)
	{
	    if (stone != find(i))
	    {
	        ok = 0;
	        break;
	    }
	}
	if (ok) cout << ans;
	else cout << "bad idea";
	return 0;
}
