#include<bits/stdc++.h>
using namespace std;
int T;
double p[1005], ans[1005];
int main()
{
	cin >> T; 
	/*training memory
	oxygen, nutrients, challenge your brain*/
	while(T--)
	{
		int n, k, m;
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 0; i < n; i++)
			scanf("%lf", &p[i]); 
		ans[1] = p[0];
		for (int i = 2; i <= m; i++)
		{
			//printf("ans[%d] = %lf\n", i - 1, ans[i - 1]);
			ans[i] = 0;
			for (int j = 0; j <= n - 1; j++)
			{
				ans[i] += p[j] * pow(ans[i - 1], j);//j toolmen get the newman
				//printf("p[%d] * pow(ans[%d - 1], %d) = %lf\n", j, i, j, p[j] * pow(ans[i - 1], j));
			}
				
		}
		//printf("ans[%d] = %lf\n", m, ans[m]);
		//printf("k = %d\n", k);
		double realAns = pow(ans[m], k);
		printf("%0.12f\n", realAns);
	}
	return 0;
}
