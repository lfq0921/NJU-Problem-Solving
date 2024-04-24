#include<bits/stdc++.h>
using namespace std;
const int N = 40,  M = 40;
int n, m;
int x[N][M], sum1, sum2;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		scanf("%d", &x[i][j]);
		if ((i+j)%2==0)sum1+=x[i][j];
		else sum2+=x[i][j];
		
	}	
	if (n == 2 && m == 2 || n*m %2 != 1) 
	{
		printf("4");
		return 0;
	}
	//printf("sum1 = %d\n sum2 = %d\n",sum1, sum2 );
	//printf("scanf over\n");
	int cnt2 = n * m / 2;
	int cnt1 = n * m - cnt2;
	
	int ans = (sum1-sum2);
	//printf("check here 1\n");
	ans= ans/(cnt1-cnt2);
	//printf("check here\n");
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		
		while (x[i][j] < ans) 
		{
			x[i][j]++;
			bool added = 0;
			if (i - 1 > 0 && added == 0)
			{
				if (x[i-1][j] < ans) 
				{
					added = 1;
					x[i-1][j]++;
				}
			}
			if (j - 1 > 0 && !added)
			{
				if (x[i][j-1] < ans) 
				{
					added = 1;
					x[i][j-1]++;
				}
			}
			if (i + 1 > 0 && added == 0)
			{
				if (x[i+1][j] < ans) 
				{
					added = 1;
					x[i+1][j]++;
				}
			}
			if (j + 1 > 0 && !added)
			{
				if (x[i][j+1] < ans) 
				{
					added = 1;
					x[i][j+1]++;
				}
			}
			if (!added) 
			{
				puts("-1");
				return 0;
			} 
		}
	}
	printf("%d", ans * n * m - sum1-sum2);
	return 0; 
}
