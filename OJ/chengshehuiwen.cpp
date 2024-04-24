#include<bits/stdc++.h>
using namespace std;

int huiwen(int n)
{
	int a[1000];
	int num = 0;
	while (n > 0){
		num++;
		a[num] = n % 10;
		n = n / 10;
	}
	int b = 0;
	for (int i = 1; i <= num; i++){
		b = b + a[i] * pow(10, num - i);
	}
	return b;
}

int main(){
	int n;
	cin >> n;
	int p = 0;
	while (n != huiwen(n)){
		p++;
		n = n + huiwen(n);
	}
	cout << p << ':' << n;
}
	
