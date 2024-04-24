#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[105], M[105];

int max(int n){
	if (n == 1) return a[1];
	M[n - 1] = max(n - 1);
	if (a[n] > M[n - 1]) return a[n];
	else return M[n - 1];
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << max(n);
	return 0;
}
