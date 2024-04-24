#include <iostream>
using namespace std;
// 1.代数系统:输入即代数系统(?)集合，及集合上定义的若干封闭的运算
// 2.半群:有结合律的代数系统
// 3.独异点:有identity element的半群
// 4.幺半群:存在单位元的半群       4399
// 5.群:有inverse的独异点
const int N = 55;
bool asso = 1, id = 1, inverse = 1;
int n, type, id_num;
int a[N][N];

bool semi()
{
    // 判断半群(结合律)遍历判断(?)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                int ans1 = a[i][j];
                int ans2 = a[j][k];
                if (ans1 != ans2)
                    return 0;
            }
    return 1;
}

bool myIdentity()
{
    // 判断单位元
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != j)
            {
                id = 0;
                break;
            }
            if (j == n && a[i][j] == j)
            {
                id_num = i;
                i = n + 1;
            }
        }
    return id;
}

bool inver()
{
    // 判断逆元
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != id_num)
                break;
            if (j == n && a[i][j] == id_num)
                return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    type = 1; // 肯定至少是一个代数系统 吧
    asso = semi();
    id = myIdentity();
    inverse = inver();
    if (asso)
    {
        type++; // type = 2;
        if (id)
        {
            type += 2; // type = 4;
            if (inverse)
                type++; // type = 5;
        }
    }
    printf("%d", type);
}