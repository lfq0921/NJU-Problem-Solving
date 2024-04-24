#include<iostream>
using namespace std;
int d[100005], in[100005], count, sum = 0, c[100005];
bool ok = false;
void dfs (int num)
{
	if (in[num] == 1) 
	{
		sum += count - c[num];
		count = 0;
		in[num] = -1;
		ok = true;
		return;
	}
	if (in[num] == 0)
	{
		in[num] = 1;
		c[num] = count++;
		dfs(d[num]);
		in[num] = -1;
		return;	
	}
	return;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
		in[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ok = false;
		if (in[i] == 0) 
		{
			count = 0;
			dfs(i);
		}
	}
	cout << sum;
	return 0;
}
