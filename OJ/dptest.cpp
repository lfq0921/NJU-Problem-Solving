#include <iostream>
#include <algorithm>
#define N 1002
using namespace std;
int f[N];
int w[N];
int v[N];
int s[N];
int main()
{
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = W; j >= w[i]; j--)
        {
            for (int k = 0; k <= s[i] && k * w[i] <= j; k++)
            {
                f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << f[W] << endl;
    return 0;
}
