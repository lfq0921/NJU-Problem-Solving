#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int a[N], n;
#define MOD 998244353
typedef long long ll;
ll qpow(ll a, ll n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 1)
		return qpow(a, n - 1) * a % MOD;
	else
	{
		ll temp = qpow(a, n / 2) % MOD;
		return temp * temp % MOD;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int q = qpow(n, MOD - 2);
	//cout << "q = " << q << endl;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
			tmp = (tmp + a[j]) % MOD/*, printf("t = %d, i = %d, j = %d\n", tmp, i, j)*/;
		int tmp2 = a[i];
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				a[j] = 1ll * tmp * q % MOD/*, printf("a[%d] = %d, i = %d\n", j, a[j], i)*/;
			else
				a[j] = 1ll * ((1ll * (n - 1) * a[j] % MOD + tmp2) % MOD) * q % MOD/*, printf("a[%d] = %d, i = %d\n", j, a[j], i)*/;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}
