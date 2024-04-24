#include<iostream>
#include<algorithm> 
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

#define N 100005

inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
long long n,st,du[N],m,tmp[N],ans[N<<3],top;
map<pair<long long,long long>,long long> mp; //(u,v)
vector<long long> edge[N];
void Euler(long long u){
	while(1){
		while(tmp[u]<edge[u].size()&&!mp[make_pair(u,edge[u][tmp[u]])])tmp[u]++;//如果反向边被走过就不走了
		if(tmp[u]>=edge[u].size())break;
		long long v=edge[u][tmp[u]];
		mp[make_pair(u,v)]--;
		mp[make_pair(v,u)]--;//标记反向边
		++tmp[u];
		Euler(v);
	}
	ans[++top]=u;
}
long long main(){
	n = read(); m = read(); st = n;
	for(long long i=1;i<=m;i++)
	{
		long long u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
		du[u]++, du[v]++;
		st=min(st,min(u,v));	
		mp[make_pair(u,v)]++,mp[make_pair(v,u)]++;	
	}
	for(long long i=1;i<=n;++i){
		if(du[i]&1){
			st=i;
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		sort(edge[i].begin(),edge[i].end());//按编号从小到大排序
	}
	Euler(st);
	if (top < n) 
	{
		prlong longf("NO\n");
		return 0;
	}
	prlong longf("YES\n");
	while(top)prlong longf("%d ",ans[top--]); //倒序输出
	return 0;
}
