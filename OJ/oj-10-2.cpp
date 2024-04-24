#include<iostream>
using namespace std;
char all[22 + 5][80 + 5], bll[22 + 5][80 + 5];
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= 22; ++i)
	{
		char c = getchar();
		for (int j = 1; j <= 80; ++j)
		{
			scanf("%c", &all[i][j]);
			bll[i][j] = all[i][j];
		}
	}
	
	for (int i = 1; i <= T; i++)
	{
		for (int j = 1; j <= 22; ++j){
		for (int k = 1; k <= 80; ++k)
		{
			
			int count = 0;
			for (int l = j - 1; l <= j + 1; l++)
			{
				for (int m = k - 1; m <= k + 1; m++)
				{
					int x, y;
					if (l == 23) x = 1;
					else if (l == 0) x = 22;
					else x = l;
					if (m == 81) y = 1;
					else if (m == 0) y= 80;
					else y = m;
					if (!((l == j) && (m == k)) && (all[x][y] == '*'))++count;
				}
				
			}
			if ((count > 3) || (count < 2)) 
			{
				bll[j][k] = ' ';
			}
			if (count == 3) bll[j][k] = '*';
		}
	}
		for (int j = 1; j <= 22; ++j)
		for (int k = 1; k <= 80; ++k)
		{
			all[j][k] = bll[j][k];
		}
		
	}
	for (int i = 1; i <= 22; ++i)
	{
		for (int j = 1; j <= 80; ++j)
		{
			
			printf("%c", all[i][j]);
		}
		
		printf("\n");
	}
	return 0;
}
