#include<iostream>
#include<cmath>
using namespace std;
int n, m;
mypow(int base, int time)
{
	int res = 1;
	for (int i = 1; i <= time; i++)
		res = (res * base) % 998244353;
	cout << "res = " << res <<endl;
	return res;
}
int main()
{
	cin >> n >> m;
	int fenzi = 1;
	int fenmu = 1;
	for (int i = m; i <= m + n - 1; i++)
		fenzi = (fenzi * i) % 998244353;
	for (int i = 1; i <= n; i++)
		fenmu = fenmu * i;
	cout << sum;
	return 0;
 } 
