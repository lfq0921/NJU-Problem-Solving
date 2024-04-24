#include<bits/stdc++.h>
using namespace std;
int N;
char s[2100005];
int main()
{
	cin >> N;
	while(N--)
	{
		long long cnt = 0;
		cin >> s;
		int len = strlen(s);
		bool safe = false;
		for (int i = 0; i < len; i++)
		{
			if (s[i] != '0') safe = true;
			cnt += s[i] - '0';
			if (safe) cnt += 1;
		}
		if (safe) cnt --;
		cout << cnt << endl;
	}
	return 0;
 } 
