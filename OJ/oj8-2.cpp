#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m;
	long long a, b;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		int ans = 0;
		while (b != a) {
			if (b < a) swap (a, b);
			ans++;
			b = b / 2;
		}
		cout << "Case #" << i << ": " << ans <<endl;
	}
	return 0;
 } 
