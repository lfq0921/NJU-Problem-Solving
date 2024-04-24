#include <iostream>
using namespace std;

int T, a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &a, &b, &c);
        bool mod2 = 0;
        bool mod1 = 0;
        mod2 = !(a % 2 || b % 2 || c % 2);
        mod1 = a % 2 && b % 2 && c % 2;
        if (mod2 || mod1)
        {
            printf("y\n");
            for (int i = 1; i <= a; i++)
                printf("1 ");
            for (int i = 1; i <= b; i++)
                printf("2 ");
            for (int i = 1; i <= c; i++)
                printf("3 ");
            printf("\n");
        }
        else
            printf("n\n");
    }
}