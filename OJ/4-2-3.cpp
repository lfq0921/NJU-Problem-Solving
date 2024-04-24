#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 998244353;
int T, n, k;

inline int gcd(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        long long sum = 0;
        scanf("%d%d", &n, &k);
        int s[N] = {0};
        for (int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        sort(s + 1, s + n + 1, greater<int>());
        int cnt = 1;  // 记录下一个要分配的s数组元素是第几号
        int newbegin; // 这组兔子开始的第一个编号
        int num;
        num = gcd(n, k);
        int z = n / num;              // 该组兔子的只数
        for (int i = 0; i < num; i++) // 找不同组的兔子, 每一组兔子的组头
        {
            long long f[n] = {0}; // 第i组兔子的friend值 清空
            newbegin = cnt;       // 这组兔子开始的第一个编号newbegin
            cnt += z;
            if (z == 1)
                sum = (sum + (s[i + 1] * s[i + 1]) % MOD) % MOD;
            else
            {
                sum = (sum + (s[i * z + 1] * s[i * z + 2]) % MOD) % MOD;     // 最大的两个数相邻
                sum = (sum + (s[i * z + z] * s[i * z + z - 1]) % MOD) % MOD; // 最小的两个数相邻
                for (int j = 1; j <= z - 2; j++)
                    sum = (sum + (s[i * z + j] * s[i * z + j + 2]) % MOD) % MOD;
            }
            /*f[z / 2 + 1] = s[newbegin]; // 最中间的那个数, 最大
            int scnt = newbegin + 1;
            for (int j = 1; j <= z / 2; j++)
            {
                if (z / 2 + 1 + j <= z)
                    f[z / 2 + 1 + j] = s[scnt++];
                if (z / 2 + 1 - j >= 1)
                    f[z / 2 + 1 - j] = s[scnt++];
            }
            for (int j = 1; j <= z; j++)
                sum = (sum + (f[j] * f[j % z + 1]) % MOD) % MOD;
            if (cnt > n)
                i = k + 1;*/
        }
        printf("%lld\n", sum);
    }
}