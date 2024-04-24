#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
char s[1000005];

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
	    int s1 = 0, s2 = 0, s3 = 0;
		int jump = 0;
		scanf("%s", s);
		int length = strlen(s);
		s[length] = '/';
		for (int j = 0; j < length; j++)
		{
			if (s[j] == '(') 
			{
				++s1;
				if ((s[j + 1] == ']') || (s[j + 1] == '}')) 
				{
					cout << "No" << endl; jump = 1;
				}
			}
			if (s[j] == ')') --s1;
			if (s[j] == '[') 
			{
				++s2;
				if ((s[j + 1] == ')') || (s[j + 1] == '}')) 
				{
					cout << "No" << endl; jump = 1;
				}
			}
			if (s[j] == ']') --s2;
			if (s[j] == '{') 
			{
				++s3;
				if ((s[j + 1] == ')') || (s[j + 1] == ']')) 
				{
					cout << "No" << endl; jump = 1;
				}
			}
			if (s[j] == '}') --s3;
			if ((s1 < 0) || (s2 < 0) || (s3 < 0))
			{
				cout << "No" << endl; jump = 1;
			}
			if (jump == 1) break;
		}
		if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (jump == 0)) cout << "Yes" << endl;
		else if (jump == 0) cout << "No" << endl;
	}
	return 0;
}
