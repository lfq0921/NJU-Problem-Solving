#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

const int N = 3e7 + 5;
// bool isprime[MAXN];
bitset<N> isprime; // 初始化为0
int prime[N];
int cnt = 0, n;

void get_prime(int n)
{
    isprime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i] == 0)
        {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime
                                                [j] <=
                                        n;
             j++)
        {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
// 最终的prime就保存了n以内的所有质数

int main()
{
    get_prime(N);
    scanf("%d", &n);
    while (n--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r < l || r <= 0)
            printf("0\n");
        else
        {
            // auto it1 = lower_bound(prime + 1, prime + cnt + 1, l); // 第一个大于等于l的位置
            // auto it2 = upper_bound(prime + 1, prime + cnt + 1, r); // 第一个大于r的位置
            int ans = upper_bound(prime + 1, prime + cnt + 1, r) - lower_bound(prime + 1, prime + cnt + 1, l);
            if (ans > 0)
                cout << ans << endl; // 范围[l, r]中的数字个数
            else
                printf("0\n");
        }
    }
    return 0;
}