#include<iostream>
using namespace std;
int a[500005];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	int x = 0;
	long long sum;
	do
	{
		x++;
		sum = 0;
		for (int i = 1; i <= n; i++)
			sum += min(a[i], x);	
	}while (sum >= k * x);
	cout << x - 1;
	return 0;
 } 
