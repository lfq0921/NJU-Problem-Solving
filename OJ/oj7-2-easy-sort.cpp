#include<bits/stdc++.h>
using namespace std;
int res[100005];
int functionA(int index)
{
	//cout << "index = " << index << endl;
	if (index <= 1) return index;
	if (res[index] != -1) return res[index];
	else
	{
		int ans = index;
		int i = 2;
		int fans = index / 2;
		while (i <= index)
		{
			fans = index / i;
			//cout << "i = " << i << endl;
			//cout << "index / fans + 1 = " << index / fans + 1 <<endl;
			ans = (ans + ((index / fans + 1 - i) * functionA(index / i)) % 998244353) % 998244353;
			i = index / fans + 1;
			//cout << "after change i = " << i << endl;
		}
		res[index] = ans;
		return ans;
	} 
}
int main()
{
	memset(res, -1, sizeof(res));
	int qn;
	cin >> qn;
	for (int i = 1; i <= qn; i++)
	{
		int index;
		cin >> index; 
		cout << functionA(index) << endl;
	}
	return 0;
 } 
