#include<bits/stdc++.h>
using namespace std;
int n, k, a[100005];

void counter_sorted (int l, int r)
{
	if (k > 0 && l < r)
	{
		int m = (l + r - 1) / 2;
		swap(a[m], a[m + 1]);
		k -= 2;
		counter_sorted(l, m);
		counter_sorted(m + 1, r);
	}
	else return;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	k--;
	counter_sorted(1, n);
	if (k > 0) 
	{
		cout << "-1" << endl;
	}
	else for (int i = 1; i <= n; i++)
	cout << a[i] << " ";
	return 0;
}
