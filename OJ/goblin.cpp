#include<iostream>
using namespace std;
int N;
long long ans;
long long cnt = 0;
int const int_max = 2147483647;

struct node
{
	int x;
	int y;
}a[500005],tmp[500005];

bool bigger (int i, int j)
{
	if ((a[i].x > a[j].x) || (a[i].x == a[j].x && a[i].y > a[j].y))
	return true;
	else return false;
}

void merge (int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r)
	{
		if (bigger(i, j))
		{
			tmp[k++] = a[j++];
			cnt += m - i + 1;
		}
		else
		{
			tmp[k++] = a[i++];
		}
		
	}
	while (i <= m) tmp[k++] = a[i++];
	while (j <= r) tmp[k++] = a[j++];
	for (int i = l; i <= r; i++)
		a[i] = tmp[i];
	return;
}
void merge_sort(int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		merge(l, m, r);
	}
}
int main()
{
	scanf("%d", &N);
	ans = N - 1;
	int p, q;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
		if (i == 1)
		{
			p = a[i].x;
			q = a[i].y;
		}
		else
		{
			if (a[i].x < p || (a[i].x == p && a[i].y < q))
			{
				p = a[i].x;
				q = a[i].y;
				ans--;
			}
		}
	}
	
	merge_sort(1, N);
	ans += 2 * cnt;
	cout << ans; 
 } 
