#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t, u, v;
long long w,ans,dis[520010];
long long tot=1,vis[520010],pre[520010],head[520010],flag[2510][2510];

struct node {
	long long to,net;
	long long val;
} e[520010];

inline void add(long long u,long long v,long long w) {
	e[++tot].to=v;
	e[tot].val=w;
	e[tot].net=head[u];
	head[u]=tot;
	e[++tot].to=u;
	e[tot].val=0;
	e[tot].net=head[v];
	head[v]=tot;
}

inline long long bfs() 
{  
	for(register long long i=1;i<=n;i++) vis[i]=0;
	queue<long long> q;
	q.push(s);
	vis[s]=1;
	dis[s]=2005020600;
	while(!q.empty()) {
		long long x=q.front();
		q.pop();
		for(register long long i=head[x];i;i=e[i].net) {
			if(e[i].val==0) continue; 
			long long v=e[i].to;
			if(vis[v]==1) continue;  
			dis[v]=min(dis[x],e[i].val);
			pre[v]=i;  
			q.push(v);
			vis[v]=1;
			if(v==t) return 1;  
		}
	}
	return 0;
}

inline void update() 
{  
	long long x=t;
	while(x!=s) {
		long long v=pre[x];
		e[v].val-=dis[t];
		e[v^1].val+=dis[t];
		x=e[v^1].to;
	}
	ans+=dis[t];  
}

long long main() {
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(register long long i=1;i<=m;i++) {
		scanf("%d%d%lld",&u,&v,&w);
		if(flag[u][v]==0) {  
			add(u,v,w);
			flag[u][v]=tot;
		}
		else {
			e[flag[u][v]-1].val+=w;
		}
	}
	while(bfs()!=0) {  
		update();
	}
	prlong longf("%lld",ans);
	return 0;
}
