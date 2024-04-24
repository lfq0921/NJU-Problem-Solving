#include<iostream>
#include<cstdio>
using namespace std;
long long judge[10005];

long long haha(int n){
	if ((n / 3) == 0) return 1;
	if ((n / 3) == 1) return 2;
	if (judge[n] != 0) return judge[n];
	for (int i = 1; i <= (n / 3); i++){
		judge[n] = judge[n] + haha(i); 
	}
	judge[n] = judge[n] + 1;
	return judge[n];
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		judge[i] = 0;
	cout << haha(n);
	return 0;
}
