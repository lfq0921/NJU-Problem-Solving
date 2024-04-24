#include<iostream>
#include<cstring>
using namespace std;
bool flag[75] = {0};
int N, M, len, x[15], pos[75];
string ansS[75], S;

int main()
{
	memset (x, 0, sizeof(x));
	cin >> S;
	
	cin >> N >> M; 
	for (int i = 0; i < N; i++)
		scanf("%d", &pos[i]);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &x[i]);
		flag[x[i]] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		len = S.length();
		if (flag[i]) ansS[i] = S; 
		int deltaL;
		if (len % 5 != 0) deltaL = len / 5 + 1;
		else deltaL = len / 5;
		string strtmp;
		if ((pos[i] + deltaL - 1) / len == pos[i] / len)
		strtmp = S.substr(pos[i] % len, (pos[i] + deltaL - 1) % len - pos[i] % len + 1);
		else 
		{
			int change = len * ((pos[i] + deltaL - 1) / len);
			string string1 = S.substr(pos[i] % len, (change - 1) % len - pos[i] % len + 1);
			string string2 = S.substr(change % len, (pos[i] + deltaL - 1) % len - change % len + 1);
			strtmp = string1 + string2;
		}
		S = strtmp + S;
	}
	if (flag[N]) ansS[N] = S;
	for (int i = 1; i <= M; i++)
		cout << ansS[x[i]] << endl;
	return 0;
}
