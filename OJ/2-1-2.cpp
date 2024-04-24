#include<iostream>
using namespace std;
int x[1000005], g[1000005], c[1000005], d[1000005];
int gcd(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		g[i] = x[i];
		c[i] = x[i];
	}
	g[0] = 0;
	c[0] = 0;
	for (int i = n - 1; i >= 2; i--)
		{
			g[i] = gcd(g[i], g[i + 1]);
		}
	for (int i = 2; i <= n; i++)
	{
		c[i] = gcd(c[i], c[i - 1]);
	}
	d[1] = g[2];
	d[n] = c[n - 1];
	int theMax = max(d[1], d[n]);
	for (int chosen = 2; chosen < n; chosen++)
	{
		d[chosen] = gcd(c[chosen - 1], g[chosen + 1]);
		if (d[chosen] > theMax) theMax = d[chosen];
	}
	cout << theMax;
	return 0;
}
