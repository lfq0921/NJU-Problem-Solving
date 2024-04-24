#include<bits/stdc++.h>
using namespace std;
bool is_DAG;
int color[100005];
vector<pair<int, int>>e[100005];
int ord[100005];
int rd[100005];
int n, m;
struct node{
	int u, v;
}ed[100005];

bool check(int mid)
{
	memset(rd, 0, sizeof(rd));
	for (int i = 1; i <= n; i++)
	{
		int sz = e[i].size();
		for (int j = 0; j < sz; j++)
		{
			if (e[i][j].second > mid) rd[e[i][j].first]++; 
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) if (rd[i] == 0) q.push(i);
	int cnt = 0;
	memset(ord, 0, sizeof(ord));
	while (!q.empty())
	{
		cnt++;
		int x = q.front();
		ord[x] = cnt;
		//printf("%d\n", x);
		q.pop();
		int sz = e[x].size();
		for (int i = 0; i < sz; i++)
		{
			if (e[x][i].second > mid) 
			{
				rd[e[x][i].first]--;
				if (rd[e[x][i].first] == 0) q.push(e[x][i].first);
			}
		}	
	}
	for (int i = 1; i <= n; i++)
		if (rd[i] != 0) return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	int maxc = 0;
	int minc = 1000005;
	for (int i = 1; i <= m; i++)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		e[u].push_back(make_pair(v, c));
		if (c < minc) minc = c;
		if (c > maxc) maxc = c;
		ed[i].u = u;
		ed[i].v = v;
 	}
	
    int l = minc, r = maxc;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        //printf("%d\n", mid);
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
    check(ans);
    for (int i = 1; i <= m; i++)
    {
    	int u = ed[i].u, v = ed[i].v;
    	if (ord[u] < ord[v]) printf("%d %d\n", u, v);
		else printf("%d %d\n", v, u);
	} 
    return 0;
	
	
}
