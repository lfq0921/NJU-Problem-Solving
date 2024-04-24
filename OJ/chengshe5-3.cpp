#include<iostream>
using namespace std;
int m , n, last, num = 0, currentAns = 0;
void solve (int k, int down)
{
    if (k == n + 1) 
    {
        if(currentAns == m)
        {
        num++;
        return;
        }
        return;
    }   
    for (int i = down; i <= m; i++)
    {
        currentAns += i;
        solve(k + 1, i);
        currentAns -= i;
    }
    if ((k == 1) && (down != 0)) cout << "ok" << endl;
    return;
}
 
 
int main()
{
     
    cin >> m >> n;
    solve(1, 0);
    cout << num;
    return 0;
}
