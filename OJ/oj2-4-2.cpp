#include<iostream>
using namespace std;
int com[4005][2005];
int combine(int n, int m)
{
	if (com[n][m] != -1) return com[n][m];
	if (m == 0)
	{
		com[n][m] = 1;
		return 1;
	}
	if (m == 1)
	{
		com[n][m] = n;
		return n;
	}
	if (m > n)
	{
		com[n][m] = 0;
		return 0;
	}
	com[n][m] = (combine(n - 1, m - 1) % 998244353 + combine(n - 1, m) % 998244353) % 998244353;
	return com[n][m];
}
int main()
{
	int M, N;
	cin >> N >> M;
	for (int i = 0; i <= M + N - 1; i++)
	for (int j = 0; j <= N; j++)
		com[i][j] = -1;
	cout << combine(N + M - 1, N);
	return 0;
 } 
