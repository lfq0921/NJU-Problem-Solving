#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 5;
int n, m, R;
int dn, dfn[N], low[N], cnt, buc[N]; 
vector<int> e[N];
void dfs(int id) 
{
  dfn[id] = low[id] = ++dn; 
  int son = 0;
  for(int it : e[id]) 
  {
    if(!dfn[it]) 
	{
    	son++;
		dfs(it);
		low[id] = min(low[id], low[it]);
    	if(low[it] >= dfn[id] && id != R) cnt += !buc[id], buc[id] = 1;
    }
    else low[id] = min(low[id], dfn[it]);
  }
  if(son >= 2 && id == R) 
  {
  	cnt += !buc[id];
	buc[id] = 1;
  }
}
int main() 
{
  cin >> n >> m;
  for(int i = 1; i <= m; i++) 
  {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v), e[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) 
  	if(!dfn[i]) 
  	{
  		R = i;
		dfs(i);
  	}
  cout << cnt << endl;
  for(int i = 1; i <= n; i++) 
  	if(buc[i]) cout << i << " ";
  return 0;
}
