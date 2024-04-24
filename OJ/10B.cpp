#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define long long long long
using namespace std;
const long long INF=1e9;
long long n,m,T,tot=1,s,t;
long long dir;
long long deg[5000],head[5000],deep[5000],cur[5000],vis[5000],bok[5000],ug[5000],vg[5000];
queue<long long>q;
struct node {
	long long u,v,w,nxt;
}e[5000];

template <class T> inline void read(T&x){
	bool f;char ch=getchar();
	for(f=false;!isdigit(ch);ch=getchar())if(ch=='-')f=true;
	for(x=0;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	x*=f==1?-1:1;
}

inline void add(long long u,long long v,long long w){
	e[++tot]=(node){u,v,w,head[u]};
	head[u]=tot;
}

inline long long abs(long long x){
	if(x<=0) return -x;
	else return x;
}

inline bool bfs(long long s,long long t){
//	cout<<"[Error!] inside bfs"<<endl;
	for(long long i=1;i<=n+5;i++) deep[i]=0;
	for(long long i=1;i<=n+5;i++) cur[i]=head[i];
	deep[s]=1;q.push(s);
	while(!q.empty()){
		long long u=q.front();q.pop();	
		for(long long i=head[u];i!=0;i=e[i].nxt){
			long long v=e[i].v,w=e[i].w; 
			if(deep[v]==0&&w!=0){
				deep[v]=deep[u]+1;
				q.push(v);
			}
		} 
	} 
	if(deep[t]!=0) return true;
	return false;
}

inline long long dfs(long long now,long long t,long long limit){
//	cout<<"[Error!] inside dfs"<<endl;
	if(!limit||now==t) return limit;
	long long flow=0,f=0;
	for(long long i=cur[now];i;i=e[i].nxt){
		cur[now]=i;
		if(deep[e[i].v]==deep[now]+1&&(f=dfs(e[i].v,t,min(limit,e[i].w)))){
			flow+=f;
			limit-=f;
			e[i].w-=f;
			e[i^1].w+=f;
			if(!limit) break;
		}
	}
	return flow;
}

inline long long work(long long s,long long t){long long R=0;while(bfs(s,t))R+=dfs(s,t,INF);return R;}

inline bool solve(){
	long long sum=0;
	for(register long long i=1;i<=n;i++){
		if(deg[i]&1) {return false;}
		if(deg[i]>0) {
			add(s,i,deg[i]/2);add(i,s,0);
			sum+=(deg[i])/2;
		}
		if(deg[i]<0) {add(i,t,-deg[i]/2);add(t,i,0);}
	}
	return sum==work(s,t);
}

vector<long long> E[2004];

void Euler(long long x) {
  while (!E[x].empty()) {
    long long y = E[x].back(); E[x].pop_back();
    Euler(y);
    //prlong longf(" %d",x);
  }
}

inline void find(){
	for(long long i=1;i<=n;i++) E[i].clear();
	for(long long i=1;i<=m;i++){
		if(bok[i]>=1&&!e[bok[i]].w) E[ug[i]].push_back(vg[i]);
		else E[vg[i]].push_back(ug[i]);
	}
	//prlong longf("1");
    Euler(1);
    //puts("");
}

inline void clean(){
	memset(vis,0,sizeof(vis));memset(bok,0,sizeof(bok));
	memset(e,0,sizeof(e));memset(vg,0,sizeof(vg));
	memset(ug,0,sizeof(ug));memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));memset(deg,0,sizeof(deg));
} 
 
signed main(){ 
//	freopen("t1.in","r",stdin);
//	freopen("my.out","w",stdout);
//	long long sss;
	read(T);//read(sss);
	while(T--){
		tot=1;
		clean();
		read(n),read(m);s=n+3,t=n+4;
		for(long long u,v,i=1;i<=m;i++){
			read(u),read(v),read(dir); 
			ug[i]=u;vg[i]=v;
			deg[u]++,deg[v]--;
			if(dir == 0) bok[i]=tot+1,add(u,v,1),add(v,u,0);
		}
		
		if(solve()) {
		cout<<"possible"<<endl;
		//	find();
		}
		else puts("impossible");
		 //if(T) puts("");
	}
	return 0;
}
