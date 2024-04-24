#include<bits/stdc++.h>
using namespace std;
int n,m,F[105],f[105][66][66],start[70],cnt=0,gs[200];
bool mp[105][30];

int main()
{
	scanf("%d%d", &n, &m);
	char a;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a; 
			if(a=='H')mp[i][j]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			F[i]=(F[i]<<1)+mp[i][j];
		}
	}
	
	start[++cnt]=0;
	
	for(int i=1;i<(1<<m);i++){
		if(i&(i<<1))continue;	
		if(i&(i<<2))continue;
		if(i&(i>>1))continue;
		if(i&(i>>2))continue;
		start[++cnt]=i;
		int x=i;
		while(x)
		{	
			gs[cnt]++;
			x-=(x&(-x));
		}
	}
	
	for(int i=1;i<=cnt;i++){	
		if((start[i]&F[1])==0){	
			f[1][i][0]=gs[i];
		}	
	}
	
	for(int i=1;i<=cnt;i++){	
		if((start[i]&F[2])==0)
		for(int j=1;j<=cnt;j++){
			if((start[i]&start[j])==0&&(start[j]&F[1])==0)
			{
				f[2][i][j] =gs[j]+gs[i];
			} 
		}
	}
	for(int i=3;i<=n;i++){		
		for(int j=1;j<=cnt;j++){			
			if((start[j]&F[i])==0){	
				for(int k1=1;k1<=cnt;k1++){				
					if((start[j]&start[k1])==0&&(start[k1]&F[i-1])==0){						
						for(int k2=1;k2<=cnt;k2++){					
							if((start[j]&start[k2])==0&&(start[k1]&start[k2])==0&&(start[k2]&F[i-2])==0){	
                            			
								f[i][j][k1]=max(f[i][j][k1],f[i-1][k1][k2]+gs[j]);//从之前转移过来就行
							}
						}
					}
				}
			} 	
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			ans=max(ans,f[n][i][j]);
		}
	}
	printf("%d", ans);
}
