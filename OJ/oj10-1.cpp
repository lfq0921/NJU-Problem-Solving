#include <iostream>
#include <cstring>
using namespace std;
int m[1005], s[1005][1000005], len[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
		len[i] = m[i]; 
	} 
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m[i]; j++)
		cin >> s[i][j];
	for (int i = 0; i < n; i++)
		s[i][m[i]] = 0; 
	int k;
	cin >> k;
	while(k--)
	{
		bool jumpout = false;
		int opt;
		cin >> opt;
		switch(opt)
		{
			case 0:
				int x, y, val, c;
				cin >> x >> y >> val >> c;
				if (len[x] < y + c) len[x] = y + c;
				if ((x <= 0) || (x > n) || (y < 0)) 
				{
					cout << "overflow" << endl;
					jumpout = true;
				}
				if (jumpout) break;
				if (y + c > m[x]) cout << 'w'; 
				for(int i = y; i < y + c; i++)
					s[x][i] = val;
				cout << "true" <<endl;
				break;
			case 1:
				/*¼ÇµÃ¼ÓÅÐ¶Ï*/ 
				int x0, y0, x1, y1;
				cin >> x0 >> y0 >> x1 >> y1;
				if ((x0 <= 0) || (x0 > n) || (y < 0)) 
				{
					cout << "overflow" << endl;
					jumpout = true;
				}
				if (jumpout) break;
				if (x0 == x1) 
				{
					cout << "overwrite" << endl;
					jumpout = true;
				}
				if (jumpout) break;
				len[x1] = y1 + len[x0] - y0;
				if ((len[x0] > m[x0]) || (len[x1] > m[x1]))
					cout << 'w';  
				for (int i = y1; i <= y1 + len[x0] - y0; i++)
				{
					s[x1][i] = s[x0][i - y1 + y0];
				}
				cout << "true" << endl;
				break;
			case 2:
				int xl, yl;
				if (!(xl > 0) || !(xl <= n) || (yl > len[xl]) || (yl < 0))
				{
					cout << "overflow" << endl;
					break;
				}
				if (len[xl] > m[xl]) cout << 'w';
				cout << len[xl] - yl << endl;
				break; 
		}
	}
	return 0;
 } 
