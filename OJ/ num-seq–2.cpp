#include<iostream>
using namespace std;
int num[105], p[7];

int judge(int n, int m, int po1, int po2)
{	
	int sum;
	bool find = false;
	if (po1 == 3 && po2 == 4)
	{ 
		do
		{
			sum = 0;
			for (int i = 1; i <= 6; i++)
			{
				printf("p[%d] = %d\n",i, p[i]);
				sum += num[p[i]];
			}
				
			cout << "sum = " << sum << endl;
			if (sum == m) find = true;
			else if (sum < m) {
				{
					/*do
					{*/
						p[3]++; //cout << "p[3]++" <<endl;
					/*}while (num[p[3]] != num[p[3] - 1]);*/
				}
			}
			else 
			{
				/*do 
				{*/
					p[4]--;//cout << "p[4]--" <<endl;
				/*}while (num[p[4]] != num[p[4] + 1]);*/
				
			}
		}while(!find && p[3] <= p[4]);
		if (find) return 0;
		else if (sum < m) return -1;
		else return 1;
	}
	else 
	{
		int bos = 2;
		int pori1 = p[po1];
		int pori2 = p[po2];
		do
		{
			//cout << "po1 = " << po1 << endl;
			//cout << "po2 = " << po2 << endl;
			p[po1 + 1] = p[po1];
			p[po2 - 1] = p[po2];
			int temp = judge(n, m, po1 + 1, po2 - 1);
			if (temp == 0) return 0;
			if (temp == -1) {
				p[po1]++; p[po1 + 1] = p[po1];
				bos = -1;
				p[po2] = pori2; p[po2 - 1] = p[po2];
			}
			if (temp == 1) 
			{
				p[po2]--; p[po2 - 1] = p[po2];
				bos = 1;
				p[po1] = pori1; p[po1 + 1] = p[po1];
			}
		}while(p[po1] <= p[po2]);
		return bos;
	}
	
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d",&n, &m);
		p[1] = 1; p[2] = 1; p[3] = 1;
		p[4] = n; p[5] = n; p[6] = n; 
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		if(judge(n, m, 1, 6) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
 } 
