#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x[4], y[4], T, yUpd, yUpu, yDownu, xLeftr, xRightl, i;
	cin >> T;
	for (i = 1; i <= T; i ++ )
	{
		cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[4] >> y[4];
		if (x[2] < x[1]) swap(x[2], x[1]);
		if (y[1] < y[2]) swap(y[1], y[2]);
		if (x[4] < x[3]) swap(x[3], x[4]);
		if (y[3] < y[4]) swap(y[3], y[4]);
		if (y[3] < y[1]) 
		{
			swap(x[1], x[3]);
			swap(x[2], x[4]);
			swap(y[1], y[3]);
			swap(y[2], y[4]);
		}
		if (y[1] < y[4]) cout << "Intersection Not Found" << endl;
		else if (((x[2] <= x[4]) && (x[2] >= x[3])) || ((x[1] <= x[4]) && (x[1] >= x[3])))
			cout << "Intersection Found" << endl;
			else if (((x[4] <= x[2]) && (x[4] >= x[1])) || ((x[3] <= x[2]) && (x[3] >= x[1])))
			cout << "Intersection Found" << endl;
			else cout << "Intersection Not Found" << endl;
	}
	return 0;
}
