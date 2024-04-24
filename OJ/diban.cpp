#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n,f,j;
	cin >> n;
	f=2;
	for (int i=2;i<=n;i++)
	{
		if(f%2==0) j=f/2;
		else j=f/2+1;
		f=f+j;
	}
	cout << f;
	return 0;
}
