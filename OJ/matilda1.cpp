#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cer, bre, app, yog, q, p, i;
    cin >> cer >> bre >> app >> yog;
    if (((cer == 1) || (bre == 1)) && (app == 1))
        p = 1;
    else p = 0;
    if (yog == 1)
        q = 1;
    else q = 0;
    if (p == 0)
        i = 1;
    else if (q == 1)
        i = 1;
    else i = 0;
    cout << i;
    return 0;
}
