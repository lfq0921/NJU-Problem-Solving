#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, X, Y;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
const int N = 300000 + 5;

vector<int> e[N]; // edge connected with vertex-N
void addedge(int a, int b)
{
    e[a].push_back(b);
    e[b].push_back(a);
}

long long sum = 0;

ll dis1[N];
bool vis[N];
int pre[N] = {0};
bool contain[N] = {0};
bool notgood[N] = {0};
priority_queue <pair<ll, int> > pq;
void dij1(int s)
{
	bool flag = 0;
	memset(contain, 0, sizeof(contain));
    memset(notgood, 0, sizeof(notgood));
	if (s == X) {
		flag = 1;
		contain[s] = 1;
		//printf("flagged\n");
	}
    memset(dis1, 0x3f, sizeof(dis1));
    memset(pre, 0, sizeof(pre));
    dis1[s] = 0;
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        pair<ll, int> now = pq.top();
        pq.pop();
        if (notgood[now.second] == 1) continue;
        
        int x = now.second; // which vertex
		if (vis[x]) continue;
        vis[x] = true;
        for (int i = 0; i < e[x].size(); i++)
        {
            int y = e[x][i]; 
			if (dis1[y] > dis1[x] + 1)
            {
            	if (x == X)  flag = 1;
            	if (pre[y] == X) flag = 0;
            	pre[y] = x;
            	contain[y] = contain[x];
            	notgood[y] = notgood[x];
                dis1[y] = dis1[x] + 1;
                pq.push(make_pair(dis1[y] * -1, y));
            	if (y == Y && contain[y]) 
				{
					notgood[y] = 1;
					sum-=e[y].size();
					printf("jianle e[%d].size-1  = %d\n", y, e[y].size()-1);	
				}
				//if (notgood[y]) 
				//	printf("nogood while s = %d, x = %d, y = %d\n", s, x, y);
            }
        }
    }
}

/*ll dis[N];
void dij(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        pair<ll, int> now = pq.top();
        pq.pop();
        int x = now.second; // which vertex
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
}*/


int main() 
{
	 scanf("%d%d%d", &n, &X, &Y);
	 for (int i = 1; i < n; i++)
	 {
	 	int a; int b;
	 	scanf("%d%d", &a, &b);
	 	addedge(a, b);
	 }	 
	 /*for (int i = 1; i <= n; i++)
        {
        	printf("e[%d].size = %d\n", i, e[i].size());
		}*/
	 for (int i = 1; i <= n; i++)
	 {
	 	
	 	printf("origin sum = %lld", sum);
	 	dij1(i);
	 	//dij(i);
	 	//if (dis1[j] == dis[j] && j != i) sum++;
	 	
	 }
	 sum += n * n - 1;
	 printf("%lld", sum);
	 return 0;
} 
