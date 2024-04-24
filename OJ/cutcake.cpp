#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int T, n, m, y;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> n;
		if (n != 0)
		{
			m = (n+1) % 2;
			if (m == 0)  
			y = (n+1)/2;
			else 
			y = n+1;
			cout << y << endl;
		}
		else cout << '0' << endl;
    }
	return 0;
 } 
