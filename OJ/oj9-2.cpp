#include <bits/stdc++.h>
using namespace std;
const int MaxN = 505;
const int MaxC = 1003;
const int MaxM = 5e5 + 5;
const int PoolSize = MaxN * MaxC + MaxM;
struct ListItem;//声明之后会有一个命名为List的struct
typedef ListItem Li; //给ListItem起了一个别名Li
//在给出其定义之前，只能声明和使用其指针
int c[MaxC];
int Index = 0;

Li *Head[MaxN], *Tail[MaxN];//

struct ListItem {//本行不能用别名
	int Index;
	/*增加更多的数据成员以实现题目要求*/
	/*你必须用指针来实现链表的连接*/
	int value;
	bool exist;
	struct ListItem *prev;
	struct ListItem *next;
	int num;
	
}Pool[PoolSize];//内存池，避免频繁申请内存导致效率降低

struct Lists
{
	ListItem *head;
	ListItem *tail;
};
Lists lists[MaxN];

ListItem *GetNewListItem() {//你必须用这个函数来申请一个新的表项
	//静态变量只会初始化1次，auto表示自动匹配类型，需要C++11及以上。如果你认为有必要可以把该静态局部变量改为全局变量
	//如果你把Index当作一个类/结构体的数据成员，那么删掉auto和static加上int
	++Index;
	Li * NewOne = &Pool[Index];
	NewOne->Index = Index;//这里的编号和池的下标是同步的，可以直接通过Pool[i]来得到第i号表项, &Pool[i] 或 (Pool + i) 表示指向第i号表项的指针
	//如果你认为有必要，可以在这里增加一些初始化代码，也可以增加本函数的参数
	NewOne->value = Index;
	NewOne->exist = true;
	return NewOne;
}
void inserthead(int nid)
{
	Li *node = GetNewListItem();
	node->num = nid;
	if (lists[nid].head == NULL) 
		lists[nid].head = lists[nid].tail = node;
	else 
	{
		int thelast = lists[nid].head->Index;
		Pool[thelast].prev = node;
		node->next = lists[nid].head;
		node->prev = NULL;
		lists[nid].head = node;
	}
}

void inserttail(int nid)
{
	ListItem *node = GetNewListItem();
	node->num = nid;
	if (lists[nid].tail == NULL)
		lists[nid].head = lists[nid].tail = node;
	else 
	{
		int thelast = lists[nid].tail->Index;
		Pool[thelast].next = node;
		node->prev = lists[nid].tail;
		node->next = NULL;
		lists[nid].tail = node;
	}
}

void deleteItem(int id)
{
	if((id > Index) || (id <= 0) || !(Pool[id].exist) ) 
		return;
	else 
	{ 
		Pool[id].exist = false;
		if (Pool[id].next != NULL) Pool[id].next->prev = Pool[id].prev;
		if (Pool[id].prev != NULL) Pool[id].prev->next = Pool[id].next;
		if ((Pool[id].next == NULL) && (Pool[id].prev != NULL)) lists[Pool[id].num].tail = Pool[id].prev;
		if ((Pool[id].prev == NULL) && (Pool[id].next != NULL)) lists[Pool[id].num].head = Pool[id].next;
		if ((Pool[id].prev == NULL) && (Pool[id].next == NULL)) lists[Pool[id].num].tail = lists[Pool[id].num].head =NULL;
		return; 
	}
}

void change(int id, int x)
{
	
	if(!(Pool[id].exist)) return;
	else Pool[id].value = x;
}

void printnode(int id)
{
	if(!(Pool[id].exist)) printf("NULL ");
	else printf("%d ",Pool[id].value);
}

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		for (int j = 1; j <= c[i]; j++){
			inserttail(i);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int opt;
		scanf("%d", &opt);
		int a;
		if(opt == 1)
		{
			scanf("%d", &a); 
			if (!Pool[a].exist) printf("NULL NULL NULL\n");
			else{
			if (Pool[a].prev != NULL) printnode(Pool[a].prev->Index);
			else printf("NULL ");
			printnode(a);
			if (Pool[a].next != NULL) printnode(Pool[a].next->Index);
			else printf("NULL ");
			printf("\n");
			}
		}
		if (opt == 2)
		{
			scanf("%d", &a);
			deleteItem(a);
		}
		if (opt == 3)
		{
			scanf("%d", &a);
			inserthead(a);
		}
		if (opt == 4)
		{
			scanf("%d", &a);
			inserttail(a);
		}
		if (opt == 5)
		{
			int what;
			scanf("%d %d", &a, &what);
			change(a, what);
		}
	}
	return 0;
}
