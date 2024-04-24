#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int cnt[N] = {0};
bool forcnt[N] = {0};
vector <int> xvhao;
int n, m;
int prt[N];

void init()
{
    for (int i = 1; i <= n * m + 5; i++)
        prt[i] = i;
}

int get(int x)
{
    if (prt[x] == x)
        return prt[x];    // if its fa is itself, its the exit.
    prt[x] = get(prt[x]); // turn into the father of father
    return prt[x];
}

void merge(int x, int y)//combine lujingyasuo(?maybe)
{
	int f1 = get(x), f2 = get(y);
	if (f1 != f2) prt[f2] = f1;
	//printf("merge %d & %d\n", x, y);
 }
 
int main()
{
	scanf("%d%d", &n, &m);
	init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m - 1; j++)
		{
			int x;
			scanf("%d", &x);
			if (x == 1) merge((i - 1) * m + j, (i - 1) * m + j + 1);
		}
	for (int i = 1; i <= n - 1; i++)
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			if (x == 1) merge((i - 1) * m + j, i * m + j);
		}
	for (int i = 1; i <= n * m + 1; i++) get(i);
	//int cnt = 0;
	for (int i = 1; i <= n * m; i++) 
	{
		cnt[prt[i]]++;
		if (forcnt[prt[i]] == 0) 
		{
			xvhao.push_back(prt[i]);
			forcnt[prt[i]] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", prt[(i - 1) * m + j]);
		}
		printf("\n");
	}
	for(auto it :xvhao) 
	{
		printf("%d:%d\n", it, cnt[it]);
	}
	
	return 0;
	
}
