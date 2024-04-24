#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 500 + 5;  //
const int M = 2500 + 5; //
const ll inf = 0x3f3f3f3f3f3f3f3fll;

vector<int> e[N]; // edge connected with vertex-N
void addedge(int x, int y)
{
    e[x].push_back(y);
    e[y].push_back(x);
}

ll dis[N];
bool vis[N];
priority_queue<pair<ll, int> > pq;
int n, m;
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
}

int main() 
{
	 scanf("%d", &n);
	 for (int i = 1; i < n; i++)
	 {
	 	int a; int b;
	 	scanf("%d%d", &a, &b);
	 	addedge(a, b);
	 }	 
	 for (int i = 1; i <= n; i++)
        {
        	printf("e[%d].size = %d\n", i, e[i].size());
		}
	return 0;
	
}
	
