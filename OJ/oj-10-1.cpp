#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 1000, maxM = 1000;
int s[maxN][maxM];
int whatm[maxN];
int main()
{
	int n;
	scanf("%d", &n);
	for	(int i = 0; i < n; i++)
		scanf("%d", &whatm[i]);
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < whatm[i]; j++)
			scanf("%d", &s[i][j]);
	}
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		int opt;
		scanf("%d", &opt);
		switch(opt){
			case 0:
				{
					int x, y, v, c;
					scanf("%d %d %d %d", &x, &y, &v, &c);
					memset(&s[x][y], v, c);
					printf("true\n");
					break;
				}
			case 1:
				{
					int x0, y0, x1, y1;
					scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
				}
		}
	}
 } 
