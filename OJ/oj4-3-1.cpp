#include <bits/stdc++.h>
using namespace std;
void move(string one, string two)
{
	cout << "Move " << "from " << one << "to " << two << endl;
}
void hanoi(int n, string a, string b, string c)
{
	if (n = 1) move(a, b) ;
	if (n > 1) 
	{
		hanoi(n-1, a, c, b);
		move(a, c);
		hanoi(n-1, b, a, c);
	}
}
int main()
{
	string A, B, C, n[11], x;
	int N;
	cin >> N;
	gets(A);
	gets(B);
	gets(C);
	for (int i = 1; i <= n; i ++)
		gets(n[i]);
	x = N[n];
	hanoi(n, A, B, C);
	return 0;
}
