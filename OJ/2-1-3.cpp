#include<iostream>
using namespace std;
long long ca[5005];
int main()
{
	int n;
	cin >> n;
	ca[0] = ca[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		ca[i] = 0;
		for (int j = 0; j <= i - 1; j++)
		{
			ca[i] += (ca[j] * ca[i - j - 1]) % 1000000007;
			ca[i] = ca[i] % 1000000007;
		}
	}
	for (int i = 1; i <= n; i++)
	cout << i << " " << ca[i] << endl;
	return 0;
}
