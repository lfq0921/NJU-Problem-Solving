#include <bits/stdc++.h> 
using namespace std;
int main()
{
	 int T, m, p, j[18], p2;
	 long long x, k;
	 cin >> T;
	 for(int i = 1; i <= T; i++)
	 {
	 	cin >> x;
	 	k = x;
	 	p = 1;
	 	while (k != 0)
	 	{
	 		j[p]=k % 10;
	 		k=k/10;
	 		p=p+1;
		}
		p=p-1;
		p2 = p/2;
		for (int q = 1; q <= p2; q++)
		{
		 	if (j[q] == j[p+1-q]) 
		 	m = 1;
		 	else 
			{
				m = 0;
				cout << 'N'<< endl;
				break;
			}
		}
	if ((m == 1)||(x < 10))cout << 'Y' << endl;
	}
	 return 0;
}
