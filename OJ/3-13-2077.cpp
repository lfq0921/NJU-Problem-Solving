#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register
const int N=1e4+10,M=5e5+10;

inline int read()
{
	rg int x=0,w=1;
	rg char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
	return x*w;
}

int head[N],ver[M],nxt[M],tot=0;
void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int fa[N];
int find(int x)//并查集
{
	int x_root=x;
	while(fa[x_root]!=x_root) x_root=fa[x_root];
	while(x!=x_root)
	{
		int tmp=fa[x];
		fa[x]=x_root; x=tmp;
	}
	return x_root;
}
int match[N],pre[N];//记录匹配与前驱
int vis[N],dfn[N],tim=0;
int n,m,res=0;

int lca(int x,int y)//求花根
{
  /*dfn是一个标记数组，一边打标即一边上跳，第一个重复点就是花根
	花根一定是一个黑点，所以可以隔点上跳*/
	++tim;
	x=find(x);y=find(y);
	while(dfn[x]!=tim)
	{
		dfn[x]=tim;
		x=find(pre[match[x]]);
		if(y) swap(x,y);
	}
	return x;
}

queue<int> q;
void blossom(int x,int y,int w)//缩奇环(开花)
{
	while(find(x)!=w)
	{
		pre[x]=y;y=match[x];//
		if(vis[y]==2) vis[y]=1,q.push(y);//暴力染黑然后进队
		if(find(x)==x) fa[x]=w;
		if(find(y)==y) fa[y]=w;
		x=pre[y];
	}
}

bool solve(int S)//带花树
{
	for(int i=1;i<=n;i++) fa[i]=i,vis[i]=pre[i]=0;
	while(q.size()) q.pop();

	q.push(S);
	vis[S]=1;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];

			if(find(x)==find(y)||vis[y]==2) continue;//y是白点或是同一花中的点
			if(!vis[y])//y还没有染色
			{
				vis[y]=2; pre[y]=x;
				if(!match[y])//没被匹配
				{
					for(int k=y,p;k;k=p)
						p=match[pre[k]],match[k]=pre[k],match[pre[k]]=k;//修改匹配
					return 1;
				}
				vis[match[y]]=1,q.push(match[y]);//被匹配过了
			}
			else //y是黑色点
			{
				int w=lca(x,y);
				blossom(x,y,w);
				blossom(y,x,w);//缩环两个方向各一次拼起来
			}
		}
	}
	return 0;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add(x,y); add(y,x);
	}

	for(int i=1;i<=n;i++)
		if(!match[i]) res+=solve(i);
	if (res * 2 < n) res += n - res * 2;
	printf("%d\n",res);
	/*for(int i=1;i<=n;i++)
		printf("%d ",match[i]);*/
	return 0;
}

