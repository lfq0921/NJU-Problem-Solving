#include <bits/stdc++.h> 
using namespace std;
int n,m,K,a,b,in;
int A[20][20], B[20][20];
void func1()
{
	for (int j = 1; j <= m; j++)
		swap(A[a][j], A[b][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	} 
}
void func2()
{
	for (int i = 1; i <= n; i++)
	swap(A[i][a], A[i][b]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	} 
}
void func3()
{
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		B[i][j] = A[n+1-j][i];
	swap (m, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			A[i][j] = B[i][j];
			cout << A[i][j] << ' ';
		}
	cout << endl;
	}
}
int main()
{
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i ++)
	for (int j = 1; j <= m; j ++)
	cin >> A[i][j];
	for (int i = 1; i<=K; i++)
	{
		cin >> in;
		if (in == 1) 
		{
			cin >> a >> b;
			if ((a > n) || (b > n) || (a <= 0) || (b <= 0))
			cout << "Invalid arguments!" << endl;
			else func1();
		}
		if(in == 2)
		{
			cin >> a >> b;
			if ((a > m) || (b > m) || (a <= 0) || (b <= 0))
			cout << "Invalid arguments!" << endl;
			else func2();
		}
		if (in == 3)
		func3();
		}
	return 0;
}
