#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int r;
	double time, a[15][15];
	cin >> r;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= r; j++)
			cin >> a[i][j];
	for (int j = 1; j < r; j++){
		if (a[j][j] == 0){
			cout << '0';
			return 0;
		}
		for (int i = j + 1; i <= r; i++){
			time = a[i][j] / a[j][j];
			a[i][j] = 0;
			for (int k = j + 1; k <= r; k++)
				a[i][k] -= (a[j][k] * time);
		}
		for (int k = 1; k <= r; k++){
			cout << endl;
		for (int l = 1; l <=r; l++)
			cout << a[k][l] << ' ';
		}
	}
	long long result = 1;
	for (int i = 1; i <= r; i++) 
		result *= a[i][i];
	cout << result;
	return 0;
}
