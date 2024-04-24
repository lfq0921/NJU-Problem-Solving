#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
unsigned int s[100001];
int findnum(int begin, int end, string s)
{
	int num = 0;
    for (int i = begin; i <= end; i++)
    {
        num += (s[i] - '0') * pow(10, end - i);
    }
    return num;
}

int main()
{
	memset(s, 0, 100001);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int val;
			unsigned int x = 1;
			cin >> val;
			x = (x << val) | (x >> 32 - val);
			s[i] = s[i] | x; 
			
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		
		unsigned int res;
		int a, b;
		string st;
		cin >> a >> st >> b;
		
		if (st[0] == '/') 
		{
			res = s[a] & s[b];
			unsigned int x = 1;
			for (int i = 0; i < 32; i++)
			{	
				unsigned int that = (res & ((unsigned int)1 << i));
				if (x == that) cout << i << ' ';
				x = (x << 1) | (x >> 31);
			}
			cout << endl;
		}
		if (st[1] == '/')
		{
			res = s[a] | s[b];
			
			unsigned int x = 1;
			for (int i = 0; i < 32; i++)
			{
				
				unsigned int that = res & ((unsigned int)1 << i);
				
				if (x == that) cout << i << ' ';
				x = (x << 1) | (x >> 31);
			}
			cout << endl;
		}
		if (st[0] == '-')
		{
			
			unsigned int x = 1;
			for (int i = 0; i < 32; i++)
			{
				unsigned int p = s[a] & ((unsigned int)1 << i);
				unsigned int q = s[b] & ((unsigned int)1 << i);
				if ((p) && (!q)) cout << i << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
