#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 555;

__int128 f[N][N];       // f[i][j]表示当前行剩下区间为[i, j]时的最大颜值
__int128 value[N];      //记录每个物品的帅气值
void output(__int128 x) //__int128的输出
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        output(x / 10);
    putchar(x % 10 + '0');
}
__int128 read() //__int128的读入
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    __int128 ans = 0;
    for (int k = 1; k <= n; k++) // n行是独立的，所以可以单独计算
    {
        memset(f, 0, sizeof f); //每行计算前清空f[]
        for (int i = 1; i <= m; i++)
            value[i] = read();
        for (int i = 1; i <= m; i++)
            for (int j = m; j >= i; j--)
            {
                __int128 left = f[i - 1][j] + (value[i - 1] * value[i - 1] * value[i - 1] * (m - j + i - 1) * (m - j + i - 1));
                __int128 right = f[i][j + 1] + (value[j + 1] * value[j + 1] * value[j + 1] * (m - j + i - 1) * (m - j + i - 1));
                f[i][j] = left;                //由于f[]数组一开始全部赋值为0，所以如果f[i-1][j]和f[i][j+1]都是负数则会出现max取0，答案就不对了。需要先赋一个值。
                f[i][j] = max(right, f[i][j]); //动态规划状态方程
                // f[i][j] = max(f[i-1][j]+value[i-1]*次数^2,f[i][j+1]+value[j+1]*次数^2)

                if (i == 1 && j != m) //处理只能选右边，但是右边值为负数的情况
                    f[i][j] = right;
                else if (j == m) //处理只能选左边，但是左边值为负数的情况
                    f[i][j] = left;
            }
        __int128 maxn = f[1][m];
        for (int i = 1; i <= m; i++) //补充处理f[i][i] 把最后一次的值加上
            f[i][i] = max(f[i][i], (f[i][i] + (value[i] * value[i] * value[i] * m * m)));

        for (int i = 1; i <= m; i++) //由于最后的答案一定在一段区间f[i][j]所以遍历一遍寻找最大值即为该行答案
            for (int j = m; j >= i; j--)
                maxn = max(f[i][j], maxn);
        ans += maxn; //所有行的答案相加即为最终答案
    }
    output(ans);
    return 0;
}
