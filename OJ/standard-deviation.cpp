#include<iostream>
#include<cmath>
using namespace std;
double x[100];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	double xba;
	double sum = 0;
	for (int i = 1; i <= n; i++)
		sum += x[i];
	xba = sum / n;
	sum = 0; 
	for (int i = 1; i <= n; i++)
		sum += (x[i] - xba) * (x[i] - xba);
	double res = sqrt(sum / n);
	cout << res;
 } 
