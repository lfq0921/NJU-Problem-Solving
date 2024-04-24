#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100000+5;

struct station
{
	string name;
	int time;
	vector<int> train;
	int num;
};
vector<station> s;

bool cmp(station a, station b)
{
	return (a.num < b.num);
}

struct train
{
	string nameOfStation;
	int arrivalTime;
};
vector<train> t;
/*struct edge
{
	string from;
	string to;
};*/
vector<pair<int, int>> e[N]; // edge connected with vertex-N
void addedge(string x, string y, int num)
{
	int a, b;
	for (int i = 0; i < t.size(); i++)
	{
		if(x == t[i].name) a = i;
		if(y == t[i].name) b = i;
	}
    e[a].push_back(b);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string na;
		cin >> na;
		int ti;
		scanf("%d", &ti);
		station a;
		a.name = na;
		a.time = ti;
		a.num = i;
		s.push_back(a);
	 } 
	 sort(s, s + s.size(), cmp);
	 /*part2*/
	 scanf("%d", &m);
	 for (int i = 1; i <= m; i++)
	 {
	 	int s;
	 	scanf("%d", &s);
	 	for (int j = 1; j <= s; j++)
		{
			string na;
			cin >> na;
			int ti;
			scanf("%d", &ti);
			train tr;
			tr.arrivalTime = ti;
			tr.nameOfStation = na;
			t.push_back(tr);
			addedge(t.nameOfStation)
		} 
	 }
	 
	 /*part3*/
	 string departure, dest;
	 cin >> departure >> dest;
	 int destTime;
	 scanf("%d", &destTime);
	 
	 if (n = 7)
	 
	 for (int i = 1; i <= m; i++)//分别在两列车上找
	 {
	 	for (j = 0; j < t.size(), j++)
	 	{
	 		if (t[j].name == departure)
	 		
		 }
	  } 
	return 0;	 
}
	 
	 
	 
	 
