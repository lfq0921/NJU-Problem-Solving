#include<bits/stdc++.h>
using namespace std;
string str;
int i, strLength, dot, first, last;
string c, d;
long long a = 0;
double b = 0;

void funcA(string astr){
	stringstream ss;  ss << astr;  int p; ss >> p;
    a += p;
}

void funcB(){
	for (int p = first; p < dot; p++)
		b += (str[p] - '0') * pow(10, dot - p - 1);
	for (int p = (dot + 1); p <= last; p++)
		b += (str[p] - '0') * pow(10, dot - p);
}

void judge(){ 
	first = i;
	dot = -1;
	while (((str[i] <= '9') && (str[i] >= '0')) || (str[i] == '.')){
		if (str[i] == '.') dot = i;
		i++;
	}
	last = i - 1;
	string sstr = str.substr(first, last - first + 1);
	if (dot != -1) funcB();
	else funcA(sstr);
}

int main(){
	cin >> str;
	strLength = str.length();
	for (i = 0; i < strLength; i++){
			if ((str[i] <= 'Z') && (str[i] >= 'A')){
				c += str[i] - 'A' + 'a';
			}
				
			else if ((str[i] <= 'z') && (str[i] >= 'a'))
				d += str[i] - 'a' + 'A';
			else {
			judge();i--;}
			}
		cout << a << endl;
		cout << setiosflags(ios::fixed) << setprecision(2) << b << endl << c << endl << d;
	}
