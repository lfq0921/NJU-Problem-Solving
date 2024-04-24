#include<iostream>
#include<algorithm>
#include<cmath>
#include <iomanip>
using namespace std;
const int N = 9 + 5;
double a[N][N], b[N][N], c[N][N];
int n;

double calRes(int p, int q) 
{

double result = 1;
double time;
int equi = 0;
for (int i = 1; i <= n; ++i){
	int equj = 0;
for (int j = 1; j <= n; ++j)
{
	if (i == p) equi = 1;
	if (j == q) equj = 1;
	c[i][j] = a[i + equi][j + equj];
}
}
for (int j = 1; j <= n - equi; j++){
			
/////////////   lfq begin     ///////////////
		int maxLine = j;
		for (int i = j; i <= n - equi; i++)
			if (fabs(c[i][j]) > fabs(c[maxLine][j])) maxLine = i;
		
		if (maxLine != j) result *= -1;
		for (int i = 1; i <= n - equi; i++)
			swap(c[maxLine][i], c[j][i]);
/////////////   lfq end       ///////////////

if (c[j][j] == 0){
			return 0;
		}

		for (int i = j + 1; i <= n - equi; i++){
			time = c[i][j] / c[j][j];
			c[i][j] = 0;
			for (int k = j + 1; k <= n - equi; k++)
				c[i][k] -= (c[j][k] * time);
		}
	}
	for (int i = 1; i <= n - equi; i++) 
		result *= c[i][i];
		cout << result << endl;
		cout << endl;
	return result;
}
		
		
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		cin >> a[i][j];
	double Ares = calRes(-1, -1);
	if (Ares == 0) 
	{
		cout << "No Solution";
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	{
		int porn = (i + j) % 2;
		if (porn) porn = -1;
		else porn = 1;
		b[j][i] = calRes(i, j) * porn / Ares;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << endl;
		for (int j = 1; j <= n; ++j){
			cout<<setiosflags(ios::fixed)<<setprecision(3);
			cout << b[i][j] << ' ';}
	}
	return 0;
	
 }
