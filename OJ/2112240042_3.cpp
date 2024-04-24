#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int year;
	bool b1, b2;
	cin >> year;
	b1 = (year % 400 == 0);
	b2 = (year % 4 == 0) && (year % 100 != 0);
	if (b1 || b2)
		cout << "yes";
	else cout << "no";
	return 0;
}
