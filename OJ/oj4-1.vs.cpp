#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
char tow[5][25], han[15][25], ch;
void move(int m, int a, int b) 
{
    printf("Move %s from %s to %s.\n", han[m], tow[a], tow[b]);
}

void work(int m, int a, int b, int c) 
{
    if (m == n) move(m, a, b);
    else 
    {
        work(m + 1, a, c, b);
        move(m, a, b);
        work(m + 1, c, b, a);
    }
}

int main() 
{
    scanf("%d\n", &n);
    for (int i = 1; i <= 3; i++)
        gets(tow[i]);
    for (int i = 1; i <= n; i++)
        gets(han[i]);
    work(1, 1, 2, 3);
    return 0;
}