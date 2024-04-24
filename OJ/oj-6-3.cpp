#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 25 + 5;
const int inf = 0x3f3f3f3f;
int v[N], k, n;
long long res = 0, theMax = -inf;

long long MyPow(int a, int b){
	long long thepow = 1;
	if (b == 0) return 1;
	if(b > 0){
		for (int i = 1; i <= b; i++)
			thepow *= a;
		return thepow;
	}
}
void dfs(int depth, int down){
	if (depth == (k + 1)) {
		if (res > theMax) theMax = res;
		return;
	}
	for (int i = down; i <= n; i++){
		if (i != down) {
			res -= v[i - 1] * MyPow(3, k - depth);
		}
		res += v[i] * MyPow(3, k - depth);
		dfs(depth + 1, i + 1);
		if (i == n) res -= v[i] * MyPow(3, k - depth);
	}
}

int main(){
	memset(v, 0, N);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	dfs(1, 1);
	cout << theMax;
	return 0;
} 
