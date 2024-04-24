#include<iostream>
using namespace std;
int d[100005], in[100005], count, sum = 0, c[100005], the[50005];
bool ok = false, can = true;
void dfs (int num)
{
	if (in[num] == 1) 
	{
		if (count - c[num] + 1 > 2)
		{
			can = false;
			return;
		 } 
		count = 0;
		in[num] = -1;
		ok = true;
		return;
	}
	if (in[num] == 0)
	{
		in[num] = 1;
		c[num] = ++count;
		dfs(d[num]);
		in[num] = -1;
		return;	
	}
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		can = true;
		count = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int c = 0;
			int en;
			cin >> en;
			if (en == 1) 
			{
				the[++count] = i;
				d[i][++c] = j;
			}
			in[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			ok = false;
			if (in[the[i]] == 0) 
			{
				count = 0;
				dfs(i);
			}
		}
		if (can) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	
	return 0;
}
