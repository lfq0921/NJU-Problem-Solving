#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
struct Node
{
	ll x;
	ll y;
}node[200005];

long long dis2(Node a, Node b)
{
	long long x2 = (a.x - b.x) * (a.x - b.x);
	long long y2 = (a.y - b.y) * (a.y - b.y);
	return x2 + y2;
 } 
ll cross (Node a, Node b, Node c)//²æ»ý
{
	return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

int main()
{
	freopen("10.in", "r", stdin);
	freopen("10test.out", "w", stdout);
	scanf("%d", &T);
	int ini = T;
	while(T--)
	{
		int n;
		cin >> n;
		int ymax = -1e9, ymin = 1e9;
		int ymaxidx, yminidx;
		int p, q;
		for (int i = 0; i < n; i++)
		{
			cin >> node[i].x >> node[i].y;
		}
		ll ans = dis2(node[0], node[1]);
		int idx1 = 0, idx2 = 1;
		node[n] = node[0], node[n + 1] = node[1];
		for (int q = 0; q < n; q++)
		{
			while(cross(node[q + 1], node[p + 1], node[q]) > cross(node[q + 1], node[p], node[q])) 
			{
				if (p == 294 && (q == 45324)) printf("duibi: 295:%lld, 294:%lld\n", cross(node[q + 1], node[p + 1], node[q]), cross(node[q + 1], node[p], node[q]));
				p = (p + 1) % n;
				if (p == 316 && (q == 45324)) printf("right judge!\n");
			}
			if (q == 45325) printf("if q == 45325, p = %d\n", p);
			ll tmp = dis2(node[p], node[q]);
			if (ans < tmp) ans = tmp, idx1 = p, idx2 = q;
			tmp = dis2(node[p], node[q + 1]);
			if (ans < tmp) ans = tmp, idx1 = p, idx2 = (q + 1) % n;
		}
		/*if(idx2 == 45325 && idx1 == 294) printf("316 45325 12925730365897570\n");*/
		/*else*/ printf("%d %d %lld\n", idx1, idx2, ans);
		if (T == ini - 1) printf("right answer = %lld\n", dis2(node[45325], node[316]));
		
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
