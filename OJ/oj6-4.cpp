/* Please do not introduce '#include <bits/stdc++.h>', otherwise if the namespace 'std' is declared, the definition will conflict with '#include <stack>'. */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

/* We default the absolute value of the elements in the stack will not exceed 10^9, so in the main function, we use the return value -inf to mark the failure of this operation. */
const int inf = 0x3f3f3f3f;    
char s[100005];
/* Used to distinguish our stack and STL stack container. */
namespace MyStack
{
    /* The upper limit of the number of elements in the stack. */
    const int MaxSize = 200000;

    struct stack
    {
        /* Data area in the stack is implemented in the form of an array. The current space is values[0 ~ top - 1]. If top = 0, the stack is empty. */
        int values[MaxSize];

        /*  The position of the top of the stack. */
        int top;

        /*
            initialization
             1,  Clear the data area in the stack.
             2£¬ Assign top to 0.
        */
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
            else{
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

    stack st;
    int T, opt, x;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
    	scanf("%s", &s);
    	int length = strlen(s);
    	st.init();
    	int conornot = 0;
    	int ok = 0;
    	for (int j = 0; j < length; j++){
			if(ok == 1) break;
    		if (s[j] == '(') {
    			opt = 1;
			}
    		else opt = 2;
	        if (opt == 1)
	        {
	            bool status = st.push(x);
	            if (status == false)
	            {
	                printf("the struct is full.\n");
	            }
	        }
	
	        else if (opt == 2)
	        {
	            x = st.pop();
	            if (x == -inf)
	            {
	                printf("no\n");
	                ok = 1;
	                continue;
	            }
	        }
	    }
	    x = st.getNum();
	    if (x != 0) printf("no\n");
	    else if(ok != 1) printf("yes\n");
	}
}
