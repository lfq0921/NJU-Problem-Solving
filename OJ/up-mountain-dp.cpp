#include<iostream>
#include<cmath>
using namespace std;
int h[105][105], res[105][105];
int R, C;
int search(int n, int m)
{
	if (res[n][m] != - 1) return res[n][m];
	bool ok = false;
	for (int i = n - 1; i <= n + 1; i++)
	{
		if ((i == 0) || (i > R))continue;
		for (int j = m - 1; j <= m + 1; j++)
		{
			if ((i != n) && (j != m)) continue; 
			if ((j > C) || (j == 0)) continue;
			if (h[i][j] < h[n][m])
			{
				ok = true;
				int temp = 1 + search(i, j);
				if (temp > res[n][m]) res[n][m] = temp;
			}
		}
	if (ok == false) res[n][m] = 1;
	}
	return res[n][m];
}
int main()
{
	
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	for (int j = 1; j <= C; j++)
		{
			cin >> h[i][j];
			res[i][j] = -1;
		}
	int MAX = 0;
	for (int i = 1; i <= R; i++)
	for (int j = 1; j <= C; j++)
	{
		res[i][j] = search(i, j);
		if (MAX < res[i][j]) {
		MAX = res[i][j];
		}
	}
	cout << MAX;
	return 0;
}
