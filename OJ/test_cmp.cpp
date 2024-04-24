#include<bits/stdc++.h>
using namespace std;

static bool cmp(int &a, int &b)
{
	return a > b;
}
int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	sort(a, a + 5, cmp);
	for (int i = 0; i < 5; i++)
		printf("%d\n", a[i]);
	return 0;
}
