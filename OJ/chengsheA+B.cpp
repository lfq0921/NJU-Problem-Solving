#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	char a[55], b[55];
	int res[150];
	scanf("%s %s", a, b);
	int lena, lenb;
	lena = strlen(a);
	lenb = strlen(b);
	memset(res, 0, 150);
	for (int i = lena - 1; i >= 0; --i)
	for (int j = lenb - 1; j >= 0; --j)
		res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
	for (int i = lena + lenb - 1; i >= 1; --i)
	{
		if (res[i] >= 10)
		{
			res[i - 1] += res[i] / 10;
			res[i] -= (res[i] /10) * 10;
		}
	} 
	for (int i = 0; i <= lena + lenb - 1; i++ )
	{
	
	if ((res[0] == 0) && (res[1] == 0)) {
	cout << '0';return 0;}
	else if ((res[i] == 0) && (i == 0)) continue;
	cout << res[i];
	}
	return 0;
}
