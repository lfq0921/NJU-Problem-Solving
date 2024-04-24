#include<bits/stdc++.h>
using namespace std;

int father[4000004];
long long ans=0;
int k = 1;
int temp;
const long long mod=998244353;

struct node
{
	int p;
	int next;
	int val;
}nod[N];
//²é 
void makeset(x)
{
	
}
int find(int k)
{
	if(father[k] != k) 
		father[k] = find(father[k]);
	return father[k];
}
//²¢
void unionn(int x,int y)
{
	if(x>y) temp=x,x=y,y=temp;
	x=find(x);
	y=find(y);
	if(x!=y)
		father[y]=x;
} 

int main()
{
	int m,n,i,a,b,s1,s2,op;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		father[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&op,&a,&b);
		if(op==0)
		{
			unionn(a,b);
		}
		else
		{
			if(find(a)==find(b))
			{
				ans*=2;
				ans++;
				ans%=mod;
			}
			else
			{
				ans*=2;
				ans%=mod;
			}
					
		}
	}	
	cout<<ans<<endl;
	return 0;
}

