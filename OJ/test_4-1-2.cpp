#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int N = 50 + 7;
int val[N][N];
int n;
bool _end = false;
int ans = 1;
int id = -1; // 单位元
int ny[N];   // 表示这个元素是否有逆元
void judge_banqun()
{
    if (_end == true)
        return;
    // 检查结合律
    /*int semi_group(int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                int x = matrix[i][j];
                int y = matrix[j][k];
                if (matrix[x][k] != matrix[i][y])
                    return 0;
            }
    return 1;
}*/
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                int tmp1 = val[val[i][j]][k];
                int tmp2 = val[i][val[j][k]];
                // printf("i=%d,j=%d,k=%d, tmp1=%d, tmp2 = %d\n", i, j, k, tmp1, tmp2);
                if (tmp1 != tmp2)
                {

                    _end = true;
                    return;
                }
            }
        }
    }
    ans = 2;
}
void judge_yaobanqun()
{
    /*int monoid(int n)
{
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        for (; j <= n; j++)
        {
            if (matrix[i][j] != j || matrix[j][i] != j || matrix[i][j] != matrix[j][i])
            {
                break;
            }
        }
        if (j == n + 1)
        {
            the_e = matrix[i][i];
            return 1;
        }
    }
    return flag;
}*/
    if (_end == true)
        return;
    for (int i = 1; i <= n && id == -1; i++)
    {
        if (val[1][i] == 1 && val[i][1] == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!(val[i][j] == j && val[j][i] == j))
                    break;
                if (j == n)
                    id = i;
            }
        }
    }
    if (id == -1)
        _end = true;
    else
        ans = 4;
    return;
}
void judge_qun()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (val[i][j] == id && val[j][i] == id)
                ny[i] = ny[j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ny[i] == 0)
        {
            _end = true;
            return;
        }
    }
    ans = 5;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &val[i][j]);
            if (!(val[i][j] >= 1 && val[i][j] <= n))
                _end = true; // 满足封闭性
        }
    }
    judge_banqun();
    judge_yaobanqun();
    judge_qun();
    printf("%d\n", ans);
    return 0;
}