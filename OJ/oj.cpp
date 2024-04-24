#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n, a[5001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int num = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n - 1; j++){
			if (a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
				num++;
			}
		}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << endl << num;
	return 0;
} 
