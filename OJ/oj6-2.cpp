#include<iostream>
#include <algorithm>
using namespace std;
const int N = 10 + 5; 
long long a[N][N], b[N][N], c[N][N], d[N][N];

int main(){
	int r;
	cin >> r;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= r; j++)
			cin >> a[i][j];
	int p[N];
	for (int i = 1; i <= r; i++)
		p[i] = i;
	long long result = 0;
	do{
		int tao = 0;
		long long mult = 1;
		for (int i = 1; i <= r; i++)
		 	mult *= a[i][p[i]];
		for (int i = 1; i < r; i++)
			for (int j = i + 1; j <= r; j++)
				if (p[i] > p[j]) tao++;
		if ((tao % 2) == 0) tao = 1;
		else tao = -1;
		result += mult * tao;
	}
	while (next_permutation(p + 1, p + r + 1));
	
	
	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= l; j++)
			cin >> c[i][j];
			
	cout << result;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= l; j++)
			d[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= l; j++){
			for (int k = 1; k <= m; k++)
				d[i][j] += b[i][k] * c[k][j];
			}
	for (int i = 1; i <= n; i++){
		cout << endl;
		for (int j = 1; j <= l; j++)
			cout << d[i][j] << ' ';
	}
} 
