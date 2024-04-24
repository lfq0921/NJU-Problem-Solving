#include<bits/stdc++.h>
using namespace std;
int T;
int A[1005][1005], B[1005][1005], C[1005][1005], X[1005], Y[1005], Z[1005];
inline int read()
{
	int x = 0, y = 1;
	char c = getchar();//y代表正负（1.-1），最后乘上x就可以了。
	while (c < '0' || c > '9') 
	{
		if (c=='-') y = -1;
		c = getchar();
	}//如果c是负号就把y赋为-1
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*y;//乘起来输出
}

int main()
{
	T = read();
	while(T--)
	{
		int n = read();
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			A[i][j] = read();
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			B[i][j] = read();
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			C[i][j] = read();
		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				printf("%d", A[i][j]);
			printf("A\n");
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				printf("%d", B[i][j]);
			printf("B\n");
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				printf("%d", C[i][j]);
			printf("C\n");
		}*/
		srand(time(NULL));
		for (int i = 1; i <= n; i++)
		X[i] = rand() % 2;
		for (int i = 1; i <= n; i++)
		{
			Y[i] = 0;
			{
				for (int j = 1; j <= n; j++)
					Y[i] += X[j] * A[j][i];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			Z[i] = 0;
			{
				for (int j = 1; j <= n; j++)
					Z[i] += Y[j] * B[j][i];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			Y[i] = 0;
			{
				for (int j = 1; j <= n; j++)
					Y[i] += X[j] * C[j][i];
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; i++)
		if (Y[i] != Z[i]) flag = 0, i = n + 1;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
 } 
