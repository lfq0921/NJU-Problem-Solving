#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, xue;
vector<int> e[N];
int dis[5][N];
int val[N] = { 0 };
int f[N][505];
bool jinguo[N] = { 0 };

void bfs1(int num)
{
	memset(jinguo, 0, sizeof(jinguo));
	queue<int> q;
	for (int i = 1; i <= n; i++) if (dis[num][i] == 0) 
	{
		q.push(i); jinguo[i] = 1;
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < e[x].size(); i++)
		{
			int y = e[x][i];
			if (!jinguo[y])
			{
				dis[num][y] = min(dis[num][y], dis[num][x] + 1);
				q.push(y); 
				jinguo[x] = 1;
			}
		}
	}
}

void bfs2()
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, xue));//位置和现存血量 
	while(!q.empty())
	{
		int x = q.front().first;//位置 
		int j = q.front().second;//现存血量 
		q.pop();//出队 
		for (int i = 0; i < e[x].size(); i++)
		{
			//printf("i = %d x = %d\n", i, x);
			int y = e[x][i];//下一站 
			int t = f[x][j];//当前时间 
			if (j >= 1 && t + 1 >= dis[1][y] && dis[1][y] < dis[2][y] && f[y][j - 1] > f[x][j] + 1) //过路费为1 
			{
				f[y][j - 1] = t + 1;
				q.push(make_pair(y, j - 1));
			}
			else if (!(t + 1 >= dis[1][y] && dis[1][y] < dis[2][y]))
			{
				if (f[y][j] > f[x][j] + 1) 
				{
					f[y][j] = t + 1;
					q.push(make_pair(y, j));
				} 
			}
		}
	}
	
}

int main()
{
	scanf("%d%d%d", &n, &m, &xue);
	for (int i = 1; i <= n; i++) dis[1][i] = INT_MAX, dis[2][i] = INT_MAX;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int g, w;
	scanf("%d%d", &g, &w);
	for (int i = 1; i <= g; i++)
	{
		int x;
		scanf("%d", &x);
		dis[1][x] = 0;
		val[x] = 1; 
	}
	for (int i = 1; i <= w; i++)
	{
		int x;
		scanf("%d", &x);
		dis[2][x] = 0;
	}
	bfs1(1);
	bfs1(2); 
	
	for (int i = 1; i <= n; i++)
	//printf("hao:%d huai:%d\n", dis[2][i], dis[1][i]);
	
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= xue; j++)
		f[i][j] = INT_MAX;
	
	f[1][xue] = 0;
	//printf("before: f[n][0] = %d\n", f[n][0]);
	bfs2();
	//printf("after: f[n][0] = %d\n", f[n][0]);
	
	int minn = INT_MAX;
	for (int i = 0; i <= xue; i++)
	if(minn > f[n][i]) 
	{
		//printf ("i = %d", i);
		minn = f[n][i];
	}
	
	if (minn < INT_MAX) printf("yes\n%d", minn);
	else printf("no");
	return 0;
	
 } 
