#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int M, l, r, slen, tlen, pos[1001], count;
	string S, t, s2, s3;
	cin >> S >> M;
	slen = S.length();
	for (int i = 1; i <= M; i++)
	{
		count = 0;
		cin >> l >> r >> t;
		tlen = t.length();
		s2 = S.substr(l-1,r-l+1);
		if (tlen<=r-l+1)
		{
			for (int j=0;j<=r-tlen;j++)
			{
				s3 = s2.substr(j,tlen);
				if (s3==t) count++;			
			}
		}
		cout << count << endl;
	}
	return 0;
}
