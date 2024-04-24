#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

const int N = 20000 + 5;

//string s1, sn;
string s[N];

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
    dis[0] = 0;
    //printf("dis1 = %lld\n", dis[1]);
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    pq.push(make_pair(0, 0));
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
	scanf("%d", &n);
	cin >> s[0] >> s[1];
	int len = s[0].length();
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> s[i];
	} 
	for (int i = 0; i < n + 1; i++)
	for (int j = i + 1; j <= n + 1; j++)
	{
		if (i == j) continue;
		int cntDiff = 0;
		int cnt = 0;
		while (cntDiff <= 1 && cnt < len)
		{
			if(s[i][cnt] != s[j][cnt]) cntDiff++;
			cnt++;
		}
		if (cntDiff <= 1) 
		{
			addedge(i, j);
			//printf("add %d & %d\n", i, j);
		}
	}
	dij();
	printf("%lld ", dis[1] >= inf ? 0 : dis[1] + 1);
}
