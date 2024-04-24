#include <iostream>
using namespace std;

const int N = 1e9 + 5;
const int MOD = 10000079;
int n;
long long res = 1;

long long quick_pow(long long a, long long b)
{
   long long ans = 1;
   while (b)
  {
       if (b & 1)
           ans = ans * a % MOD;
       a = a * a % MOD;
       b = b >> 1;
  }
   return ans;
}

int main()
{ 
	
     scanf("%d", &n);
     //ca[0] = ca[1] = 1;
     if (n - 1 <= MOD)
         for (int i = 2; i <= n - 1; i++)
         {
             res = (res * (i) % MOD) % MOD;
             printf("%lld\n", res);
         }
     else printf("0\n");
     res = quick_pow(2, n - 1);
     printf("%lld\n", res);
     return 0;
}
