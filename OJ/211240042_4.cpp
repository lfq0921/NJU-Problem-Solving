#include <bits/stdc++.h> 
using namespace std;
int decToBin(int dec)
{
	int result = 0, temp = dec, j = 1;
	while(temp){
		result = result + j * (temp % 2);
		temp = temp / 2;
		j = j * 10;
	}
	return result;
}
int dotTenToTwo(float dot)
{
	while (dot)
	{
		dot = dot * 2;
		result 
	}
}
int main()
{
	float x, y, x1, x2;
	int a, b, c;
	b = 0;
	cin >> x;
	if (x >= 0) 
		c = 1;
	else c = -1;
	x = abs(x);
	x1 = floor(x);
	x2 = x-x1;
	y = decToBin(x1);
	while (y >= 10)
	{
		y = y / 10;
		b ++;
	}
	cout << c << endl << b << endl;
	cout << setiosflags(ios::fixed) << setprecision(4);
	cout << y << endl;
	return 0;
}
