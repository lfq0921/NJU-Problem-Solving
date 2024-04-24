#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e3;
int e[N][N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		e[i][j] = INF;
	for (int i = 1; i <= n; i++) e[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u][v] = min(e[u][v], w);
		e[v][u] = e[u][v]
	}
	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		printf("%d ", e[i][j]);
	return 0;
}

