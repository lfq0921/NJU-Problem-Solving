#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 15 + 5;
int p[N];
int main()
{
    int n = 5; // 可自行更改
    for (int i = 1; i <= n; i++)
      p[i] = i;
    bool flag = true;
    while (flag == true)
    {
      for (int i = 1; i <= n; i++)
        printf("%d ", p[i]);
      printf("\n");
      flag = next_permutation(p + 1, p + n + 1);
    }
  return 0;
}
