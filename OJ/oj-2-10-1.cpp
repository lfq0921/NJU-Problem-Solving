#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 1005;
int a[N];
int n, m, k;
vector<int> fac;
inline int read()
{
	int x = 0, y = 1;
	char c = getchar();//y代表正负（1.-1），最后乘上x就可以了。
	while (c < '0' || c > '9') 
	{
		if (c == '-') y = -1;
		c = getchar();
	}//如果c是负号就把y赋为-1
	while (c >= '0' && c<='9') x = x * 10 + c - '0', c=getchar();
	return x * y;//乘起来输出
}

void find(int x)
{
	for (int i = 1; i <= sqrt(x); i++)
		if (x % i == 0)
		{
			fac.push_back(i);
			if (i != x / i) fac.push_back(x / i);
		}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	if (m == 0)
	{
		cout << k;
		return 0;
	}
	if (n == n - m + 1) 
	{
		cout << a[1];
		return 0;
	} 
	srand(time(0));
	int randidx[25];
	for (int i = 1; i <= 20; i++)
		randidx[i] = i;
	random_shuflle(randidx + 1, randidx + 21);
	for (int i = 1; i <= min(n, 20); i++)
		find(a[randidx[i]]);
	
	int ans = 1;
	for (int i = 0; i < fac.size(); i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (a[j] % fac[i] == 0) cnt++;
		if (cnt >= m)
			if (ans < fac[i] && fac[i] <= k) ans = fac[i];
	}
	cout << ans;
}
