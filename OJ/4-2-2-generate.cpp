#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;
int p[100], s[100];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    random_shuffle(p + 1, p + 1 + n);
    for (int i = 1; i < n; i++)
        s[p[i]] = p[i + 1];
    s[p[n]] = p[1];
    for (int i = 1; i <= n; i++)
        printf("%d ", s[i]);
    return 0;
}
