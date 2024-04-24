#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	long long int x;
	bool p, q, h, P;
	cin >> T;
	for (int i = 1; i <= T; i ++)
	{
		cin >> x;
		p = x > 0;
		q = (x <= 14) && (x >= 4);
		h = (x > 44) || (x <= 26);
		P = p && q && h;
		if (P) cout << "T" << endl;
		else cout << "F" << endl;
	}
}
