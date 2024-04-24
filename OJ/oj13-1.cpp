#include<iostream>
#include<cstring>
using namespace std;
char s[105][55];
int count[105];
int main()
{
	int n, m;
	memset(count, 0, 105);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> s[i][j];
	for (int c = 1; c <= m; c++)
	{
		for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (s[c][i] > s[c][j]) count[c]++;
		}
	}
	int q[105];
	for (int i = 1; i<= m; i++)
		q[i] = i;
	for (int i = 1; i < m; i++)
	for (int j = 1; j <= m - 1; j++)
	{
		if (count[j] > count[j + 1]) 
		{
			swap(q[j], q[j + 1]);
			swap(count[j], count[j + 1]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << s[q[i]][j];
		cout << endl;
	}
	return 0;	
 } 
