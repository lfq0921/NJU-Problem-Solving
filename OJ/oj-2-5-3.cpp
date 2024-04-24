#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;
const int N = 1000000 + 5;
bool vis[N];
int a[N], MAX[N], MIN[N];
int n, k, countt;
int judgeMax, judgeMin;

int main()
{
    scanf("%d%d", &n, &k);
    int sum = 0;
    int loc1 = 0, loc2 = 0; 
    int maxx; 
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == 1 && i < n) loc1 = i, sum = 1;
     }
     
     maxx = a[n];
    
    // 最后一项为k-1 且前面存在1 
    if (sum == 1 && a[n] == k - 1)
    {
    	judgeMax = 1;
        countt = 1;
        while (countt < n)
        {
        	if (countt != loc1) 
			{
				MAX[countt] = a[countt];
				countt++;
			}
        	else MAX[countt++] = 1;
		}
		MAX[n] = 0;
        goto find_min;
    }
    //存在进位情况
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] + maxx >= k)
        {
        	judgeMax = 1;
            for (int j = n; j > i; j--)
            {
                if (a[i] + a[j] >= k)
                {
                		int tmpi = a[i];
                		int tmpj = a[j];
                		a[j] = (a[i] + a[j]) % k;
                		a[i] = 1;
						countt = 1;
						while (countt <= n) 
						{
							MAX[countt] = a[countt];
							countt++;
						}
						a[i] = tmpi;
						a[j] = tmpj;
                    goto find_min;
                }
            }
        }
        else
        {
            maxx = max(maxx, a[i]);
        }
    }
    
    // 没有进位情况 
    judgeMax = 0;
    MAX[1] = a[1] + a[2];
	countt = 2;
	while (countt < n) 
	{
		MAX[countt] = a[countt + 1];
		countt++;
	}
    
    
    // find_min
    find_min:
    int minn = a[n], cnt = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] + minn < k) vis[i] = true, cnt++;
        minn = min(minn, a[i]);
    }
    
    //存在不进位的情况 
    if (cnt)
    {
    	judgeMin = 0;
        //存在拐点 
        for (int i = 1; i < n; i++)
        {
            if (vis[i] && a[i] > a[i + 1])
            {
                for (int j = n; j > i + 1; j--)
                {
                    if (a[i] + a[j] < k)
                    {
                        countt = 1;
						int count_a = 1;
						int tmpj = a[j];
						a[j] = a[i] + a[j];
						while (countt <= n - 1)
						{
							if (count_a != i) 
							{
								MIN[countt++] = a[count_a++];
							} 
							else count_a++;
						}
						a[j] = tmpj;
                        goto To_print;
                    }
                }
            }
        }
        
        // 不存在拐点 
        for (int i = n; i >= 1; i--)
        {
            if (vis[i])
            {
                for (int j = n; j > i; j--)
                {
                    if (a[i] + a[j] < k)
                    {
                        countt = 1;
						int count_a = 1;
						int tmpj = a[j];
						a[j] += a[i];
						while (countt <= n - 1)
						{
							if (count_a != i) 
							{
								MIN[countt++] = a[count_a++];
							} 
							else count_a++;
						}
						a[j] = tmpj;
                        goto To_print;
                    }
                }
            }
        }
    }
    //一定需要进位 
    else
    {
        MIN[1] = 1;
        MIN[2] = (a[1] + a[2]) % k; 
		countt = 3;
		while (countt <= n) 
		{
			MIN[countt] = a[countt];
			countt++;
		}
		judgeMin = 1;
    }
    
    To_print:
    	bool prev0 = true;
		for (int i = 1; i <= n - 1 + judgeMax; i++)
		{
			if (MAX[i] != 0) prev0 = false; 
			if (!prev0) printf("%d ", MAX[i]);
		}
		cout << endl;
		prev0 = true;
		for (int i = 1; i <= n - 1 + judgeMin; i++)
		{
			if (MIN[i] != 0) prev0 = false; 
			if (!prev0) printf("%d ", MIN[i]);
		}
    return 0;   
}
