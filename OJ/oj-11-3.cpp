#include<iostream>
int x, res[85][85], resum = 0;
using namespace std;
int buy(int num, int count)
{
	if (res[num][count] != -1) return res[num][count];
	res[num][count] = 0;
	if ((num == 1) && (count == 0))
	{
		res[num][count] = x;
		return res[num][count];
	}
	if ((num == 1) && (count == 1)) {
		res[num][count] = x - 1;
		return res[num][count];
	}
	if (count == 0)
	{
		for (int i = 0; i < num; i++)
		res[num][count] += buy(num - 1, i);
		return res[num][count];
	}
	for (int i = 0; i < num; i++)
	{
		if (buy(num - 1, i) - num * count *  >= 0) 
		{
			res[num][count] = (buy(num - 1, i) - num * count + res[num][count]) % 998244353;	
		}
	}
	printf("res[%d][%d] = %d\n", num, count, res[num][count]);
	return res[num][count];
}
int main()
{
	cin >> x;
	for (int i = 1; i <= x; i++)
	for (int j = 0; j <= x; j++)
		res[i][j] = -1;
	buy(x, 1);
	for (int i = 1; i <= x; i++)
	for (int j = 1; j <= x; j++)
		resum += res[i][j];
	cout << resum;
 } 
