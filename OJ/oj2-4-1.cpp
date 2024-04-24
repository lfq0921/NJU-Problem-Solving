#include<iostream>
using namespace std;
int n, m;
int s[3000 + 5][3000 + 5];
char a[3000 + 5][3000 + 5]; 
int step(int x, int y)
{
	if (x == n - 1 && y == m) return 1;
	if (x == n && y == m - 1) return 1;
	if (a[x][y] =='X') return 0;
	if (s[x][y] != 0) return s[x][y];
	if (a[x + 1][y] == '.' && x + 1 <= n)  s[x + 1][y] = step(x + 1, y);
	if (a[x][y + 1] == '.' && y + 1 <= m) s[x][y + 1] = step(x, y + 1);
	s[x][y] = (s[x + 1][y] + s[x][y + 1]) % (1000000009);
	return s[x][y];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> a[i][j];
		s[i][j] = 0;
	}
	for (int i = 1; i<= n; i++)
		s[i][m + 1] = 0;
	for (int j = 1; j <= m; j++)
		s[n + 1][j] = 0;
	int res = step(1, 1);
	cout << res;
}
