#include <iostream>
using namespace std;

void LoopDown (int num) ;
void CircleDown (int num) ;
void LoopUp (int num) ;
void CircleUp (int num) ;
int count = 0;
int N;

void LoopDown (int num)
{
    if (num == 2) 
    {
        CircleDown (2);
        CircleDown (1) ;
        return;
    }
    if (num == 1) 
    {
        CircleDown (1) ;
        return;
    }
    LoopDown (num - 2) ;
    CircleDown (num) ;
    LoopUp (num - 2) ;
    LoopDown (num - 1) ;
    return;
}

void CircleDown ( int num )
{
	printf("down %d\n", num);
    count++;
}

void LoopUp ( int num )
{
    if (num == 2) 
    {
        CircleUp(1) ;
        CircleUp(2) ;
        return;
    }
    if (num == 1) 
    {
        CircleUp(1) ;
        return;
    }
    LoopUp(num - 1) ;
    LoopDown(num - 2) ;
    CircleUp(num) ;
    LoopUp(num - 2) ;
    return;
}

void CircleUp (int num) 
{
	printf("up %d\n", num);
    count ++ ;
    return;
}

int main () 
{
    scanf("%d", &N);
    LoopDown(N);
    printf("%d", count);
    return 0; 
}
