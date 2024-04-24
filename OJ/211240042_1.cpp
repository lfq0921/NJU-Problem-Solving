#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int num[55];
int cal = 0;
void findnum(int begin, int end, string s)
{
    for (int i = begin; i <= end; i++)
    {
        num[cal] += (s[i] - '0') * pow(10, end - i);
    }
}
int main()
{
    memset(num, 0, 55);
    int begin = 0;
    string s;
    cin >> s;
    int len = s.length();
    int i = 0;
    while(i < len)
    {
        bool po = true;
        if (s[i] == '+') 
            i++;
        if (s[i] == '-')
        {
            i++;
            po = false;
        }
        while ((s[i] <= '9') && (s[i] >= '0'))
        {
            if ((s[i- 1] == '-') || (s[i - 1] == '+')) begin = i;
            if ((s[i + 1] > '9') || (s[i + 1] <= '0')) 
            {
                int end = i;
                cal++;
                findnum(begin, end, s);
                if (!po) num[cal] = - num[cal];
            }
            i++;
        }
    }
    for (int i = 1; i <= cal; i++)
    for (int j = 1; j < cal; j++)
        if (num[j] > num[j + 1]) swap(num[j], num[j + 1]);
    for (int i = 1; i <= cal; i++)
    {
        if (i != cal) cout << num[i] << '+';
        else cout << num[i];
    }
    return 0;
}
