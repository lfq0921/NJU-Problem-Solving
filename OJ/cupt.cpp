#include<bits/stdc++.h> 
using namespace std;
double x[270], y[270];
int main()
{
	freopen("cupt.in", "r", stdin);
	freopen("cupt.out", "w", stdout);
	for (int i = 1; i <= 262; i++)
		scanf("%lf", &x[i]);
	for (int i = 1; i <= 262; i++)
		scanf("%lf", &y[i]);
	for (int i = 1; i <= 262; i++)
		printf("{%lf, %lf},\n", x[i], y[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
