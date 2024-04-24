#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];
int main()
{
	int n, k;
	cin >> n >> k;
	long long all = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		all += a[i];
	}
	sort(a + 1, a + n + 1);
	long long x1 = a[1];
	long long x2 = all / k + 1;
	long long sum;
	bool big = false;
	bool small = false;
	long long x3;
	long long ans;
	while(x1 <= x2)
	{
		sum = 0;
		x3 = (x1 + x2) / 2;
		for (int i = 1; i <= n; i++)
			sum += a[i] < x3 ? a[i] :x3;
		if (sum >= k * x3)
		{
			ans = x3;
			x1 = x3 + 1;
		}
		else 
			x2 = x3 - 1;
	}
	cout << ans;
	return 0;
}
