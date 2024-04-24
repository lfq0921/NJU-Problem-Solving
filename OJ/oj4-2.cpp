#include <bits/stdc++.h>
using namespace std;
long long f(long long x)
{
	long long a = floor(sqrt(x) / 3);
	long long b = floor(sqrt(x) / 2);
	if (x == 0) return 0;
	long long y = 2 * f(a) + 3 * f(b)+ (x/2);
	return y;
}
int main()
{
	long long x;
	cin >> x;
	cout << f(x);
	return 0;
}
