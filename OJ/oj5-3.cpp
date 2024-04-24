#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long f[10000001];

long long F(long long x){
	if (x == 0) return 0;
	if (x == 1) return 1;
	if ((x <= 10000000) && (f[x] != -1)) 
		return f[x];
	long long t = pow(x, 0.8);
	long long a = max((int)floor(t) - 1, 0);
	long long b = x / 2;
	if (x <= 10000000){
		f[x] = 3 * F(a) + 2 * F(b) + x;
		return f[x];
	}
	else return 3 * F(a) + 2 * F(b) + x;
}

int main(){
	int N;
	long long a[100001];
	cin >> N;
	long long M = 10000000;
	for (int i = 1; i <= N; i++){
		cin >> a[i];
		if (M > a[i]) M = a[i];
	}
	for (int i = 0; i <= M; i++)
		f[i] = -1;
		
	for (int i = 1; i <= N; i++){
		cout << F(a[i]) << ' ';
	}
	return 0;
}
