/*中国剩余定理。
如果k是a_1,a_2,...,a_n的最小公倍数，那么Bob一定能猜出x(mod k)的值。*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll n, k, a[N];                                       // 没给i范围啊...
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; } // 求最大公约数
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int main()
{
    cin >> n >> k; // 输入n和k
    for (int i = 1; i <= n; i++)
        cin >> a[i]; // 输入a数组
    ll g = a[1];     // 初始化g为a_1
    ll l = a[1];
    for (int i = 2; i <= n; i++)
    {
        k /= gcd(k, a[i]); // 求a数组的最大公约数
        if (k == 1)
            break;
        /*l = lcm(l, a[i]);// 求a数组的最小公倍数
        if(g!= 0) k /= g;*/
    }
    if (k == 1)
        cout << "Bob" << endl; // 如果k是a数组的最小公倍数，输出Bob
    else
        cout << "Alice" << endl; // 否则输出Alice
    return 0;
}