#include<bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std; 
queue<int> f;
	const int fx[4]={0,0,1,-1};
	const int fy[4]={1,-1,0,0};
	struct node{int x,y,z,next;} a[200000];
	int last[1000];
	int n,m,len=-1,ans=0,st,ed;
void ins(int x,int y,int z)
{
	a[++len].x=x;a[len].y=y;a[len].z=z;a[len].next=last[x];last[x]=len;
}
int h[1000];
bool bfs()
{
	memset(h,0,sizeof(h));
	h[st]=1;
	f.push(st);
	while(!f.empty())
	{
		int x=f.front();
		for(int i=last[x];i>=0;i=a[i].next)
		{
			int y=a[i].y;
			if(a[i].z>0&&h[y]==0)
			{
				h[y]=h[x]+1;
				f.push(y);
			}
		}
		f.pop();
	}
	if(h[ed]) return true; else return false;
}
int dfs(int x,int f)
{
	int s=0,t;
	if(x==ed) return f;
	for(int i=last[x];i>=0;i=a[i].next)
	{
		int y=a[i].y;
		if(a[i].z>0&&h[y]==h[x]+1&&f>s)
		{
			s+=(t=(dfs(y,min(f-s,a[i].z))));
			a[i].z-=t;
			a[i^1].z+=t;
		}
	}
	if(!s) h[x]=0;
	return s;
}
int dinic()
{
	int sum=0;
	while(bfs())
		sum+=dfs(st,INF);
	return sum;
}
int main()
{
	int x,id;
	scanf("%d",&n);
	m = n;
	st=0,ed=n*m+1;
	memset(last,-1,sizeof(last));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			ans+=x;
			id=(i-1)*m+j;
			if((i+j)&1) ins(st,id,x),ins(id,st,0); else ins(id,ed,x),ins(ed,id,0);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((i+j)&1)
			{
				for(int k=0;k<=3;k++)
				{
					int t1=i+fx[k],t2=j+fy[k];
					if(t1<=0||t1>n||t2<=0||t2>m) continue;
					id=(i-1)*m+j;
					ins(id,(t1-1)*m+t2,INF),ins((t1-1)*m+t2,id,0);
				}
			}
	printf("%d",ans-dinic());
}
