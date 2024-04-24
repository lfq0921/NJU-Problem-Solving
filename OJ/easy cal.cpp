#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	int m, n, product;
	cin >> m;
	while (m >= 10){
	product = 1;
		while (m != 0){
			n = m % 10;
			if (n != 0) product = product * n;
			m = m / 10;
		}
	m = product;
	}
	cout << m;
 } 
