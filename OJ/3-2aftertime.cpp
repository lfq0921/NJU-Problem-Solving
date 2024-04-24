#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f;
long long n, m, a[35], f[27005];


int main()
{
	scanf("%lld %lld", &n, &m);
	printf("n = %lld, m = %lld\n", n, m);
	int themax = -inf;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &a[i]);
		if (a[i] > themax) themax = a[i];
	}
	long long div = 0;
	if (themax != -inf) div = m / themax;
	long long left = m - (themax * div);
	while (left > n * themax) 
	{
		left -= themax;
		div--;
	}
	memset(f, 0x3f3f3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = a[i]; j <= left; j++)
	{
		f[j] = min(f[j], f[j - a[i]] + 1);
	}
	
	if (f[left] != 0x3f3f3f) printf("%lld", f[left] + div);
	else printf("-1");
	return 0;
}
