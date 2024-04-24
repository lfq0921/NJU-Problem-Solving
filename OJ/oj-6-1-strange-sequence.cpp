#include<iostream>
#define rep(i, a, b) for (register int i = a; i <= b; ++i)
using namespace std;
int n;
int a[2000005], copyIt[200005];
int zty_k (int l, int r, int k)
{
	if (l == r) 
	{
		if (a[l] != k)
		{
			copyIt[l] = k;
			return 1;
			//printf("return 1, when a[%d] change to be %d\n", l, k);
		}
		else 
		{
			copyIt[l] = k;
			//printf("return 0, when a[%d] is %d\n", l, k);
			return 0;
		}
	}
	int call = 0;
	int calr = 0;
	rep(i, l, (l + r) / 2)
		if (a[i] != k) call++;
	rep(i, (l + r) / 2 + 1, r)
		if (a[i] != k) calr++;
	//if (l ==1 && r ==8 ) cout << "calr = " << calr << endl;
	int ansl = call + zty_k((l + r) / 2 + 1, r, k + 1);
	//printf("ansl(%d, %d) = %d\n", l, r, ansl);
	
	
	int ansr = calr + zty_k(l, (l + r) / 2, k + 1);
	
	//printf("ansr(%d, %d) = %d\n", l, r, ansr);
	if (ansl <= ansr) 
	{
		rep(i, l, (l + r) / 2)
			copyIt[i] = k;
		//printf("return ansl(%d, %d) = %d\n", l, r, ansl);
		return ansl;
	}
	else 
	{
		rep(i, (l + r) / 2 + 1, r)
			copyIt[i] = k;
		//printf("return ansr(%d, %d) = %d\n", l, r, ansr);
		return ansr;
	}
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%d", &a[i]);
		copyIt[i] = a[i];
	}
	
	cout << zty_k(1, n, 1) << endl;
	/*int real = 0;
	rep(i, 1, n)
		if (copyIt[i] != a[i]) real++;
	cout << real << endl;*/
	rep(i, 1, n)
		printf("%d ", copyIt[i]);
	return 0;
 } 
 
