#include<iostream>
using namespace std;
int num[1000005];
bool find(int n, int m)
{
	int a = 1;
	int b = n;
	bool ok = false;
	while(a < b && !ok)
	{
		if(num[a] + num[b] == m)
		ok = true;
		else if(num[a] + num[b] < m) a++;
		else if (num[a] + num[b] > m) b--;
	}
	return ok;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		if (find(n, m)) printf("Yes\n");
				else printf("No\n");
	}
	return 0;
 } 
