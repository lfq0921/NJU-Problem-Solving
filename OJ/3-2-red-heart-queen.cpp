#include<bits/stdc++.h>
using namespace std;
int n, d[1000005];
struct soldier
{
	int attack;
	int armor;
};

bool compare2 (soldier s1, soldier s2)
{
	return s1.armor > s2.armor;
}

int main()
{
	vector <soldier> man;
	scanf("%d", &n);
	if (n == 0) 
	{
		printf("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		soldier newone;
		scanf("%d %d", &newone.attack, &newone.armor);
		man.push_back(newone);
	}
	sort(man.begin(), man.end(), compare2);
	d[1] = man[0].attack;
	int len = 1;
	for (int i = 1; i < n; i++)
	{
		if (man[i].attack > d[len]) d[++len] = man[i].attack;
		else
		{
			int j = upper_bound(d, d + len, man[i].attack) - d;
			d[j] = man[i].attack;
		 } 
	}
	printf("%d", len);
	return 0;
 } 
