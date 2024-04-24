#include <iostream>
using namespace std;
int num[70];
bool a[1005][1005];
int main()
{
	int count = 0;
	int x;
	do
	{ 
		cin >> x;
		num[++count] = x;
	}while(x != -1);
	count--;
	for (int i = 1; i <= count; i++)
	for (int j = 1; j <= count; j++)
		a[num[i]][num[j]] = false;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = true;
	}
	int ref = 0;
	for (int i = 1; i <= count; i++)
	{
		if (a[num[i]][num[i]]) ref++;
	}
	if (ref == count) cout << "reflexive" << endl;
	bool sym = true;
	for (int i = 1; i <= count; i++)
	for (int j = 1; j <= count; j++)
	{
		if (a[num[i]][num[j]])
		{
			if (!a[num[j]][num[i]]) sym = false;
		}
			
	}
	if (sym) cout << "symmetric" <<endl;
	bool tran = true;bool in = false, IN = true;
	for (int i = 1; i <= count; i++)
	for (int j = 1; j <= count; j++)
	{
		if (j == i) continue;
		for (int k = 1; k <= count; k++)
		{
			if (k == j) continue;
			IN = false;
			if (a[num[i]][num[j]] && a[num[j]][num[k]]) 
			{
				cout << num[i] <<' ' <<num[j] << ' ' << num[k] << endl;
				in = true;
				if (!(a[num[i]][num[k]])){
					tran = false;
					cout << num[i] << ' ' << num[k] <<endl;
				}
					
			}
			 
		}
	}
	if ((tran && (in || IN)) || (n == 0)) cout << "transitive";
	 
 } 
