#include<iostream>
using namespace std;
int num[10][10], row[10][10], col[10][10], block[10][10], flag[10][10];
bool ok = false;
void dfs(int n, int m)
{
	
	if (ok) return;cout << "n = " << n << " m = " << m << endl;
	/*if ((n == 5) && (m == 3))
	{
		ok = true;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
				cout << num[i][j];
			cout << endl;
		}
		return;
	}*/
	if ((n == 9) && (m == 10))
	{
		ok = true;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
				cout << num[i][j];
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		bool change = false;
		if ((flag[n][m] != 1) && (row[n][i] != 1) && (col[m][i] != 1) && (block[((n - 1) / 3) * 3 + (m - 1) / 3 + 1][i] != 1))
		{
			num[n][m] = i;
			row[n][i] = 1;
			col[m][i] = 1;
			block[((n - 1) / 3) * 3 + (m - 1) / 3 + 1][i] = 1;
			change = true;
		}
		if (change || (flag[n][m] == 1))
		{
			if (m != 9) dfs(n, m + 1);
			else if ((n == 9) && (m == 9)) dfs(9, 10);
			else dfs(n + 1, 1);
			if (change)
			{
				row[n][i] = 0;
				col[m][i] = 0;
				block[(n - 1) / 3 + (m - 1) / 3 + 1 + ((n - 1) / 3) * 2][i] = 0;
			}
		}
		if (ok) {cout << "return " << endl;return;}
	 } 
	return;
}
int main()
{
	/*记得初始化数组*/
	for (int i = 1; i <= 9; i++)
	for (int j = 1; j <= 9; j++)
	{
		flag[i][j] = 0;
		row [i][j] = 0;
		col [i][j] = 0;
		block[i][j] = 0;
	}
	int T;
	cin >> T;
	while (T--)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				char hehe;
				cin >> hehe;
				num[i][j] = hehe - '0';
				if (num[i][j] != 0)
				{	
					row[i][hehe - '0'] = 1;
					col[j][hehe - '0'] = 1;
					flag[i][j] = 1;
					block[(i - 1) / 3 + (j - 1) / 3 + 1 + ((i - 1) / 3) * 2][hehe - '0'] = 1;
				}
				
			}
			getchar();
		}
		dfs(1, 1);
		
	}return 0;
}
