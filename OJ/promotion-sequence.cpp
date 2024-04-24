#include <iostream>
using namespace std;

const int N = 1e9 + 5;
const int MOD = 10000079;
int n;
long long ca[N];

int main()
{
    scanf("%d", &n);
    ca[0] = ca[1] = 1;
    for (int i = 2; i <= n - 1; i++)
        for (int j = 0; j <= i - 1; j++)
            ca[i] = (ca[i] + ca[j] * ca[i - j - 1]) % MOD;
    printf("%lld\n", ca[n - 1]);
    return 0;
}
