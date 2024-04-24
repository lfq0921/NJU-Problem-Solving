#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e5 + 5;
int n, m;//点数，边数 
int n1, m1;
int timer;//dfs时间戳 
int stac[N], top;//栈 
int deg[N] = { 0 };//新建图的度 
int dfn[N] = { 0 }, low[N] = { 0 }; 
bool instack[N];//是否在栈中 
int cnt = 0;//强连通分量个数
int represent[N] = { 0 };//用一个点代替这个环 
long long Max = 0;
long long dis[N] = { 0 };
vector<pair<int, int>> e[N], e1[N];
vector<int> inhuan;
bool jinhuan[N] = { 0 };

void tarjan(int x)
{
	dfn[x] = low[x] = ++timer;//给时间戳
	//入栈 
	stac[++top] = x;
	instack[x] = 1;
	/*----------------------更新---------------------*/ 
	for(int i = 0; i < e[x].size(); i++)//遍历每一条边 
	{
		int y = e[x][i].first;
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(instack[y]) low[x] = min(low[x],dfn[y]);
	}
	/*---------------------------------------------*/
	if(dfn[x] == low[x])
	{
		int y;
		//找到一个强连通分量 
		cnt++;  
		do  
		{  
			//退栈
			y=stac[top--];  
			instack[y] = 0;  
			represent[y] = x;//给点赋值所在的强连通分量编号  
		}while(x != y);  
	} 
	return;
}

void toposort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if(represent[i] == i && !deg[i]) q.push(i);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int sz = e1[x].size();
		for (int i = 0; i < sz; i++)
		{
			int y = e1[x][i].first;
			int z = e1[x][i].second;
			deg[y]--;
			dis[y] = max(dis[y], dis[x] + z);
			if (dis[y] > Max) Max = dis[y];
			if (deg[e1[x][i].first] == 0) q.push(e1[x][i].first);
		}
	}
 }

int main()
{
	timer = 0;
	top = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++)//建立新的图 
	{
		int rep = represent[i];
		if (rep == i) n1++;
		int sz = e[i].size();
		for (int j = 0; j < sz; j++)
		{
			if (represent[i] != represent[e[i][j].first]) 
			{
				deg[e[i][j].first]++; //统计每个点的入度
				e1[rep].push_back(e[i][j]);//构建图 
			}
			else
			{
				jinhuan[i] = 1;
				jinhuan[e[i][j].first] = 1;
			}
		} 
	}
	toposort();//以拓扑序作为dp顺序
	for (int i = 1; i <= n; i++)
	if (jinhuan[i]) inhuan.push_back(i);
	sort(inhuan.begin(), inhuan.end());
	int sz = inhuan.size();
	for (int i = 0; i < sz; i++)
	printf("%d ", inhuan[i]);
	printf("\n%lld", Max);
	return 0;
}

