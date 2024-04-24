#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
unsigned long long base=131;
unsigned long long a[10005];
char s[10010 * 2];
long long n,m,ans=1;
long long prime=233317; 
unsigned long long mod=212370440130137957ll;
unsigned long long hashe(char s[])
{
 long long len=strlen(s);
 unsigned long long ans=0;
 for (long long i=0;i<len;i++)
 ans=(ans*base+(unsigned long long)s[i])%mod+prime;
 return ans;
}
long long main()
{
 scanf("%d%d",&n, &m);
 for(long long i=1;i<=n;i++)
 {
 	scanf("%s",s);
 	a[i]=hashe(s);
 }
 sort(a+1,a+n+1);
 long long cnt = 0;
 for(long long i=1;i<=m;i++)
 {
 	scanf("%s",s);
 	unsigned long long b =hashe(s);
 	for (long long j = 1; j <= n; j++)
 	{
 		if (b == a[j] )
 		{
 			cnt ++;
 			j = n + 1;
		 }
	 }
 }
 prlong longf("%d",cnt);
} 
