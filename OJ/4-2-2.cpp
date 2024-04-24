#include <iostream>
using namespace std;
const int N = 1005;
int T, n, k, p[N];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        scanf("%d", &k);
        bool find_cycle = 0;
        int cnt = 0;
        int ori[N] = {0};
        for (int i = 1; i <= n; i++)
            ori[i] = p[i];
        while (!find_cycle)
        {
            int tmp[N];
            for (int j = 1; j <= n; j++)
                tmp[j] = p[j];
            for (int j = 1; j <= n; j++)
                p[j] = tmp[p[j]];
            bool judge = 1;
            for (int j = 1; j <= n; j++)
                if (p[j] != ori[j])
                {
                    judge = 0;
                    break;
                }
            if (judge)
                find_cycle = 1;
            cnt++;
        }
        for (int i = 1; i <= cnt - (k % cnt); i++)
        {
            int tmp[N];
            for (int j = 1; j <= n; j++)
                tmp[j] = p[j];
            for (int j = 1; j <= n; j++)
                p[j] = tmp[p[j]];
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", p[i]);
        printf("\n");
    }
}