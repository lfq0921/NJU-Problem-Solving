#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 500 + 5;
const int M = 2500 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
bool flag[N][N] = {0}; 
 
vector<int> e[N]; 
void addedge(int x, int y)
{
    e[x].push_back(y);
    e[y].push_back(x);
}
 
ll dis[N];
bool vis[N];
priority_queue<pair<ll, int> > pq;
int n, m;
void dij()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    pq.push(make_pair(0, 1));
    while (!pq.empty())
    {
        pair<ll, int> now = pq.top();
        pq.pop();
        int x = now.second;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = 0; i < e[x].size(); i++)
        {
            int y = e[x][i];
            if (dis[y] > dis[x] + 1)
            {
                dis[y] = dis[x] + 1;
                pq.push(make_pair(dis[y] * -1, y));
            }
        }
    }
}
int main()
{
	int n, m;
    scanf("%d%d", &n, &m);
	for (int i = 0; i <= n + 1; i++)
	for (int j = 0; j <= n + 1; j++)
		flag[i][j] = 0;//初始化补图所有边都存在 
	
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        flag[y][x] = 1;
        flag[x][y] = 1;// 补图中此边不存在 
        //printf("there is no edge here (%d, %d)\n", x, y); 
    }//标出补图 
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
    	if (i == j) continue;
    	if (flag[i][j] == 0 && flag[j][i] == 0) 
		{
			addedge(i, j);
    		//printf("there is edge here (%d, %d)\n", i, j);
		} 
	}//addedge 
    dij();
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i] >= inf ? -1 : dis[i]);
    return 0;
}
