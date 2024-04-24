#include<bits/stdc++.h>
#define ri register long long
using namespace std;
#define gc getchar
template<class T>void read(T&x)
{
    ri f=1,c;while(c=gc(),c<48||57<c)if(c=='-')f=-1;x=c^48;
    while(c=gc(),47<c&&c<58)x=(x<<3)+(x<<1)+(c^48);x*=f;
}
const long long N = 10005, INF = 0x3f3f3f3f;
vector<long long> G[N];
long long Nx,Ny,k;

long long Mx[N],My[N];
long long dx[N],dy[N];
long long dis,u,v;
bool used[N];
bool searchP(){
    queue<long long> Q;
    dis = INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(long long i = 0;i < Nx;++i)
    if(Mx[i] == -1)    Q.push(i), dx[i] = 0;
    while(!Q.empty()){
        long long u = Q.front();Q.pop();
        if(dx[u] > dis) break;
        long long sz = G[u].size();
        for(long long i = 0;i < sz;++i){
            long long v = G[u][i];
            if(dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if(My[v] == -1) dis = dy[v];
                else dx[My[v]] = dy[v] + 1, Q.push(My[v]);
            }
        }
    }
    return dis != INF;
}
bool DFS(long long u){
    long long sz = G[u].size();
    for(long long i = 0;i < sz;++i){
        long long v = G[u][i];
        if(!used[v] && dy[v] == dx[u] + 1){
            used[v] = true;
            if(My[v] != -1 && dy[v] == dis) continue;
            if(My[v] == -1 || DFS(My[v])){
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        } 
    }
    return false;
}
long long MaxMatch(){
    long long res = 0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP()){
        memset(used,false,sizeof(used));
        for(long long i = 0;i < Nx;++i)
        if(Mx[i] == -1 && DFS(i)) ++res;
    }
    return res;
}
long long main()
{
    read(Nx);
	read(Ny);
	read(k);
    while(k--)
	{
		read(u);
		read(v);
		if(v<=Ny) G[u-1].push_back(v-1);
	}
    prlong longf("%d\n",MaxMatch());
}
