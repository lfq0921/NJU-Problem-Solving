#include<iostream>
using namespace std;
int x;
int cou[85][85];
int count(int num, int cost)
{
	if (cou[num][cost] != -1) return cou[num][cost];
	if ((num == 1) && (cost <= x)) 
	{
		cou[1][cost] = 1;
		return 1;
	}
	cou[num][cost] = 0;
	for (int i = 0; i <= (cost / num); i++)
	{
		cou[num][cost] += count(num - 1, cost - i * num);
	}
	return cou[num][cost];
}
int main()
{
	cin >> x;
	for (int i = 1; i <= x; i++)
	for (int j = 0; j <= x; j++)
		cou[i][j] = -1;
	int res = 0;
	for (int i = x; i >= 0; i--)
	{
		res = ((x - i) * count(x, i) + res) % 998244353;
	}
		
	cout << res;
}
