#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 
#define MAXN 6005
int h[N];
int v[N];
vector<int> son[N];
int f[N][2];
void dp(int x)
{
	f[x][0] = 0;
	f[x][1] = h[x];
	for(int i = 0; i < son[x].size(); i++)
	{
		int y = son[x][i];
		dp(y);
		f[x][0] += max(f[y][0],f[y][1]);
		f[x][1] += f[y][0];
	}
}
int main()
{
 int n;
 scanf("%d", &n);
 for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
 for(int i = 1; i <= n - 1; i++)
 {
  int x, y;
  scanf("%d%d", &x, &y);
  son[y].push_back(x);
  v[x] = 1;
 }
 int r;
 for(int i = 1; i <= n; i++)
 if(!v[i]) 
 {
 	r=i;
	break;
 }
 dp(r);
 if (f[r][0] > f[r][1]) printf("%d\n", f[r][0]);
 else printf("%d\n", f[r][1]);
 return 0;
}
