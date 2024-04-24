#include<iostream>
using namespace std;
int main()
{
	int m, n;
	int N = 105;
	int a[N][N];
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	int height[N][N];
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		height[i][j] = 0;
	for (int j = 1; j <= n; j++)
	{
		int h = 0;
		for (int i = m; i >= 1; i--)
		{
			if (a[i][j] == 0) 
			{
				h = 0;
				height[i][j] = 0;
			}
			if (a[i][j] == 1) 
				height[i][j] = ++h;
			else height[i][j] = h;
		}
	}
	int mmax = 0, M = 0;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		if (a[i][j] == 1)
		{
			mmax = height[i][j];
			int h = height[i][j];
			int right = j;
			while ((right < n) && (a[i][right + 1] == 1))
			{
				right ++;
				int dibian = right - j + 1;
				h = min(h, height[i][right]);
				mmax = max(mmax, h * dibian);
			}
			M = max(mmax, M); 
		}
	cout << M;
	return 0;
}
