#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+10;
const int base=131;
ull hr[2*N],hl[2*N],p[2*N];
char s[N*2];
ull get_hash(ull h[],int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    int t=1;
    scanf("%s",s+1); 
        int res=0;
        int n=strlen(s+1);
        for(int i=2*n;i>0;i-=2)
        {
            s[i]=s[i/2];
            s[i-1]='z'+1;
        }
        n*=2,p[0]=1;
        for(int i=1,j=n;i<=n;i++,j--)
        {
            hl[i]=hl[i-1]*base+s[i]-'a'+1;
            hr[i]=hr[i-1]*base+s[j]-'a'+1;
            p[i]=p[i-1]*base;
        }
        for(int i=1;i<n;i++)
        {
            int l=0,r=min(i-1,n-i),mid;
            while(r>l)
            {
                mid=l+r+1>>1;
                if(get_hash(hl,i-mid,i-1)==get_hash(hr,n-(mid+i)+1,n-(i+1)+1))
                    l=mid;
                else r=mid-1;
            }
            if(s[i-l]=='z'+1)
               res=max(res,l);
            else res=max(res,l+1);
        }
        printf("%d\n",res);
    return 0;
}
