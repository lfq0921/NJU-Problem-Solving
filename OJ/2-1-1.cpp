#include<iostream>
using namespace std;
int k;
int cal(int x)
{
	int sum = 0;
	while(x > 0)
	{	
		int a = x % 10;
		sum += a * a * a;
		x /= 10;
	}
	sum += k;
	return sum;
}
int main()
{
	while(scanf("%d", &k) == 1)
	{
		for (int i = 0; i <= k + 10000; i++)
		{
			if (cal(i) == i) cout << i << endl;
		}
		cout << endl;
	}
	return 0;
 } 
