#include<iostream>
#include<algorithm>
using namespace std;
int num[105], mud[1000000];
bool find(int n, int m)
{
	int a = 1;
	int b = n;
	bool ok = false;
	while(a <= b && !ok)
	{
		if(mud[a] + mud[b] == m)
		ok = true;
		else if(mud[a] + mud[b] < m) a++;
		else if (mud[a] + mud[b] > m) b--;
	}
	return ok;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		int count = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
		{
			count++;
			mud[count] = num[i] + num[j] + num[k];
		}
		sort(mud + 1, mud + 1 + count);
		if (find(count, m)) printf("Yes\n");
		else printf("No\n");
	} 
	
	return 0; 
 } 
