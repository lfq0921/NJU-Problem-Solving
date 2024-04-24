#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int inf = 0x3f3f3f3f;

namespace MyStack
{
    const int MaxSize = 200000;

    struct stack
    {
        int values[MaxSize];
        int top;
        void init()
        {
            for (int i = 0; i < MaxSize; i++)
            	values[i] = 0;
            top = 0;
        }

        /*
            Put x on the top of the stack.
            If the stack is full at this time (top == MaxSize), this operation is invalid, and return false.
            Otherwise, add x to the top of the stack and return true.
        */
        bool push(int x)
        {
            if (top == MaxSize) return false;
            else {
            	top++;
            	values[top] = x;
            	return true;
			}
        }

        /*
            Pop the top element of the stack.
            If the stack is empty(top == 0), return -inf, which means the operation is invalid.
            Otherwise, clear the top element of the stack to 0 and update the top position. Return value? look for the main function and the output description.
        */
        int pop()
        {
            if (top == 0) return -inf;
            else {
            	int temp = values[top];
            	values[top] = 0;
            	top--;
            	return temp;
			}
        }

        /*
            Get the top element of the stack.
            If the stack is empty(top == 0), return -inf, which means this operation is illegal.
            Otherwise, return the top element of the stack.
        */
        int getTop()
        {
            if (top == 0) return -inf;
            else return values[top];
        }

        /*
            Returns the number of elements in the stack (return 'top').
        */
        int getNum()
        {
            return top;
        }
    };
}

int main()
{
    /* Declare to use the namespace MyStack, otherwise we cannot introduce the struct we defined under MyStack. */
    using namespace MyStack;

    stack s1, s2;
    int n, m;
    scanf("%d", &n);
    s1.init();
    s2.init();
    for (int i = 0; i < n; i++)
    {
        int opt, x;
        scanf("%d", &opt);
        if (opt == 1)
        {
        	x = s1.pop();
        	if (x == -inf) 
			{
				printf("invalid option 1\n");
				continue;
			}
        	else bool status = s2.push(x);
        }

        else if (opt == 2)
        {
            x = s2.pop();
            if (x == -inf)
            {
                printf("invalid option 2\n");
                continue;
            }
            bool status = s1.push(x);
            if (status == false)
            {
                printf("The stack1 is full.\n");
            }
        }

        else if (opt == 3)
        {
            scanf("%d", &x);
            bool status = s1.push(x);
            if (status == false)
                printf("The stack1 is full.\n");
        }

        else if (opt == 4)
        {
            x = s1.pop();
            if (x == -inf) printf("invalid option 4\n");
        }
        else if (opt == 5)
        {
        	x = s1.getTop();
        	if (x == -inf) printf("invalid option 5\n");
        	else printf("%d\n", x);
		}
		else if (opt == 6)
		{
			x = s1.getNum();
         	printf("%d\n", x);
		}
    }
    return 0;
}
