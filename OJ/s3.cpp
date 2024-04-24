#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, c, s, p;
	cin >> a >> b >> c;
	p=0.5*(a+b+c);
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout << setiosflags(ios::fixed) << setprecision(6) << s;
	return 0;
}
