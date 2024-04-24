#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n > 0)
    {
        if (n >= 1000)
        {
            n -= 1000;
            cout << "M";
        }
        if ((n < 1000) && (n >= 500))
        {
            if ((n / 100)== 9) 
			{
                cout << "CM";
                if (n != 900) n -= 900;
                else return 0;
            }
            else 
            {
            	n -= 500;
            	cout << "D";    	
			}
            
        }
        if ((n < 500) && (n >= 100))
        {
            if ((n / 100)== 4) 
			{
                cout << "CD";
                if (n != 400) n -= 400;
                else return 0;
            }
            else 
            {
            	n -= 100;
            	cout << "C";
			}
            
        }
        if ((n < 100) && (n >= 50))
        {
            if ((n / 10) == 9) 
			{
                cout << "XC";
                if (n != 90) n -= 90;
                else return 0;
            }
            else 
			{
            	n -= 50;
            	cout << "L";
			}
        }
        if ((n < 50) && (n >= 10))
        {
            if ((n / 10) == 4) 
			{
                cout << "XL";
                if (n != 40) n -= 40;
                else return 0;
            }
            else 
			{
            	n -= 10;
            	cout << "X";
			}
        }
        if ((n < 10) && (n >= 5))
        {
            if (n == 9) 
			{
                cout << "IX";
                return 0;
            }
            else 
			{
            	n -= 5;
            	cout << "V";
			}
        }
        if ((n < 5) && (n >= 1))
        {
            if (n == 4) 
			{
                cout << "IV";
                return 0;
            }
            else 
            {
            	n -= 1;
            	cout << "I";
			}
            
        }
    }
    return 0;
    } 
