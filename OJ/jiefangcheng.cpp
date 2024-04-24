#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int a, b, c;
	double delta, x1, x2, sdelta;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (delta < 0) 
	cout << "No Solution";
	else 
	{
		sdelta = sqrt(delta);
		x1 = (-b-sdelta)/(2*a);
		x2 = (-b+sdelta)/(2*a);
		if (x1>x2) swap (x1,x2);
		cout<<setiosflags(ios::fixed)<<setprecision(2);
		cout << x1 << ' ' << x2;
	}
}
