#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e13;
long long n,m,u,v,w,ans = inf;
long long dis[205][205];
long long mp[205][205];
int main()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			if(i!=j)dis[i][j]=mp[i][j]=inf;
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
	}
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<k;i++)
			for(long long j=i+1;j<k;j++)
				ans = min(ans,dis[i][j]+mp[i][k]+mp[k][j]);
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		
	}
	if(ans==inf)cout<<"-1";
	else cout<<ans;
	return 0;
	return 0;
}
