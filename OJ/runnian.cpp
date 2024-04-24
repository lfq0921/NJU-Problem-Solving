#include<iostream>
using namespace std;
int main()
{
	int by, ey;
	cin >> by >> ey;
	int a;
	a = ey / 4 - by / 4;
	int b = (ey % 100) - (by % 100);
	int c = (ey % 400) - (by % 400);
	int res = a - b + c;
	if ((by % 400 == 0) || ((by % 100 != 0) && (by % 4 == 0)))
	res++;
	cout << res;
	return 0; 
 } 
