#include<bits/stdc++.h>
using namespace std;
long long num[55];
int main()
{
	int n;
	cin >> n;
	num[1] = 2;
	num[2] = 3;
	for (int i = 3; i <= n; i++)
		num[i] = num[i - 1] + num[i - 2];
	cout << num[n]; 
	return 0;
}
