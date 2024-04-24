#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

struct node{
    long long l;
    char s;
}n[100010];

bool cmp(node t1, node t2)
{
    return t1.l < t2.l;
}

bool cnf[30];

int solution(string &S, vector<int> &X, vector<int> &Y)
{
    int res, res0 = 0;
    long long len;
    int N = S.length();
    for (int i = 0; i < N; ++i)
    {
        n[i].l = X[i] * X[i] + Y[i] * Y[i];
        n[i].s = S[i];
    }
    sort(n, n + N, cmp);
    for (int i =0; i < N; i++)
    	cout << n[i].l << " ";
    cout << endl; 
    for (res = 0; res < N; ++res){
        if (!cnf[n[res].s - 'A']){
            len = n[res].l;
            cnf[n[res].s - 'A'] = 1;
            res0 = res;
        }
        else if (n[res].l != len) return res;
        else return res0;
    }
        return res;
}

int main()
{
     //string s = "ABDCA";
     //vector<int> X = {2, -1, -4, -3, 3};
     //vector<int> Y = {2, -2, 4, 1, -3};
    string s = "CCD";
    vector<int> X {1,-1,2};
    vector<int> Y {1,-1,-2};
    cout << solution(s,X,Y) << endl;
}

