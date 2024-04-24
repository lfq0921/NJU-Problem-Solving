#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, a[50];
	int k = 0, cal = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j++)
		if (a[j] < a[j + 1]){
			swap(a[j], a[j + 1]);
			k++;
		}
	cout << k << endl;
	while (next_permutation(a + 1, a + n + 1)) cal++;
	cout << cal << endl;
	return 0;
}
