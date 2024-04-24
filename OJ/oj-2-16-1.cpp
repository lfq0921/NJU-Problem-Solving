#include<bits/stdc++.h>
using namespace std;
long long sol[1000005];
int k;

long long solve(int n)
{
	if (n == 1) return 1;
	if (sol[n] != -1) return sol[n];
	long long sum = solve(n - 1);
	for (int i = 1; i <= min(k, n - 1); i++)
	{
		sum = (sum + solve(n - i)) % 2000000007;
	}
	sol[n] = sum;
	return sum;
}

int main()
{
	memset(sol, -1, sizeof(sol));
	int T;
	scanf("%d%d", &T, &k);
	sol[1] = 2;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", (solve(n) * 2) % 2000000007);
	}
	/*for (int i = 1; i <= 5; i++)
		printf("sol[%d] = %d\n", i, sol[i]);*/
	return 0;
}
