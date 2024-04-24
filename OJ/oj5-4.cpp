#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x[100005], note[100005], last;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	int k = 0;
	for (int i = 1; i <= n; i++){
		if (x[i] == 0) {
			k++;
			note[k] = i;
			last = i;
		}
	}
	note[k + 1] = -1;
	k = 1;
	for (int i = 1; i <= n; i++){
		if (i > last) 
			cout << "overflow" << endl; 
		int d = note[k] - i;
		if (i < note[k]) 
			cout << d << endl; 
		else if (i == note[k]){
			k++;
			cout << '0' << endl;
		}
	}
	return 0; 
	} 
